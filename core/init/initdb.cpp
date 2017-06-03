#include "initdb.h"
#include <QtSql>
//#include <QDebug>
#include <QMessageBox>

void initDb::createDb()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("./bookdata.db");

    if (!db.open())
    {
//        qDebug()<<db.lastError();
        QMessageBox::information(NULL, "error", "Connect false", QMessageBox::Yes);
    }
    else
    {
        QSqlQuery q;
        q.exec("create table books(id integer primary key, title varchar, author varchar)");
        q.exec("insert into books values(1,'Foundation', 'Science Fiction')");
        QMessageBox::information(NULL, "OK", QObject::tr("数据库已建立"), QMessageBox::Yes);
        db.close();
        QSqlDatabase::removeDatabase("QSQLITE");
    }    
}

