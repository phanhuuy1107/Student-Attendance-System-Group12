QT       += core gui sql
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Group12_Attendance
TEMPLATE = app

INCLUDEPATH += src/Model \
               src/View \
               src/Controller

SOURCES += \
    src/main.cpp \
    src/Controller/AttendanceController.cpp \
    src/Model/AttendanceRecord.cpp \
    src/Model/AttendanceSession.cpp \
    src/Model/Course.cpp \
    src/Model/DatabaseManager.cpp \
    src/Model/LeaveRequest.cpp \
    src/Model/User.cpp

HEADERS += \
    src/Controller/AttendanceController.h \
    src/Model/AttendanceRecord.h \
    src/Model/AttendanceSession.h \
    src/Model/Course.h \
    src/Model/DatabaseManager.h \
    src/Model/LeaveRequest.h \
    src/Model/User.h

FORMS += \
    src/View/AttendanceReport.ui \
    src/View/LecturerDashboard.ui \
    src/View/LoginWindow.ui \
    src/View/StudentCheckIn.ui

DESTDIR = ./bin