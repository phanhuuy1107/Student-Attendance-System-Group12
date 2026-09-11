#ifndef USER_H
#define USER_H
#include <QString>
#include <QDateTime>
#include <vector>
class AttendanceSession;
class AttendanceRecord;
// class user
class User {
protected:
    int userId;
    QString fullName;
    QString email;
    QString passwordHash; //NFR Security
    QString status;
    QString role;
public:
    User(int id, const QString &name, const QString &mail, const QString &rawPassword,
         const QString &st, const QString &r);
    virtual ~User() = default;
    virtual bool login(const QString &inputEmail, const QString &inputPassword);
    virtual void logout();
    int getUserId() const;
    QString getFullName() const;
    QString getEmail() const;
    QString getStatus() const;
    QString getRole() const;
    void setStatus(const QString &st);
};
// class admin
class Admin : public User {
private:
    QString adminCode;
public:
    Admin(int id, const QString &name, const QString &mail, const QString &rawPassword,
          const QString &st, const QString &aCode);
    void manageAccount(const QString &action, const QString &userData);
    void manageClass(const QString &action, const QString &classData);
    QString getAdminCode() const;
};
//class lecturer
class Lecturer : public User {
private:
    QString lecturerCode;
    QString department;
public:
    Lecturer(int id, const QString &name, const QString &mail, const QString &rawPassword,
             const QString &st, const QString &lCode, const QString &dept);
    //FR3:lecturer tạo điểm danh với thời gian quy định
    AttendanceSession createAttendanceSession(int sessionId, int courseId, int duration);
    std::vector<AttendanceRecord> viewRealtimeAttendance(int sessionId);
    void updateAttendanceStatus(AttendanceRecord &record, const QString &newStatus);
    void exportAttendanceReport(int courseId, const QString &dateRange);
    QString getLecturerCode() const;
    QString getDepartment() const;
};
//class student
class Student : public User {
private:
    int studentId;
    QString studentCode;
    QString className;
public:
    Student(int id, const QString &name, const QString &mail, const QString &rawPassword,
            const QString &st, int sId, const QString &sCode, const QString &cName);
    //FR8: logic tạo 2 cách điểm danh
    bool scanQRCode(AttendanceSession &session, const QString &qrInput);
    bool enterPIN(AttendanceSession &session, const QString &pinInput);
    //logic xác thực và ghi nhận điểm danh
    bool checkIn(AttendanceSession &session, const QString &token);
    std::vector<AttendanceRecord> viewAttendanceHistory();
    void submitLeaveRequest(const QDateTime &date, const QString &reason, const QString &proofAttachment);
    int getStudentId() const;
    QString getStudentCode() const;
    QString getClassName() const;
};
#endif 