#ifndef USER_H
#define USER_H

#include <QString>

class User {
protected:
    int userId;
    QString fullName;
    QString email;
    QString role;

public:
    User(int id, const QString &name, const QString &mail, const QString &r)
        : userId(id), fullName(name), email(mail), role(r) {}
    virtual ~User() = default;

    int getId() const { return userId; }
    QString getName() const { return fullName; }
    QString getRole() const { return role; }
};

class Student : public User {
private:
    QString studentCode;
    QString className;

public:
    Student(int id, const QString &name, const QString &mail, const QString &code, const QString &clazz)
        : User(id, name, mail, "STUDENT"), studentCode(code), className(clazz) {}

    QString getStudentCode() const { return studentCode; }
};

class Lecturer : public User {
private:
    QString lecturerCode;
    QString department;

public:
    Lecturer(int id, const QString &name, const QString &mail, const QString &code, const QString &dept)
        : User(id, name, mail, "LECTURER"), lecturerCode(code), department(dept) {}
};

#endif // USER_H