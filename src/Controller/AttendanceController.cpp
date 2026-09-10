#include "AttendanceController.h"
#include "DatabaseManager.h"
#include "AttendanceSession.h"
#include <QDebug>

AttendanceController::AttendanceController(QObject *parent) : QObject(parent) {
   
}


bool AttendanceController::handleLogin(const QString &username, const QString &password) {
    QString role;
    int userId = -1;

    
    bool isSuccess = DatabaseManager::getInstance().authenticateUser(username, password, role, userId);

    if (isSuccess) {
        
        emit loginResult(true, role, "Ðang nh?p thành công!");
        return true;
    } else {
       
        emit loginResult(false, "", "Tài kho?n ho?c m?t kh?u không chính xác!");
        return false;
    }
}

bool AttendanceController::handleCheckIn(int studentId, const QString &pinCode) {
    if (pinCode.isEmpty()) {
        emit checkInResult(false, "Mã PIN không du?c d? tr?ng!");
        return false;
    }


    emit checkInResult(true, "Ði?m danh thành công!");
    return true;
}


bool AttendanceController::handleCreateSession(int courseId, int duration) {

    qDebug() << "Ðang t?o phiên di?m danh m?i cho Course ID:" << courseId << "v?i th?i lu?ng:" << duration << "phút.";

    return true;
}
