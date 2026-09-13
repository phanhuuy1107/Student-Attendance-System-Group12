#include "AttendanceController.h"
#include <QMessageBox>
#include <QInputDialog>
#include <QDateTime>
#include <QTimer>
#include <QTableWidget>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlTableModel>
#include <QPixmap>
#include <QPainter>
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QDialog>
#include <QVBoxLayout>
#include <QHeaderView>
#include <QFormLayout>
#include <QComboBox>
#include <QDateEdit>
#include <QLineEdit>
#include <QFileInfo>

AttendanceController::AttendanceController(QObject *parent)
    : QObject(parent),
    dbManager(DatabaseManager::getInstance()),
    currentUser(nullptr),
    currentSession(nullptr)
{
    // Cấp phát bộ nhớ cho các khung cửa sổ
    loginWidget = new QMainWindow();
    lecturerWidget = new QMainWindow();
    studentWidget = new QMainWindow();
    reportWidget = new QMainWindow();

    loginUi.setupUi(loginWidget);
    lecturerUi.setupUi(lecturerWidget);
    studentUi.setupUi(studentWidget);
    reportUi.setupUi(reportWidget);

    // Móc nối Giao diện -> Logic
    connect(loginUi.btnLogin, SIGNAL(clicked()), this, SLOT(handleLogin()));
    connect(lecturerUi.btnCreateSession, SIGNAL(clicked()), this, SLOT(handleCreateSession()));
    connect(studentUi.btnEnterPin, SIGNAL(clicked()), this, SLOT(handleStudentCheckIn()));
    connect(studentUi.btnScanQR, &QPushButton::clicked, [=]() {
        QMessageBox::information(studentWidget, "QR Scan", "Camera scanner simulation: Please use PIN code for testing!");
    });
    connect(lecturerUi.btnLogout, &QPushButton::clicked, [=]() {
        lecturerWidget->hide();
        loginWidget->show();
    });
    connect(studentUi.btnBack, SIGNAL(clicked()), this, SLOT(handleBackToLogin()));
    connect(lecturerUi.btnViewReport, SIGNAL(clicked()), this, SLOT(handleViewReport()));

    // Khởi tạo bộ đếm thời gian thực
    countdownTimer = new QTimer(this);
    connect(countdownTimer, &QTimer::timeout, [=]() {
        if (remainingSeconds > 0) {
            remainingSeconds--;
            int minutes = remainingSeconds / 60;
            int seconds = remainingSeconds % 60;

            lecturerUi.lblTimer->setText(QString("Countdown: %1:%2")
                                             .arg(minutes, 2, 10, QChar('0'))
                                             .arg(seconds, 2, 10, QChar('0')));
        } else {
            countdownTimer->stop();
            lecturerUi.lblTimer->setText("Countdown: 00:00 (Expired)");
        }
    });
}

AttendanceController::~AttendanceController() {
    delete loginWidget;
    delete lecturerWidget;
    delete studentWidget;
    delete reportWidget;
    if (currentUser) delete currentUser;
    if (currentSession) delete currentSession;
}

void AttendanceController::start() {
    dbManager.initTables();
    loginWidget->show();
}

void AttendanceController::handleLogin() {
    QString username = loginUi.txtUsername->text();
    QString rawPassword = loginUi.txtPassword->text();

    QString hashedPassword = User::hashPassword(rawPassword);
    QString role;

    if (dbManager.checkLogin(username, hashedPassword, role)) {
        QMessageBox::information(loginWidget, "Success", "Login successful as " + role + "!");
        loginWidget->hide();

        if (role == "Lecturer") {
            lecturerWidget->show();
        } else if (role == "Student") {
            studentWidget->show();
        }
    } else {
        QMessageBox::warning(loginWidget, "Error", "Invalid credentials!");
    }
}

