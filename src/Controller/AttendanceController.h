#ifndef ATTENDANCECONTROLLER_H
#define ATTENDANCECONTROLLER_H

#include <QObject>
#include <QString>

class AttendanceController : public QObject {
    Q_OBJECT
public:
    explicit AttendanceController(QObject *parent = nullptr);

    // Xu ly cac luong nghiep vu chinh
    bool handleLogin(const QString &username, const QString &password);
    bool handleCheckIn(int studentId, const QString &pinCode);
    bool handleCreateSession(int courseId, int duration);

signals:
    void loginResult(bool success, const QString &role, const QString &message);
    void checkInResult(bool success, const QString &message);
};

#endif // ATTENDANCECONTROLLER_H