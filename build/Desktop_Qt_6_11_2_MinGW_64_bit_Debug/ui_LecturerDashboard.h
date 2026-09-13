/********************************************************************************
** Form generated from reading UI file 'LecturerDashboard.ui'
**
** Created by: Qt User Interface Compiler version 6.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LECTURERDASHBOARD_H
#define UI_LECTURERDASHBOARD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LecturerDashboard
{
public:
    QWidget *centralwidget;
    QLabel *lblHeader;
    QLabel *label;
    QLabel *cmbClass;
    QLabel *spnDuration;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *lblPin;
    QLabel *lblTimer;
    QLabel *lblQRCode;
    QPushButton *btnCreateSession;
    QPushButton *btnLogout;
    QPushButton *btnViewReport;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *LecturerDashboard)
    {
        if (LecturerDashboard->objectName().isEmpty())
            LecturerDashboard->setObjectName("LecturerDashboard");
        LecturerDashboard->resize(800, 600);
        centralwidget = new QWidget(LecturerDashboard);
        centralwidget->setObjectName("centralwidget");
        lblHeader = new QLabel(centralwidget);
        lblHeader->setObjectName("lblHeader");
        lblHeader->setGeometry(QRect(30, 30, 191, 16));
        QFont font;
        font.setPointSize(9);
        lblHeader->setFont(font);
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(210, 30, 231, 16));
        label->setFont(font);
        cmbClass = new QLabel(centralwidget);
        cmbClass->setObjectName("cmbClass");
        cmbClass->setGeometry(QRect(30, 80, 281, 21));
        cmbClass->setFont(font);
        spnDuration = new QLabel(centralwidget);
        spnDuration->setObjectName("spnDuration");
        spnDuration->setGeometry(QRect(30, 120, 171, 16));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(30, 190, 161, 16));
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(80, 440, 71, 16));
        lblPin = new QLabel(centralwidget);
        lblPin->setObjectName("lblPin");
        lblPin->setGeometry(QRect(290, 250, 121, 16));
        lblPin->setFont(font);
        lblTimer = new QLabel(centralwidget);
        lblTimer->setObjectName("lblTimer");
        lblTimer->setGeometry(QRect(290, 300, 201, 16));
        lblTimer->setFont(font);
        lblQRCode = new QLabel(centralwidget);
        lblQRCode->setObjectName("lblQRCode");
        lblQRCode->setGeometry(QRect(30, 240, 211, 191));
        lblQRCode->setStyleSheet(QString::fromUtf8("border: 1.5px dashed #555555;\n"
"background-color: white;\n"
"color: black;"));
        btnCreateSession = new QPushButton(centralwidget);
        btnCreateSession->setObjectName("btnCreateSession");
        btnCreateSession->setGeometry(QRect(40, 150, 111, 31));
        btnLogout = new QPushButton(centralwidget);
        btnLogout->setObjectName("btnLogout");
        btnLogout->setGeometry(QRect(550, 490, 101, 31));
        btnViewReport = new QPushButton(centralwidget);
        btnViewReport->setObjectName("btnViewReport");
        btnViewReport->setGeometry(QRect(310, 370, 111, 31));
        LecturerDashboard->setCentralWidget(centralwidget);
        menubar = new QMenuBar(LecturerDashboard);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 26));
        LecturerDashboard->setMenuBar(menubar);
        statusbar = new QStatusBar(LecturerDashboard);
        statusbar->setObjectName("statusbar");
        LecturerDashboard->setStatusBar(statusbar);

        retranslateUi(LecturerDashboard);

        QMetaObject::connectSlotsByName(LecturerDashboard);
    } // setupUi

    void retranslateUi(QMainWindow *LecturerDashboard)
    {
        LecturerDashboard->setWindowTitle(QCoreApplication::translate("LecturerDashboard", "MainWindow", nullptr));
        lblHeader->setText(QCoreApplication::translate("LecturerDashboard", "LECTURER DASHBOARD", nullptr));
        label->setText(QCoreApplication::translate("LecturerDashboard", "> Create Attendance Session", nullptr));
        cmbClass->setText(QCoreApplication::translate("LecturerDashboard", "Select Class: SE101 - Software Engineering", nullptr));
        spnDuration->setText(QCoreApplication::translate("LecturerDashboard", "Duration: [ 15 ] minutes", nullptr));
        label_6->setText(QCoreApplication::translate("LecturerDashboard", " SESSION ACTIVE", nullptr));
        label_7->setText(QString());
        lblPin->setText(QCoreApplication::translate("LecturerDashboard", " Pin: 849201", nullptr));
        lblTimer->setText(QCoreApplication::translate("LecturerDashboard", "Countdown Timer: 14:59", nullptr));
        lblQRCode->setText(QCoreApplication::translate("LecturerDashboard", "                  QR CODE", nullptr));
        btnCreateSession->setText(QCoreApplication::translate("LecturerDashboard", "Create Session", nullptr));
        btnLogout->setText(QCoreApplication::translate("LecturerDashboard", "Log Out", nullptr));
        btnViewReport->setText(QCoreApplication::translate("LecturerDashboard", "View Reports", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LecturerDashboard: public Ui_LecturerDashboard {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LECTURERDASHBOARD_H
