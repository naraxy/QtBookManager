#ifndef DELBOOK_H
#define DELBOOK_H

#include <QDialog>
#include "../../common/connectsql.h"
class QLabel;
class QLineEdit;
class QSpacerItem;

class delBook : public QDialog
{
    Q_OBJECT
public:
    explicit delBook(QWidget *parent = 0);
    ~delBook();

private:
    QLabel *delTitle;
    QLineEdit *delIdBook;
    QSpacerItem *horizontalSpacer,*VerticalSpacer;
    QPushButton *okBtn,*cancelBtn;
    connectSql *sql;

private slots:
    void del();
};

#endif // DELBOOK_H
