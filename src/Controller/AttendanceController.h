#ifndef ATTENDANCECONTROLLER_H
#define ATTENDANCECONTROLLER_H

#include <QObject>
#include <QMessageBox>
#include <QWidget>
#include <QMainWindow>

// Gọi trực tiếp các file ẨN được Qt tự động sinh ra từ bản vẽ của Trâm
#include "ui_LoginWindow.h"
#include "ui_LecturerDashboard.h"
#include "ui_StudentCheckIn.h"
#include "ui_AttendanceReport.h"

// Gọi các Model và DB
#include "User.h"
#include "AttendanceSession.h"
#include "DatabaseManager.h"

class AttendanceController : public QObject {
    Q_OBJECT

public:
    explicit AttendanceController(QObject *parent = nullptr);
    ~AttendanceController();
    void start();

private slots:
    void handleLogin();
    void handleCreateSession();
    void handleStudentCheckIn();
    void handleBackToLogin();
    void handleViewReport();

private:
    // 1. Tạo các khung cửa sổ rỗng (Containers)
    QMainWindow *loginWidget;
    QMainWindow *lecturerWidget;
    QMainWindow *studentWidget;
    QMainWindow *reportWidget;
    //2 khai báo các class UI
    Ui::LoginWindow loginUi;
    Ui::LecturerDashboard lecturerUi;
    Ui::StudentCheckIn studentUi;
    Ui::AttendanceReport reportUi;

    DatabaseManager& dbManager;
    User *currentUser;
    AttendanceSession *currentSession;

    QTimer *countdownTimer = nullptr;
    int remainingSeconds = 0;
};

#endif // ATTENDANCECONTROLLER_H