void AttendanceController::handleCreateSession() {
    QString durationStr = lecturerUi.spnDuration->text();
    int durationMinutes = durationStr.toInt();
    if (durationMinutes <= 0) durationMinutes = 15;

    if (currentSession) delete currentSession;
    currentSession = new AttendanceSession(durationMinutes);

    QString newPin = currentSession->getPIN();
    QString qrCodeData = currentSession->getQRCode();

    lecturerUi.lblPin->setText("Pin: " + newPin);

    // Thuật toán vẽ mô phỏng QR Code
    if (lecturerUi.lblQRCode) {
        int size = 200;
        QPixmap qrPixmap(size, size);
        qrPixmap.fill(Qt::white);
        QPainter painter(&qrPixmap);
        painter.setPen(Qt::NoPen);

        int gridSize = 21;
        int rectSize = size / gridSize;
        int charIndex = 0;

        painter.setBrush(Qt::black);
        for (int y = 0; y < gridSize; ++y) {
            for (int x = 0; x < gridSize; ++x) {
                if (charIndex < qrCodeData.length()) {
                    if ((qrCodeData[charIndex].toLatin1() ^ (x * y)) % 2 == 0) {
                        painter.drawRect(x * rectSize, y * rectSize, rectSize, rectSize);
                    }
                    charIndex = (charIndex + 1) % qrCodeData.length();
                }
            }
        }

        auto drawLocator = [&](int px, int py) {
            painter.setBrush(Qt::black);
            painter.drawRect(px * rectSize, py * rectSize, 7 * rectSize, 7 * rectSize);
            painter.setBrush(Qt::white);
            painter.drawRect((px + 1) * rectSize, (py + 1) * rectSize, 5 * rectSize, 5 * rectSize);
            painter.setBrush(Qt::black);
            painter.drawRect((px + 2) * rectSize, (py + 2) * rectSize, 3 * rectSize, 3 * rectSize);
        };

        drawLocator(0, 0);
        drawLocator(gridSize - 7, 0);
        drawLocator(0, gridSize - 7);

        painter.end();

        lecturerUi.lblQRCode->setPixmap(qrPixmap);
        lecturerUi.lblQRCode->setScaledContents(true);
    }

    remainingSeconds = durationMinutes * 60;
    if (!countdownTimer->isActive()) {
        countdownTimer->start(1000);
    }

    QMessageBox::information(lecturerWidget, "Session Created", "Session is active! PIN: " + newPin);
}

