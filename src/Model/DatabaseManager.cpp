#include "DatabaseManager.h"

DatabaseManager::DatabaseManager() {
    db = QSqlDatabase::addDatabase("QSQLITE");
}

DatabaseManager::~DatabaseManager() {
    if (db.isOpen()) {
        db.close();
    }
}

DatabaseManager& DatabaseManager::getInstance() {
    static DatabaseManager instance;
    return instance;
}

bool DatabaseManager::connectDB(const QString &path) {
    db.setDatabaseName(path);
    if (!db.open()) {
        qDebug() << "Error: Connection with database fail: " << db.lastError().text();
        return false;
    }
    qDebug() << "Database connected successfully!";
    return true;
}

bool DatabaseManager::initTables() {
    QSqlQuery query;

    // Tạo bảng Account
    QString createAccountTable = "CREATE TABLE IF NOT EXISTS Account ("
                                 "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                                 "username TEXT UNIQUE NOT NULL, "
                                 "password TEXT NOT NULL, "
                                 "role TEXT NOT NULL);";

    // Tạo bảng Report / Điểm danh
    QString createReportTable = "CREATE TABLE IF NOT EXISTS Report ("
                                "report_id INTEGER PRIMARY KEY AUTOINCREMENT, "
                                "account_id INTEGER, "
                                "check_in_time TEXT, "
                                "status TEXT, "
                                "FOREIGN KEY(account_id) REFERENCES Account(id));";

    if (!query.exec(createAccountTable)) {
        qDebug() << "Failed to create Account table:" << query.lastError().text();
        return false;
    }

    if (!query.exec(createReportTable)) {
        qDebug() << "Failed to create Report table:" << query.lastError().text();
        return false;
    }

    return true;
}

// --- CRUD CHO ACCOUNT ---

bool DatabaseManager::addAccount(const QString &username, const QString &password, const QString &role) {
    QSqlQuery query;
    query.prepare("INSERT INTO Account (username, password, role) VALUES (:username, :password, :role)");
    query.bindValue(":username", username);
    query.bindValue(":password", password); // Lưu ý: thực tế nên mã hóa mật khẩu (như SHA256)
    query.bindValue(":role", role);

    if (!query.exec()) {
        qDebug() << "Add Account failed: " << query.lastError().text();
        return false;
    }
    return true;
}

bool DatabaseManager::checkLogin(const QString &username, const QString &password, QString &role) {
    QSqlQuery query;
    query.prepare("SELECT role FROM Account WHERE username = :username AND password = :password");
    query.bindValue(":username", username);
    query.bindValue(":password", password);

    if (query.exec() && query.next()) {
        role = query.value(0).toString();
        return true;
    }
    return false;
}

bool DatabaseManager::updateAccountPassword(int accountId, const QString &newPassword) {
    QSqlQuery query;
    query.prepare("UPDATE Account SET password = :password WHERE id = :id");
    query.bindValue(":password", newPassword);
    query.bindValue(":id", accountId);

    return query.exec();
}

bool DatabaseManager::deleteAccount(int accountId) {
    QSqlQuery query;
    query.prepare("DELETE FROM Account WHERE id = :id");
    query.bindValue(":id", accountId);

    return query.exec();
}

// --- CRUD CHO REPORT ---

bool DatabaseManager::addReport(int accountId, const QString &status, const QString &checkInTime) {
    QSqlQuery query;
    query.prepare("INSERT INTO Report (account_id, check_in_time, status) VALUES (:account_id, :check_in_time, :status)");
    query.bindValue(":account_id", accountId);
    query.bindValue(":check_in_time", checkInTime);
    query.bindValue(":status", status);

    return query.exec();
}

QSqlQuery DatabaseManager::getReports() {
    QSqlQuery query("SELECT r.report_id, a.username, r.check_in_time, r.status "
                    "FROM Report r JOIN Account a ON r.account_id = a.id");
    return query;
}