#include "User.h"
#include "AttendanceSession.h"
#include "AttendanceRecord.h"
#include <QCryptographicHash>
// xử lý class user
User::User(int id, const QString &name, const QString &mail, const QString &rawPassword,
           const QString &st, const QString &r)
    : userId(id), fullName(name), email(mail), status(st), role(r) {
    // xử lý NFR Security bằng thuật toán SHA-256
    this->passwordHash = QString(QCryptographicHash::hash(
        rawPassword.toUtf8(), QCryptographicHash::Sha256).toHex());
}
bool User::login(const QString &inputEmail, const QString &inputPassword) {
    if (status != "Active") return false;// chỉ cho phép đăng nhập khi tài khoản "active"
    //mật khẩu người dùng nhập được SHA-256 xử lý
    QString hashedInput = QString(QCryptographicHash::hash(
        inputPassword.toUtf8(), QCryptographicHash::Sha256).toHex());
    //so sánh mail và mật khẩu để xác thực
    return (email == inputEmail && passwordHash == hashedInput);
}
void User::logout() {}
int User::getUserId() const { return userId; }
QString User::getFullName() const { return fullName; }
QString User::getEmail() const { return email; }
QString User::getStatus() const { return status; }
QString User::getRole() const { return role; }
void User::setStatus(const QString &st) { status = st; }
// xử lý class admin
Admin::Admin(int id, const QString &name, const QString &mail, const QString &rawPassword,
             const QString &st, const QString &aCode)
    : User(id, name, mail, rawPassword, st, "Admin"), adminCode(aCode) {}
void Admin::manageAccount(const QString &action, const QString &userData) {
    Q_UNUSED(action);
    Q_UNUSED(userData);
}
void Admin::manageClass(const QString &action, const QString &classData) {
    Q_UNUSED(action);
    Q_UNUSED(classData);
}
QString Admin::getAdminCode() const { return adminCode; }
//xử lý class lecturer
Lecturer::Lecturer(int id, const QString &name, const QString &mail, const QString &rawPassword,
                   const QString &st, const QString &lCode, const QString &dept)
    : User(id, name, mail, rawPassword, st, "Lecturer"), lecturerCode(lCode), department(dept) {}
//FR3: tạo phiên điểm danh với mã QR và mã PIN
AttendanceSession Lecturer::createAttendanceSession(int sessionId, int courseId, int duration) {
    return AttendanceSession(sessionId, courseId, duration);
}
std::vector<AttendanceRecord> Lecturer::viewRealtimeAttendance(int sessionId) {
    Q_UNUSED(sessionId);
    return std::vector<AttendanceRecord>();
}
void Lecturer::updateAttendanceStatus(AttendanceRecord &record, const QString &newStatus) {
    record.updateStatus(newStatus);
}
void Lecturer::exportAttendanceReport(int courseId, const QString &dateRange) {
    Q_UNUSED(courseId);
    Q_UNUSED(dateRange);
}
QString Lecturer::getLecturerCode() const { return lecturerCode; }
QString Lecturer::getDepartment() const { return department; }
// xử lý class student
Student::Student(int id, const QString &name, const QString &mail, const QString &rawPassword,
                 const QString &st, int sId, const QString &sCode, const QString &cName)
    : User(id, name, mail, rawPassword, st, "Student"),
      studentId(sId), studentCode(sCode), className(cName) {}
//FR8: kiểm tra điểm danh qua 3 bước
bool Student::checkIn(AttendanceSession &session, const QString &token) {
    //kiểm tra tài khoản
    if (this->status != "Active") return false;
    //kiểm tra phiên điểm danh
    if (!session.isValidCode(token)) return false;
    //rà soát trùng lặp khi điểm danh
    return session.recordStudent(this->studentId);
}
//Điểm danh bằng QR code
bool Student::scanQRCode(AttendanceSession &session, const QString &qrInput) {
    return checkIn(session, qrInput);
}
//Điểm danh bằng mã Pin
bool Student::enterPIN(AttendanceSession &session, const QString &pinInput) {
    return checkIn(session, pinInput);
}
std::vector<AttendanceRecord> Student::viewAttendanceHistory() {
    return std::vector<AttendanceRecord>();
}
void Student::submitLeaveRequest(const QDateTime &date, const QString &reason, const QString &proofAttachment) {
    Q_UNUSED(date);
    Q_UNUSED(reason);
    Q_UNUSED(proofAttachment);
}
int Student::getStudentId() const { return studentId; }
QString Student::getStudentCode() const { return studentCode; }
QString Student::getClassName() const { return className; }