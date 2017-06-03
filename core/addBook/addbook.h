#ifndef ADDBOOK_H
#define ADDBOOK_H

#include <QDialog>
#include "../../common/connectsql.h"
class QLabel;
class QLineEdit;

class addBook : public QDialog
{
    Q_OBJECT
public:
    explicit addBook(QWidget *parent = 0);
    ~addBook();

private slots:
    void add();

private:
    connectSql *sql;
    QLabel *bookName;
    QLabel *bookAuthor;
    QLabel *bookId;
    QLineEdit *Name;
    QLineEdit *Author;
    QLabel *autoId;
    QPushButton *okBtn,*cancelBtn;
    int maxID;
};

#endif // ADDBOOK_H
