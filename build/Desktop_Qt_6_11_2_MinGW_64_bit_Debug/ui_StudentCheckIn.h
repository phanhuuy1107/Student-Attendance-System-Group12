/********************************************************************************
** Form generated from reading UI file 'StudentCheckIn.ui'
**
** Created by: Qt User Interface Compiler version 6.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STUDENTCHECKIN_H
#define UI_STUDENTCHECKIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StudentCheckIn
{
public:
    QWidget *centralwidget;
    QPushButton *btnBack;
    QLabel *lblInstruction;
    QPushButton *btnScanQR;
    QPushButton *btnEnterPin;
    QLabel *label_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *StudentCheckIn)
    {
        if (StudentCheckIn->objectName().isEmpty())
            StudentCheckIn->setObjectName("StudentCheckIn");
        StudentCheckIn->resize(360, 640);
        StudentCheckIn->setStyleSheet(QString::fromUtf8(""));
        centralwidget = new QWidget(StudentCheckIn);
        centralwidget->setObjectName("centralwidget");
        btnBack = new QPushButton(centralwidget);
        btnBack->setObjectName("btnBack");
        btnBack->setGeometry(QRect(100, 50, 151, 31));
        QFont font;
        font.setPointSize(9);
        btnBack->setFont(font);
        btnBack->setStyleSheet(QString::fromUtf8("border: 1px solid #777777; background-color: white;"));
        lblInstruction = new QLabel(centralwidget);
        lblInstruction->setObjectName("lblInstruction");
        lblInstruction->setGeometry(QRect(100, 120, 161, 16));
        lblInstruction->setFont(font);
        btnScanQR = new QPushButton(centralwidget);
        btnScanQR->setObjectName("btnScanQR");
        btnScanQR->setGeometry(QRect(100, 190, 151, 41));
        btnScanQR->setFont(font);
        btnScanQR->setStyleSheet(QString::fromUtf8("background-color: #d9d9d9;\n"
"border: none;\n"
"padding: 12px;"));
        btnEnterPin = new QPushButton(centralwidget);
        btnEnterPin->setObjectName("btnEnterPin");
        btnEnterPin->setGeometry(QRect(100, 310, 151, 41));
        btnEnterPin->setFont(font);
        btnEnterPin->setStyleSheet(QString::fromUtf8("background-color: #d9d9d9;\n"
"border: none;\n"
"padding: 12px;"));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(160, 260, 55, 16));
        label_2->setFont(font);
        StudentCheckIn->setCentralWidget(centralwidget);
        menubar = new QMenuBar(StudentCheckIn);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 360, 26));
        StudentCheckIn->setMenuBar(menubar);
        statusbar = new QStatusBar(StudentCheckIn);
        statusbar->setObjectName("statusbar");
        StudentCheckIn->setStatusBar(statusbar);

        retranslateUi(StudentCheckIn);

        QMetaObject::connectSlotsByName(StudentCheckIn);
    } // setupUi

    void retranslateUi(QMainWindow *StudentCheckIn)
    {
        StudentCheckIn->setWindowTitle(QCoreApplication::translate("StudentCheckIn", "MainWindow", nullptr));
        btnBack->setText(QCoreApplication::translate("StudentCheckIn", "\342\206\220     CHECK-IN", nullptr));
        lblInstruction->setText(QCoreApplication::translate("StudentCheckIn", "Select check-in method", nullptr));
        btnScanQR->setText(QCoreApplication::translate("StudentCheckIn", "SCAN QR CODE.", nullptr));
        btnEnterPin->setText(QCoreApplication::translate("StudentCheckIn", "ENTER PIN", nullptr));
        label_2->setText(QCoreApplication::translate("StudentCheckIn", "OR", nullptr));
    } // retranslateUi

};

namespace Ui {
    class StudentCheckIn: public Ui_StudentCheckIn {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STUDENTCHECKIN_H
