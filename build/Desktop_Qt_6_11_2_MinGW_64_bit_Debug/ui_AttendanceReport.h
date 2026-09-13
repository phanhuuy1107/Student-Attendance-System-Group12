/********************************************************************************
** Form generated from reading UI file 'AttendanceReport.ui'
**
** Created by: Qt User Interface Compiler version 6.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ATTENDANCEREPORT_H
#define UI_ATTENDANCEREPORT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AttendanceReport
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QLabel *lblCourseInfo;
    QLineEdit *txtSearch;
    QTableWidget *tblAttendanceReport;
    QPushButton *btnExport;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *AttendanceReport)
    {
        if (AttendanceReport->objectName().isEmpty())
            AttendanceReport->setObjectName("AttendanceReport");
        AttendanceReport->resize(939, 600);
        centralwidget = new QWidget(AttendanceReport);
        centralwidget->setObjectName("centralwidget");
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(70, 10, 241, 31));
        QFont font;
        font.setPointSize(13);
        label->setFont(font);
        lblCourseInfo = new QLabel(centralwidget);
        lblCourseInfo->setObjectName("lblCourseInfo");
        lblCourseInfo->setGeometry(QRect(70, 70, 401, 20));
        QFont font1;
        font1.setPointSize(9);
        lblCourseInfo->setFont(font1);
        txtSearch = new QLineEdit(centralwidget);
        txtSearch->setObjectName("txtSearch");
        txtSearch->setGeometry(QRect(70, 120, 241, 22));
        txtSearch->setFont(font1);
        tblAttendanceReport = new QTableWidget(centralwidget);
        if (tblAttendanceReport->columnCount() < 7)
            tblAttendanceReport->setColumnCount(7);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tblAttendanceReport->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tblAttendanceReport->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tblAttendanceReport->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tblAttendanceReport->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tblAttendanceReport->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tblAttendanceReport->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tblAttendanceReport->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        tblAttendanceReport->setObjectName("tblAttendanceReport");
        tblAttendanceReport->setGeometry(QRect(30, 230, 881, 231));
        btnExport = new QPushButton(centralwidget);
        btnExport->setObjectName("btnExport");
        btnExport->setGeometry(QRect(740, 490, 111, 28));
        btnExport->setFont(font1);
        AttendanceReport->setCentralWidget(centralwidget);
        menubar = new QMenuBar(AttendanceReport);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 939, 26));
        AttendanceReport->setMenuBar(menubar);
        statusbar = new QStatusBar(AttendanceReport);
        statusbar->setObjectName("statusbar");
        AttendanceReport->setStatusBar(statusbar);

        retranslateUi(AttendanceReport);

        QMetaObject::connectSlotsByName(AttendanceReport);
    } // setupUi

    void retranslateUi(QMainWindow *AttendanceReport)
    {
        AttendanceReport->setWindowTitle(QCoreApplication::translate("AttendanceReport", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("AttendanceReport", "Attendance Report", nullptr));
        lblCourseInfo->setText(QCoreApplication::translate("AttendanceReport", "Course: SE101 - Software Engineering | Date: Aug 22, 2026", nullptr));
        txtSearch->setText(QString());
        txtSearch->setPlaceholderText(QCoreApplication::translate("AttendanceReport", "Search by Student ID or Name...", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tblAttendanceReport->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("AttendanceReport", "Student ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tblAttendanceReport->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("AttendanceReport", "Full Name", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tblAttendanceReport->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("AttendanceReport", "Check-in Time", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tblAttendanceReport->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("AttendanceReport", "Status", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tblAttendanceReport->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("AttendanceReport", "Present", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tblAttendanceReport->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("AttendanceReport", "Absent", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tblAttendanceReport->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("AttendanceReport", "Rate", nullptr));
        btnExport->setText(QCoreApplication::translate("AttendanceReport", "Export Excel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AttendanceReport: public Ui_AttendanceReport {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ATTENDANCEREPORT_H
