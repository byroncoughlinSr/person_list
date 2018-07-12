#include "databasehelper.h"
#include <QSqlDriver>
#include <QSqlQueryModel>
#include <QSqlDatabase>
#include <QtDebug>
#include <QMessageBox>
#include <QtSql>
#include <QDate>



DatabaseHelper::DatabaseHelper()
{

}

bool DatabaseHelper::createConnection(QString *uname, QString *pword)
{
    QString username = *uname;
    QString password = *pword;
    const QString DRIVER("QMYSQL");
    QSqlDatabase db = QSqlDatabase::addDatabase(DRIVER);
    db.setDatabaseName("artc");
    db.setHostName("192.168.56.103");
    db.setUserName(username);
    db.setPassword(password);
    db.setDatabaseName("dbArtc");
    if (!db.open()) {
        QMessageBox::critical(0, QObject::tr("Database Error"), db.lastError().text());
        return false;
    }
    return true;
}

 QSqlQueryModel *DatabaseHelper::getListView ()
{
    QSqlQueryModel *qryModel = new QSqlQueryModel();
    qryModel->setQuery("SELECT DISTINCT(DNADisplayName) FROM tblDNAFamily ORDER BY DNADisplayName ASC");
    return qryModel;
 }




