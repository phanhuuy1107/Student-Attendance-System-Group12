#ifndef ATTENDANCESESSION_H
#define ATTENDANCESESSION_H
#include <QString>
#include <QDateTime>
#include <set>
class AttendanceSession {
private:
    int sessionId;
    int courseId;
    QString qrCode;
    QString pinCode;
    QDateTime startTime;
    int duration;
    QString status;
    std::set<int> checkedInStudents;// NFR Integrity
public:
    AttendanceSession(int sId, int cId, int dur);
    // thuật toán sinh mã động
    QString generateQRCode();
    QString generatePIN();
    //kiểm tra tính hợp lệ của mã và trạng thái TTL của phiên
    bool isValidCode(const QString &inputCode) const;
    bool isExpired() const;
    // ghi nhận sinh viên điểm danh 
    bool isAlreadyCheckedIn(int studentId) const;
    bool recordStudent(int studentId);
    void closeSession();
    int getSessionId() const;
    int getCourseId() const;
    QString getQRCode() const;
    QString getPIN() const;
    QDateTime getStartTime() const;
    int getDuration() const;
    QString getStatus() const;
};
#endif