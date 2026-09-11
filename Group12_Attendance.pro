QT       += core gui sql
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Group12_Attendance
TEMPLATE = app

INCLUDEPATH += src/Model \
               src/View \
               src/Controller
SOURCES += \
    src/main.cpp \
    src/View/MainWindow.cpp \
    src/Model/AttendanceRecord.cpp \
    src/Model/AttendanceSession.cpp \
    src/Model/Course.cpp \
    src/Model/LeaveRequest.cpp \
    src/Model/User.cpp

HEADERS += \
    src/View/MainWindow.h \
    src/Model/AttendanceRecord.h \
    src/Model/AttendanceSession.h \
    src/Model/Course.h \
    src/Model/LeaveRequest.h \
    src/Model/User.h \
    src/Model/DatabaseManager.h

FORMS += \
    src/View/LoginWindow.ui \
    src/View/StudentCheckIn.ui \
    src/View/LecturerDashboard.ui \
    src/View/AttendanceReport.ui

DESTDIR = ./bin
