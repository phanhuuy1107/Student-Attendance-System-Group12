#include "AttendanceRecord.h"
//log điểm danh khi thực hiện quá số lần quy định
AttendanceRecord::AttendanceRecord(int sId, int stuId, const QDateTime &time, const QString &st)
    : sessionId(sId), studentId(stuId), timestamp(time), status(st) {}
//gv cập nhật trạng thái điểm danh
void AttendanceRecord::updateStatus(const QString &newStatus) {
    this->status = newStatus;
}
int AttendanceRecord::getSessionId() const { return sessionId; }
int AttendanceRecord::getStudentId() const { return studentId; }
QDateTime AttendanceRecord::getTimestamp() const { return timestamp; }
QString AttendanceRecord::getStatus() const { return status; }