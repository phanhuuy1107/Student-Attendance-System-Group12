#ifndef ATTENDANCESESSION_H
#define ATTENDANCESESSION_H

#include <QString>
#include <QDateTime>

class AttendanceSession {
private:
    int sessionId;
    int courseId;
    QString qrCodeData;
    QString pinCode;
    QDateTime startTime;
    int durationMinutes;
    bool isActive;

public:
    AttendanceSession(int sId, int cId, int duration);

    // FR3 & FR8: Sinh va xac thuc ma QR/PIN (Quynh viet logic, Unit Test)
    void generateNewCodes();
    bool validatePIN(const QString &inputPin) const;
    bool isExpired() const;
};

#endif // ATTENDANCESESSION_H