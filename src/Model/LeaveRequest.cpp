#include "LeaveRequest.h"
//sv nộp đơn xin nghỉ
LeaveRequest::LeaveRequest(int reqId, int stuId, int cId, const QDateTime &d,
                           const QString &rsn, const QString &proof)
    : requestId(reqId), studentId(stuId), courseId(cId),
      date(d), reason(rsn), proofAttachment(proof), status("Pending") {}
//trạng thái duyệt đơn
void LeaveRequest::updateRequestStatus(const QString &newStatus) {
    this->status = newStatus;
}
int LeaveRequest::getRequestId() const { return requestId; }
int LeaveRequest::getStudentId() const { return studentId; }
int LeaveRequest::getCourseId() const { return courseId; }
QDateTime LeaveRequest::getDate() const { return date; }
QString LeaveRequest::getReason() const { return reason; }
QString LeaveRequest::getProofAttachment() const { return proofAttachment; }
QString LeaveRequest::getStatus() const { return status; }