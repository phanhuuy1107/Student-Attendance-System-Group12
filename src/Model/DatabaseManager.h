#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QString>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QVector>

class DatabaseManager {
public:
    static DatabaseManager& getInstance();

    // Khoi tao va dong ket noi SQLite
    bool initDatabase(const QString &dbPath = "database/attendance.db");
    void closeDatabase();

    // FR1: Quan ly Account & Dang nhap (Ky Anh)
    bool authenticateUser(const QString &username, const QString &password, QString &role, int &userId);

    // FR6: Xuat du lieu va Thong ke Report (Ky Anh)
    QVector<QStringList> getAttendanceReport(int sessionId);

private:
    DatabaseManager() = default;
    ~DatabaseManager();
    DatabaseManager(const DatabaseManager&) = delete;
    DatabaseManager& operator=(const DatabaseManager&) = delete;

    QSqlDatabase db;
};

#endif // DATABASEMANAGER_H