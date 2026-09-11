QT += core testlib
CONFIG += c++17 testcase
SOURCES += \
    tst_AttendanceSystem.cpp \
    User.cpp \
    Course.cpp \
    AttendanceSession.cpp \
    AttendanceRecord.cpp \
    LeaveRequest.cpp
HEADERS += \
    User.h \
    Course.h \
    AttendanceSession.h \
    AttendanceRecord.h \
    LeaveRequest.h