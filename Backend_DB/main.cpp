#include <QCoreApplication>
#include "DatabaseManager.h"

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);

    auto &dbManager = DatabaseManager::getInstance();
    if (dbManager.connectDB()) {
        dbManager.initTables();
    }

    return a.exec();
}