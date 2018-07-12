#ifndef DATABASEHELPER_H
#define DATABASEHELPER_H

#include <QSqlQueryModel>

class DatabaseHelper
{
public:
    DatabaseHelper();
    bool createConnection(QString *username, QString *password);
    QSqlQueryModel *getListView();
};

#endif // DATABASEHELPER_H
