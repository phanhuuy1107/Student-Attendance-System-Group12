#include "AttendanceController.h"
#include "DatabaseManager.h"
#include "AttendanceSession.h"
#include <QDebug>

AttendanceController::AttendanceController(QObject *parent) : QObject(parent) {
    // Controller initialization
}

// 1. Login Handling Logic

bool AttendanceController::handleLogin(const QString &username, const QString &password) {
    QString role;
    int userId = -1;

    bool isSuccess = DatabaseManager::getInstance().authenticateUser(username, password, role, userId);

    if (isSuccess) {
        emit loginResult(true, role, "Login successful!");
        return true;
    } else {
        emit loginResult(false, "", "Incorrect username or password!");
        return false;
    }
}

// 2. Student Check-in Logic
bool AttendanceController::handleCheckIn(int studentId, const QString &pinCode) {
    if (pinCode.isEmpty()) {
        emit checkInResult(false, "PIN code cannot be empty!");
        return false;
    }

    // TODO: Integrate AttendanceSession validation and Database record insertion here
    
    // Simulate successful check-in
    emit checkInResult(true, "Check-in successful!");
    return true;
}


// 3. Lecturer Create Session Logic
bool AttendanceController::handleCreateSession(int courseId, int duration) {
    qDebug() << "Creating new attendance session for Course ID:" << courseId 
             << "with duration:" << duration << "minutes.";
    
    // TODO: Call DatabaseManager to save this session
    return true;
}
