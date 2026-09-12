#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <QDebug>
#include <QString>

class DatabaseManager {
private:
    QSqlDatabase db;
    DatabaseManager(); 
    ~DatabaseManager();

public:
    static DatabaseManager& getInstance();
    bool connectDB(const QString &path = "student_attendance.db");
    bool initTables();

    // Các hàm CRUD cho Account
    bool addAccount(const QString &username, const QString &password, const QString &role);
    bool checkLogin(const QString &username, const QString &password, QString &role);
    bool updateAccountPassword(int accountId, const QString &newPassword);
    bool deleteAccount(int accountId);

    // Các hàm CRUD cho Report / Attendance
    bool addReport(int accountId, const QString &status, const QString &checkInTime);
    QSqlQuery getReports();
};

#endif // DATABASEMANAGER_H