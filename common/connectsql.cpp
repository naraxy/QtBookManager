#include "connectsql.h"
#include <QtSql>
#include <QSqlTableModel>
#include <QSqlError>
#include <QDebug>

int connectSql::maxid()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("./bookdata.db");
    db.open();
    QSqlQuery q;
    int maxId = 0;
    q.prepare("select max(id) from books");
    if(!q.exec())
    {
        qDebug() << q.lastError();
    }
    else
    {
        while (q.next()) {
            maxId = q.value(0).toInt();
//            qDebug()<<QString("max id:%1").arg(maxId);
        }
    }
    db.close();
    QSqlDatabase::removeDatabase("QSQLITE");
    return maxId += 1;
}

void connectSql::addid(int bookId, const QString &bookName, const QString &bookAuthor)
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("./bookdata.db");
    db.open();
    QSqlQuery q;
    q.exec("insert into books(id, title, author) values(?, ?, ?)");
    q.addBindValue(bookId);
    q.addBindValue(bookName);
    q.addBindValue(bookAuthor);
    if(!q.exec())
    {
        qDebug() << q.lastError();
    }
    else
    {
        qDebug()<< "ok";
    }
    db.close();
    QSqlDatabase::removeDatabase("QSQLITE");
}

void connectSql::createSqlModel()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("./bookdata.db");
    if(db.open())
    {
        sqlModel = new QSqlTableModel();
        sqlModel->setTable("books");
        sqlModel->select();
        sqlModel->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
        sqlModel->setHeaderData(1, Qt::Horizontal, QObject::tr("书籍"));
        sqlModel->setHeaderData(2, Qt::Horizontal, QObject::tr("作者"));
    }
    db.close();
    QSqlDatabase::removeDatabase("QSQLITE");
}

void connectSql::delId(const int bookId)
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("./bookdata.db");
    QSqlQuery q;
    if(db.open())
    {
        q.prepare("delete from books where id = ?");
        q.addBindValue(bookId);
    }
    if(!q.exec())
    {
        qDebug() << q.lastError();
    }
    else
    {
        qDebug()<< "ok";
    }
    db.close();
    QSqlDatabase::removeDatabase("QSQLITE");
}
