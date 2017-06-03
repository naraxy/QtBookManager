#include "addbook.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
//#include <QDebug>

addBook::addBook(QWidget *parent) : QDialog(parent)
{
//    初始化
    maxID = sql->maxid();
    this->resize(320,120);

//    页面部件
    bookId = new QLabel();
    bookName = new QLabel();
    bookAuthor = new QLabel();
    autoId = new QLabel();

    Name = new QLineEdit();
    Author = new QLineEdit();

    okBtn = new QPushButton();
    cancelBtn = new QPushButton();
//    页面布局
    QVBoxLayout *mainLayout = new QVBoxLayout();
    QHBoxLayout *idLayout = new QHBoxLayout();
    QHBoxLayout *nameLayout = new QHBoxLayout();
    QHBoxLayout *authorLayout = new QHBoxLayout();
    QHBoxLayout *btnLayout = new QHBoxLayout();
//    局部布局
    idLayout->addWidget(bookId);
    idLayout->addWidget(autoId);
    nameLayout->addWidget(bookName);
    nameLayout->addWidget(Name);
    authorLayout->addWidget(bookAuthor);
    authorLayout->addWidget(Author);
    btnLayout->addWidget(okBtn);
    btnLayout->addWidget(cancelBtn);
//    总体布局
    mainLayout->addLayout(idLayout);
    mainLayout->addLayout(nameLayout);
    mainLayout->addLayout(authorLayout);
    mainLayout->addLayout(btnLayout);
//    部件设置
    bookId->setText(tr("编号"));
    autoId->setText(QString("ID:%1").arg(maxID));
    bookName->setText(tr("图书名："));
    bookAuthor->setText(tr("作者："));
    okBtn->setText(tr("确认"));
    cancelBtn->setText(tr("取消"));
//    运行布局
    this->setWindowTitle(tr("添加图书"));
    this->setLayout(mainLayout);
//    信号与槽
    connect(okBtn,SIGNAL(clicked()),this,SLOT(add()));
    connect(cancelBtn,SIGNAL(clicked()),this,SLOT(hide()));


}

addBook::~addBook()
{

}

void addBook::add()
{
//    测试
//    qDebug() << maxID;
    QString addName = Name->text();
//    qDebug() << addName;
    QString addAuthor = Author->text();
//    qDebug() << addAuthor;
    sql->addid(maxID,addName,addAuthor);
    this->setAttribute(Qt::WA_DeleteOnClose); //删除页面对象，切记要重新建立对象才能激活页面
    this->close();
}
