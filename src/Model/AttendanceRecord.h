#ifndef ATTENDANCERECORD_H
#define ATTENDANCERECORD_H
#include <QString>
#include <QDateTime>
class AttendanceRecord {
private:
    int sessionId;
    int studentId;
    QDateTime timestamp;
    QString status;
public:
    AttendanceRecord(int sId, int stuId, const QDateTime &time, const QString &st);
    void updateStatus(const QString &newStatus);
    int getSessionId() const;
    int getStudentId() const;
    QDateTime getTimestamp() const;
    QString getStatus() const;
};
#endif 