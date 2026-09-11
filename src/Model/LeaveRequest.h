#ifndef LEAVEREQUEST_H
#define LEAVEREQUEST_H
#include <QString>
#include <QDateTime>
class LeaveRequest {
private:
    int requestId;
    int studentId;
    int courseId;
    QDateTime date;
    QString reason;
    QString proofAttachment;
    QString status;
public:
    LeaveRequest(int reqId, int stuId, int cId, const QDateTime &d,
                 const QString &rsn, const QString &proof);

    void updateRequestStatus(const QString &newStatus);
    int getRequestId() const;
    int getStudentId() const;
    int getCourseId() const;
    QDateTime getDate() const;
    QString getReason() const;
    QString getProofAttachment() const;
    QString getStatus() const;
};
#endif 