#ifndef CONNECTSQL_H
#define CONNECTSQL_H
#include <QsqlDatabase>
class QSqlTableModel;


class connectSql
{
public:
    int maxid();
    void addid(int bookId,const QString &bookName,const QString &bookAuthor);
    void createSqlModel();
    void delId(const int bookId);
    QSqlTableModel *sqlModel;
};

#endif // CONNECTSQL_H
