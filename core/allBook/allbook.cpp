#include "allbook.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QTableView>
#include <QSqlTableModel>
#include <QSpacerItem>
//#include <QDebug>

allBook::allBook(QWidget *parent) : QDialog(parent)
{
//    初始化
    this->resize(485,354);
//    页面部件
    tableView = new QTableView();
    horizontalSpacer = new QSpacerItem(388,20);
    okBtn = new QPushButton();
//    页面布局
    QVBoxLayout *mainLayout = new QVBoxLayout();
    QHBoxLayout *btnLayout = new QHBoxLayout();
//    局部布局
    btnLayout->addSpacerItem(horizontalSpacer);
    btnLayout->addWidget(okBtn);
//    总体布局
    mainLayout->addWidget(tableView);
    mainLayout->addLayout(btnLayout);
//    部件设置
    tableView->resize(465,303);
    sql.createSqlModel();
    tableView->setModel(sql.sqlModel);
//    禁止编辑表格
    tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);

    okBtn->resize(75,23);
    okBtn->setText(tr("退出"));
//    运行布局
    this->setWindowTitle(tr("浏览全部图书"));
    this->setLayout(mainLayout);
    tableView->show();
//    信号与槽
    connect(okBtn,SIGNAL(clicked()),this,SLOT(refresh()));

}

allBook::~allBook()
{

}

void allBook::refresh()
{
//    退出时清除对话框对象
    this->setAttribute(Qt::WA_DeleteOnClose);
    this->close();
}
