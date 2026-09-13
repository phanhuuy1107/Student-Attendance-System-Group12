/********************************************************************************
** Form generated from reading UI file 'LoginWindow.ui'
**
** Created by: Qt User Interface Compiler version 6.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINWINDOW_H
#define UI_LOGINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginWindow
{
public:
    QWidget *centralwidget;
    QLineEdit *txtUsername;
    QPushButton *btnLogin;
    QCheckBox *chkRememberMe;
    QLabel *btnForgotPassword;
    QLineEdit *txtPassword;
    QLabel *lblTitle;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *LoginWindow)
    {
        if (LoginWindow->objectName().isEmpty())
            LoginWindow->setObjectName("LoginWindow");
        LoginWindow->resize(800, 600);
        centralwidget = new QWidget(LoginWindow);
        centralwidget->setObjectName("centralwidget");
        txtUsername = new QLineEdit(centralwidget);
        txtUsername->setObjectName("txtUsername");
        txtUsername->setGeometry(QRect(280, 130, 221, 31));
        btnLogin = new QPushButton(centralwidget);
        btnLogin->setObjectName("btnLogin");
        btnLogin->setGeometry(QRect(280, 300, 221, 41));
        QFont font;
        font.setPointSize(11);
        btnLogin->setFont(font);
        btnLogin->setStyleSheet(QString::fromUtf8("background-color: #d9d9d9;\n"
"color: black;\n"
"border: none;"));
        chkRememberMe = new QCheckBox(centralwidget);
        chkRememberMe->setObjectName("chkRememberMe");
        chkRememberMe->setGeometry(QRect(280, 260, 131, 20));
        QFont font1;
        font1.setPointSize(9);
        chkRememberMe->setFont(font1);
        btnForgotPassword = new QLabel(centralwidget);
        btnForgotPassword->setObjectName("btnForgotPassword");
        btnForgotPassword->setGeometry(QRect(320, 360, 141, 31));
        QFont font2;
        font2.setPointSize(10);
        btnForgotPassword->setFont(font2);
        txtPassword = new QLineEdit(centralwidget);
        txtPassword->setObjectName("txtPassword");
        txtPassword->setGeometry(QRect(280, 200, 221, 31));
        lblTitle = new QLabel(centralwidget);
        lblTitle->setObjectName("lblTitle");
        lblTitle->setGeometry(QRect(250, 70, 321, 16));
        QFont font3;
        font3.setPointSize(11);
        font3.setBold(true);
        lblTitle->setFont(font3);
        LoginWindow->setCentralWidget(centralwidget);
        txtPassword->raise();
        txtUsername->raise();
        btnLogin->raise();
        chkRememberMe->raise();
        btnForgotPassword->raise();
        lblTitle->raise();
        menubar = new QMenuBar(LoginWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 26));
        LoginWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(LoginWindow);
        statusbar->setObjectName("statusbar");
        LoginWindow->setStatusBar(statusbar);

        retranslateUi(LoginWindow);

        QMetaObject::connectSlotsByName(LoginWindow);
    } // setupUi

    void retranslateUi(QMainWindow *LoginWindow)
    {
        LoginWindow->setWindowTitle(QCoreApplication::translate("LoginWindow", "MainWindow", nullptr));
        txtUsername->setText(QString());
        txtUsername->setPlaceholderText(QCoreApplication::translate("LoginWindow", "Email / Student ID", nullptr));
        btnLogin->setText(QCoreApplication::translate("LoginWindow", "LOG IN", nullptr));
        chkRememberMe->setText(QCoreApplication::translate("LoginWindow", "Remember me", nullptr));
        btnForgotPassword->setText(QCoreApplication::translate("LoginWindow", "Forgot Password?", nullptr));
        txtPassword->setText(QString());
        txtPassword->setPlaceholderText(QCoreApplication::translate("LoginWindow", "Password", nullptr));
        lblTitle->setText(QCoreApplication::translate("LoginWindow", "STUDENT ATTENDANCE SYSTEM", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginWindow: public Ui_LoginWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINWINDOW_H
