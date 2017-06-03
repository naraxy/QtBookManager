#include "delbook.h"
#include <QLabel>
#include <QLineEdit>
#include <QSpacerItem>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>

delBook::delBook(QWidget *parent) : QDialog(parent)
{
//    初始化
    this->resize(335,127);
//    页面部件
    delTitle = new QLabel();
    delIdBook = new QLineEdit();
    horizontalSpacer = new QSpacerItem(20,58);
    VerticalSpacer = new QSpacerItem(68,20);
    okBtn = new QPushButton();
    cancelBtn = new QPushButton();
//    页面布局
    QVBoxLayout *mainLayout = new QVBoxLayout();
    QHBoxLayout *delLayout = new QHBoxLayout();
    QHBoxLayout *btnLayout = new QHBoxLayout();
//    局部布局
    delLayout->addWidget(delTitle);
    delLayout->addWidget(delIdBook);
    btnLayout->addWidget(okBtn);
    btnLayout->addSpacerItem(VerticalSpacer);
    btnLayout->addWidget(cancelBtn);
//    总体布局
    mainLayout->addLayout(delLayout);
    mainLayout->addSpacerItem(horizontalSpacer);
    mainLayout->addLayout(btnLayout);
//    部件设置
    delTitle->resize(168,20);
    delIdBook->resize(133,20);
    okBtn->resize(75,23);
    cancelBtn->resize(75,23);

    delTitle->setText(tr("填入你想删除的书籍编号(ID)："));
    okBtn->setText(tr("确定"));
    cancelBtn->setText(tr("取消"));
//    运行布局
    this->setWindowTitle(tr("删除图书"));
    this->setLayout(mainLayout);
//    信号与槽
    connect(okBtn,SIGNAL(clicked()),this,SLOT(del()));
    connect(cancelBtn,SIGNAL(clicked()),this,SLOT(hide()));


}

delBook::~delBook()
{

}

void delBook::del()
{
    int writeId = delIdBook->text().toInt();
    sql->delId(writeId);
//    退出时清除对话框对象
    this->setAttribute(Qt::WA_DeleteOnClose);
    this->close();
}
