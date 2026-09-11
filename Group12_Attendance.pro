QT       += core gui sql
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Group12_Attendance
TEMPLATE = app

INCLUDEPATH += src/Model \
               src/View \
               src/Controller

SOURCES += src/main.cpp
HEADERS +=
FORMS +=
src/View/LoginWindow.ui \
    src/View/StudentCheckIn.ui \
    src/View/LecturerDashboard.ui \
    src/View/AttendanceReport.ui
DESTDIR = ./bin
