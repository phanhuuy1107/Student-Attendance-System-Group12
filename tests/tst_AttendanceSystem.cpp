#include <QtTest/QtTest>
#include "User.h"
#include "Course.h"
#include "AttendanceSession.h"
#include "AttendanceRecord.h"
#include "LeaveRequest.h"
class TestAttendanceSystem : public QObject {
    Q_OBJECT
private slots:
    // test các FR
    void testFR3_SessionTokenGeneration();
    void testFR8_CheckInSuccessViaPIN();
    void testFR8_CheckInSuccessViaQR();
    // test các NFR
    void testNFR_CompositeKeyDuplicateRejection();
    void testNFR_TTLExpiration();
    void testNFR_InactiveAccountRejection();
    void testNFR_SHA256PasswordHash();
};
// Test FR3: kiểm tra định dạng và tính hợp lệ của 2 loại mã
void TestAttendanceSystem::testFR3_SessionTokenGeneration() {
    Lecturer lecturer(10, "Dr. Robert", "robert@uni.edu", "pass", "Active", "LEC01", "IT");
    AttendanceSession session = lecturer.createAttendanceSession(1, 101, 15);
    QString pin = session.getPIN();
    QCOMPARE(pin.length(), 6);
    bool isNumeric = false;
    pin.toInt(&isNumeric);
    QVERIFY(isNumeric);
    QString qr = session.getQRCode();
    QCOMPARE(qr.length(), 64);
}
// Test FR8: sv điểm danh thành công bằng nhập mã Pin
void TestAttendanceSystem::testFR8_CheckInSuccessViaPIN() {
    AttendanceSession session(2, 101, 10);
    Student student(1, "Nguyen Van A", "a@uni.edu", "pass", "Active", 1001, "SV001", "SE01");
    bool ok = student.enterPIN(session, session.getPIN());
    QVERIFY(ok);
    QVERIFY(session.isAlreadyCheckedIn(student.getStudentId()));
}
// Test FR8: sv điểm danh thành công bằng phương thức quét mã QR
void TestAttendanceSystem::testFR8_CheckInSuccessViaQR() {
    AttendanceSession session(3, 101, 10);
    Student student(2, "Tran Thi B", "b@uni.edu", "pass", "Active", 1002, "SV002", "SE01");
    bool ok = student.scanQRCode(session, session.getQRCode());
    QVERIFY(ok);
    QVERIFY(session.isAlreadyCheckedIn(student.getStudentId()));
}
// Test NFR: tránh điểm danh trùng lặp
void TestAttendanceSystem::testNFR_CompositeKeyDuplicateRejection() {
    AttendanceSession session(4, 101, 10);
    Student student(3, "Le Van C", "c@uni.edu", "pass", "Active", 1003, "SV003", "SE01");
    QVERIFY(student.enterPIN(session, session.getPIN()));
    QVERIFY(!student.enterPIN(session, session.getPIN()));
}
// Test NFR: đảm bảo TTL của phiên điểm danh
void TestAttendanceSystem::testNFR_TTLExpiration() {
    AttendanceSession session(5, 101, 0);
    Student student(4, "Pham Van D", "d@uni.edu", "pass", "Active", 1004, "SV004", "SE01");
    QTest::qSleep(1000);
    QVERIFY(session.isExpired());
    QVERIFY(!student.enterPIN(session, session.getPIN()));
}
// Test NFR: kiểm tra trạng thái tài khoản
void TestAttendanceSystem::testNFR_InactiveAccountRejection() {
    AttendanceSession session(6, 101, 10);
    Student student(5, "Hoang Van E", "e@uni.edu", "pass", "Suspended", 1005, "SV005", "SE01");
    QVERIFY(!student.enterPIN(session, session.getPIN()));
    QVERIFY(!student.scanQRCode(session, session.getQRCode()));
}
// Test NFR: thuật toán SHA-256
void TestAttendanceSystem::testNFR_SHA256PasswordHash() {
    User user(99, "User Test", "user@uni.edu", "PlainSecretPass", "Active", "Student");
    QVERIFY(user.login("user@uni.edu", "PlainSecretPass"));
    QVERIFY(!user.login("user@uni.edu", "WrongPass"));
}
QTEST_MAIN(TestAttendanceSystem)
#include "tst_AttendanceSystem.moc"