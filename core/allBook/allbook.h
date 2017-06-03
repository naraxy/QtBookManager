#ifndef ALLBOOK_H
#define ALLBOOK_H

#include <QDialog>
#include "../../common/connectsql.h"
class QTableView;
class QTextEdit;
class QSpacerItem;

class allBook : public QDialog
{
    Q_OBJECT
public:
    explicit allBook(QWidget *parent = 0);
    ~allBook();
private:
    QTableView *tableView;
    QSpacerItem *horizontalSpacer;
    QPushButton *okBtn;
    QSqlTableModel *sqlModel;
    connectSql sql;

private slots:
    void refresh();
};

#endif // ALLBOOK_H
