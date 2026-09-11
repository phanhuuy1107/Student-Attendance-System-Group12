#include "AttendanceSession.h"
#include <QRandomGenerator>
#include <QCryptographicHash>
AttendanceSession::AttendanceSession(int sId, int cId, int dur)
    : sessionId(sId), courseId(cId), duration(dur), status("Active") {
    //ghi nhận tgian bắt đầu điểm danh
    startTime = QDateTime::currentDateTime();
    //tạo 2 mã ngay khi phiên học được tạo
    qrCode = generateQRCode();
    pinCode = generatePIN();
}
//FR3: thuật toán sinh mã PIN 6 số ngẫu nhiên
QString AttendanceSession::generatePIN() {
    int randNum = QRandomGenerator::global()->bounded(100000, 1000000);
    return QString::number(randNum);
}
//FR3: thuật toán sinh mã QR động
QString AttendanceSession::generateQRCode() {
    QString seed = QString("SESSION:%1:TIME:%2:SALT:%3")
                       .arg(sessionId)
                       .arg(startTime.toSecsSinceEpoch())
                       .arg(QRandomGenerator::global()->generate());
    return QString(QCryptographicHash::hash(seed.toUtf8(), QCryptographicHash::Sha256).toHex());
}
//kiểm tra TTL của phiên điểm danh
bool AttendanceSession::isExpired() const {
    if (status == "Closed") return true;
    qint64 elapsedSecs = startTime.secsTo(QDateTime::currentDateTime());
    return elapsedSecs > (duration * 60);
}
//NFR: xác thực mã đầu vào
bool AttendanceSession::isValidCode(const QString &inputCode) const {
    if (isExpired()) return false;//vô hiệu hoá khi quá TTL
    QString clean = inputCode.trimmed();
    return (clean == pinCode || clean == qrCode);
}
//NFR Integrity: kiểm tra ID của sinh viên trong phiên
bool AttendanceSession::isAlreadyCheckedIn(int studentId) const {
    return checkedInStudents.find(studentId) != checkedInStudents.end();
}
//NFR Integrity: ghi nhận sinh viên trong phiên( chống trùng lặp)
bool AttendanceSession::recordStudent(int studentId) {
    if (isAlreadyCheckedIn(studentId)) return false;
    checkedInStudents.insert(studentId);
    return true;
}
void AttendanceSession::closeSession() {
    status = "Closed";
}
int AttendanceSession::getSessionId() const { return sessionId; }
int AttendanceSession::getCourseId() const { return courseId; }
QString AttendanceSession::getQRCode() const { return qrCode; }
QString AttendanceSession::getPIN() const { return pinCode; }
QDateTime AttendanceSession::getStartTime() const { return startTime; }
int AttendanceSession::getDuration() const { return duration; }
QString AttendanceSession::getStatus() const { return status; }