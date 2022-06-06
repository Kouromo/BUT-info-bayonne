#ifndef DATABASE_H
#define DATABASE_H

#include <QtSql/QSqlDatabase>
#include <QVariant>
#include <QSqlQuery>
#include <QtDebug>
#include <QSqlError>
#include <QSqlDatabase>
#define DATABASE_NAME "BD_Mateo_Lakartxela"
#define CONNECT_TYPE "QODBC"

class database
{


public:
    database();
    bool openDatabase();
    void closeDataBase();

private:
    QSqlDatabase mydb;
};

#endif // DATABASE_H
