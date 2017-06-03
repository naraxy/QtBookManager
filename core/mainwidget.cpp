#include "mainwidget.h"
#include <QGridLayout>
#include <QtWidgets>
#include <QFile>

MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent)
{
    doInitDb();
    QGridLayout *mainLayout = new QGridLayout;

    menuBar = new QMenuBar;
    aboutMenu = new QMenu(tr("关于(&A)"),this);
    aboutMeAction = aboutMenu->addAction(tr("关于我"));
    exitAction = aboutMenu->addAction(tr("退出(&x)"));
    menuBar->addMenu(aboutMenu);
    mainLayout->addWidget(menuBar,0,0);

    newBtn = new QPushButton(tr("添加新书"));
    viewBtn= new QPushButton(tr("浏览全部"));
    delBtn= new QPushButton(tr("删除图书"));
//    按键样式设定
    newBtn->setStyleSheet("QPushButton{background: rgb(68, 69, 73);border: 1px solid rgb(50, 50, 50);color: white;width: 75px;height: 75px;}"
                          "QPushButton:hover{background: rgb(85, 85, 85);}"
                          "QPushButton:pressed{background: rgb(80, 80, 80);}"
                          "QPushButton:checked{background: green;}");
    viewBtn->setStyleSheet("QPushButton{background: rgb(68, 69, 73);border: 1px solid rgb(50, 50, 50);color: white;width: 75px;height: 75px;}"
                           "QPushButton:hover{background: rgb(85, 85, 85);}"
                           "QPushButton:pressed{background: rgb(80, 80, 80);}"
                           "QPushButton:checked{background: green;}");
    delBtn->setStyleSheet("QPushButton{background: rgb(68, 69, 73);border: 1px solid rgb(50, 50, 50);color: white;width: 75px;height: 75px;}"
                          "QPushButton:hover{background: rgb(85, 85, 85);}"
                          "QPushButton:pressed{background: rgb(80, 80, 80);}"
                          "QPushButton:checked{background: green;}");

    mainLayout->addWidget(newBtn,1,0);
    mainLayout->addWidget(viewBtn,1,1);
    mainLayout->addWidget(delBtn,1,2);
    mainLayout->setColumnStretch(1, 20);
    mainLayout->setColumnStretch(2, 20);
    mainLayout->setColumnStretch(3, 20);

    this->setLayout(mainLayout);
    connect(aboutMeAction,SIGNAL(triggered()),this,SLOT(showAboutMe()));
    connect(exitAction,SIGNAL(triggered()),this,SLOT(close()));
    connect(newBtn,SIGNAL(clicked()),this,SLOT(showAddBook()));
    connect(viewBtn,SIGNAL(clicked()),this,SLOT(showAllBook()));
    connect(delBtn,SIGNAL(clicked()),this,SLOT(showDelBook()));
}

MainWidget::~MainWidget()
{

}

void MainWidget::doInitDb()
{
    QFile file("./bookdata.db");
    if (!file.exists())
        init->createDb();
}

void MainWidget::showWidget()
{
    this->setStyleSheet("color:white;background-color: gray");
    this->showNormal();
    this->raise();
    this->activateWindow();

}


void MainWidget::showAboutMe()
{
    aboutMeDlg = new aboutMe(this); //关于我对话框
    aboutMeDlg->show();
}

void MainWidget::showAddBook()
{
    addBookDlg = new addBook(this); //添加书籍界面
    addBookDlg->exec();
}

void MainWidget::showAllBook()
{
    allBookDlg = new allBook(this); //浏览书籍界面
    allBookDlg->exec();
}

void MainWidget::showDelBook()
{
    delBookDlg = new delBook(this); //删除书籍界面
    delBookDlg->exec();
}