void AttendanceController::handleStudentCheckIn() {
    if (loginUi.txtUsername->text() == "teacher") {
        QMessageBox::warning(studentWidget, "Access Denied", "Giảng viên không thể tham gia điểm danh!");
        return;
    }

    if (!currentSession || currentSession->isExpired()) {
        QMessageBox::warning(studentWidget, "Error", "No active session or session has expired!");
        return;
    }

    bool ok;
    QString inputCode = QInputDialog::getText(studentWidget, "Student Check-In",
                                              "Enter PIN code:", QLineEdit::Normal, "", &ok);

    if (ok && !inputCode.isEmpty()) {
        inputCode = inputCode.trimmed();

        if (currentSession->isValidCode(inputCode)) {
            if (currentSession->recordStudent(1)) {
                QString checkInTime = QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss");
                QString currentUsername = loginUi.txtUsername->text();

                QSqlQuery findIdQuery;
                findIdQuery.prepare("SELECT id FROM Account WHERE username = ?");
                findIdQuery.addBindValue(currentUsername);

                int accId = 1;
                if (findIdQuery.exec() && findIdQuery.next()) {
                    accId = findIdQuery.value(0).toInt();
                }

                if (dbManager.addReport(accId, "Present", checkInTime)) {
                    QMessageBox::information(studentWidget, "Success", "Attendance recorded successfully!");

                    // --- BẬT POPUP LỊCH SỬ & XIN NGHỈ PHÉP (CODE-ONLY UI) ---
                    QDialog *historyDialog = new QDialog(studentWidget);
                    historyDialog->setWindowTitle("My Attendance & Leave Portal");
                    historyDialog->resize(500, 350);

                    QVBoxLayout *layout = new QVBoxLayout(historyDialog);

                    // 1. Bảng lịch sử điểm danh
                    QLabel *lblTitle = new QLabel("<b>Recent Attendance History</b>");
                    layout->addWidget(lblTitle);

                    QTableWidget *histTable = new QTableWidget();
                    histTable->setColumnCount(3);
                    histTable->setHorizontalHeaderLabels({"Course", "Check-in Time", "Status"});
                    histTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
                    histTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

                    QSqlQuery q;
                    q.prepare("SELECT 'SE101 - Software Engineering', r.check_in_time, r.status "
                              "FROM Report r JOIN Account a ON r.account_id = a.id "
                              "WHERE a.username = :username ORDER BY r.check_in_time DESC");
                    q.bindValue(":username", currentUsername);
                    q.exec();

                    int r = 0;
                    while(q.next()) {
                        histTable->insertRow(r);
                        histTable->setItem(r, 0, new QTableWidgetItem(q.value(0).toString()));
                        histTable->setItem(r, 1, new QTableWidgetItem(q.value(1).toString()));

                        QTableWidgetItem *statusItem = new QTableWidgetItem(q.value(2).toString());
                        if (q.value(2).toString() == "Present") statusItem->setForeground(Qt::darkGreen);
                        histTable->setItem(r, 2, statusItem);
                        r++;
                    }
                    layout->addWidget(histTable);

                    // 2. Nút Submit Leave Request (FR10)
                    QPushButton *btnLeaveRequest = new QPushButton("Submit Leave Request");
                    btnLeaveRequest->setStyleSheet("QPushButton { background-color: #f0ad4e; color: white; font-weight: bold; padding: 8px; }");
                    layout->addWidget(btnLeaveRequest);

                    // 3. Xử lý sự kiện khi bấm nút Xin nghỉ phép
                    connect(btnLeaveRequest, &QPushButton::clicked, [=]() {
                        QDialog *leaveDialog = new QDialog(historyDialog);
                        leaveDialog->setWindowTitle("Leave Request Form");
                        leaveDialog->resize(350, 200);

                        QFormLayout *form = new QFormLayout(leaveDialog);

                        QComboBox *cbCourse = new QComboBox();
                        cbCourse->addItem("SE101 - Software Engineering");

                        QDateEdit *dateEdit = new QDateEdit(QDate::currentDate());
                        dateEdit->setCalendarPopup(true);

                        QLineEdit *txtReason = new QLineEdit();
                        txtReason->setPlaceholderText("Enter medical or personal reason...");

                        QPushButton *btnAttach = new QPushButton("Attach Proof...");
                        QLabel *lblFile = new QLabel("No file selected");

                        QHBoxLayout *fileLayout = new QHBoxLayout();
                        fileLayout->addWidget(btnAttach);
                        fileLayout->addWidget(lblFile);

                        // Xử lý đính kèm file
                        connect(btnAttach, &QPushButton::clicked, [=]() mutable {
                            QString selectedFile = QFileDialog::getOpenFileName(leaveDialog,
                                                                                "Select Medical Proof",
                                                                                "",
                                                                                "Images/PDF (*.png *.jpg *.pdf)");
                            if (!selectedFile.isEmpty()) {
                                QFileInfo fi(selectedFile);
                                lblFile->setText(fi.fileName());
                            }
                        });

                        QPushButton *btnSubmit = new QPushButton("Submit Request");
                        btnSubmit->setStyleSheet("QPushButton { background-color: #5cb85c; color: white; font-weight: bold; }");

                        form->addRow("Course:", cbCourse);
                        form->addRow("Date:", dateEdit);
                        form->addRow("Reason:", txtReason);
                        form->addRow("Proof Attachment:", fileLayout);
                        form->addWidget(btnSubmit);

                        // Xử lý gửi đơn
                        connect(btnSubmit, &QPushButton::clicked, [=]() {
                            if (txtReason->text().isEmpty()) {
                                QMessageBox::warning(leaveDialog, "Error", "Please enter a reason for your absence!");
                                return;
                            }
                            // Báo cáo thành công (Lúc này có thể mở rộng insert vào DB sau)
                            QMessageBox::information(leaveDialog, "Success", "Leave request submitted successfully!\nStatus: Pending Lecturer Review");
                            leaveDialog->accept();
                        });

                        leaveDialog->exec();
                    });

                    historyDialog->exec();
                    // ----------------------------------------------------

                } else {
                    QMessageBox::warning(studentWidget, "Database Warning", "Lỗi lưu điểm danh (Khóa ngoại không hợp lệ)!");
                }
            } else {
                QMessageBox::warning(studentWidget, "Warning", "You have already checked in!");
            }
        } else {
            QMessageBox::warning(studentWidget, "Error", "Invalid PIN code!");
        }
    }
}
void AttendanceController::handleBackToLogin() {
    studentWidget->hide();
    loginWidget->show();
}

