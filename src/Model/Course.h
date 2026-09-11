#ifndef COURSE_H
#define COURSE_H
#include <QString>
class Course {
private:
    int courseId;
    QString courseCode;
    QString courseName;
    int credits;
public:
    Course(int id, const QString &code, const QString &name, int cr);
    QString getCourseInfo() const;
    int getCourseId() const;
    QString getCourseCode() const;
    QString getCourseName() const;
    int getCredits() const;
};
#endif 