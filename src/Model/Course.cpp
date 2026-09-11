#include "Course.h"
//khởi tạo môn học
Course::Course(int id, const QString &code, const QString &name, int cr)
    : courseId(id), courseCode(code), courseName(name), credits(cr) {}
//hiển thị Mã môn- Tên môn
QString Course::getCourseInfo() const {
    return QString("%1 - %2 (%3 Credits)").arg(courseCode, courseName).arg(credits);
}
int Course::getCourseId() const { return courseId; }
QString Course::getCourseCode() const { return courseCode; }
QString Course::getCourseName() const { return courseName; }
int Course::getCredits() const { return credits; }