void AttendanceController::handleViewReport() {
    reportWidget->show();

    QTableWidget *table = nullptr;
    QList<QTableWidget*> allTables = reportWidget->findChildren<QTableWidget*>();
    if (!allTables.isEmpty()) {
        table = allTables.first();
    }

    if (table) {
        table->blockSignals(true);
        table->setRowCount(0);

        QSqlQuery query("SELECT r.report_id, a.username, r.check_in_time, r.status "
                        "FROM Report r JOIN Account a ON r.account_id = a.id");
        int row = 0;

        while (query.next()) {
            table->insertRow(row);

            QString username = query.value(1).toString();
            QString checkInTime = query.value(2).toString();
            QString status = query.value(3).toString();

            QTableWidgetItem *idItem = new QTableWidgetItem(username);
            idItem->setFlags(idItem->flags() & ~Qt::ItemIsEditable);

            QTableWidgetItem *nameItem = new QTableWidgetItem("Student Demo");
            nameItem->setFlags(nameItem->flags() & ~Qt::ItemIsEditable);

            QTableWidgetItem *timeItem = new QTableWidgetItem(checkInTime);
            timeItem->setFlags(timeItem->flags() & ~Qt::ItemIsEditable);

            QTableWidgetItem *statusItem = new QTableWidgetItem(status);
            statusItem->setBackground(QColor("#f0f8ff"));

            table->setItem(row, 0, idItem);
            table->setItem(row, 1, nameItem);
            table->setItem(row, 2, timeItem);
            table->setItem(row, 3, statusItem);

            QTableWidgetItem *presentItem = new QTableWidgetItem("--");
            presentItem->setFlags(presentItem->flags() & ~Qt::ItemIsEditable);
            table->setItem(row, 4, presentItem);

            row++;
        }

        table->disconnect(SIGNAL(cellChanged(int,int)));

        connect(table, &QTableWidget::cellChanged, this, [=](int r, int c) {
            if (c == 3) {
                QString studentUsername = table->item(r, 0)->text();
                QString newStatus = table->item(r, 3)->text();

                QSqlQuery updateQuery;
                updateQuery.prepare("UPDATE Report SET status = :status WHERE account_id = (SELECT id FROM Account WHERE username = :username)");
                updateQuery.bindValue(":status", newStatus);
                updateQuery.bindValue(":username", studentUsername);

                if(updateQuery.exec()) {
                    table->blockSignals(true);
                    table->item(r, 3)->setForeground(Qt::darkGreen);
                    table->blockSignals(false);
                }
            }
        });

        table->blockSignals(false);
    } else {
        QMessageBox::warning(reportWidget, "Lỗi UI", "Không tìm thấy bảng hiển thị trên giao diện!");
    }

    // TÌM VÀ KÍCH HOẠT NÚT EXPORT EXCEL (Bản chuẩn, quét chữ trên nút)
    QPushButton *excelBtn = nullptr;
    QList<QPushButton*> allButtons = reportWidget->findChildren<QPushButton*>();
    for (QPushButton *btn : allButtons) {
        if (btn->text().contains("Export Excel", Qt::CaseInsensitive)) {
            excelBtn = btn;
            break;
        }
    }

    if (excelBtn) {
        excelBtn->disconnect();

        connect(excelBtn, &QPushButton::clicked, this, [=]() {
            QString fileName = QFileDialog::getSaveFileName(reportWidget,
                                                            "Export Attendance Report",
                                                            "Attendance_Report.csv",
                                                            "CSV Files (*.csv);;All Files (*)");
            if (fileName.isEmpty()) return;

            QFile file(fileName);
            if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
                QMessageBox::warning(reportWidget, "Error", "Không thể tạo file báo cáo!");
                return;
            }

            QTextStream out(&file);
            out.setEncoding(QStringConverter::Utf8);
            out << "\xEF\xBB\xBF"; // Dấu BOM giúp Excel đọc chuẩn tiếng Việt
            out << "Student ID,Full Name,Check-in Time,Status\n";

            if (table) {
                for (int r = 0; r < table->rowCount(); ++r) {
                    QString id = table->item(r, 0) ? table->item(r, 0)->text() : "";
                    QString name = table->item(r, 1) ? table->item(r, 1)->text() : "";
                    QString time = table->item(r, 2) ? table->item(r, 2)->text() : "";
                    QString status = table->item(r, 3) ? table->item(r, 3)->text() : "";

                    id.replace(",", " ");
                    name.replace(",", " ");
                    time.replace(",", " ");
                    status.replace(",", " ");

                    out << id << "," << name << "," << time << "," << status << "\n";
                }
            }

            file.close();
            QMessageBox::information(reportWidget, "Success", "Xuất file báo cáo thành công!");
        });
    }

    // Tự động set ngày tháng hiện tại
    QLabel *lblInfo = reportWidget->findChild<QLabel*>("lblCourseInfo");
    if (lblInfo) {
        QString currentDate = QDateTime::currentDateTime().toString("MMM dd, yyyy");
        lblInfo->setText("Course: SE101 - Software Engineering | Date: " + currentDate);
    }
}