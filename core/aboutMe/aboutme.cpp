#include "aboutme.h"
#include <QGridLayout>
#include <QPushButton>
#include <QLabel>

aboutMe::aboutMe(QWidget *parent) : QDialog(parent)
{
//    this->resize(320,190);
//    设置标题栏隐藏
//    this->setWindowFlags(Qt::FramelessWindowHint | Qt::Dialog);

    title = new QLabel();
    info = new QLabel();
    copyright = new QLabel();
    okBtn = new QPushButton();

    title->setText(tr("关于我"));
    info->setText(tr("Made by Naraxy,06-01-2017,ver:1.0"));
    okBtn->setText(tr("确定"));

    QGridLayout *aboutMeLayout = new QGridLayout();
    aboutMeLayout->addWidget(title,0,0,1,1);
    aboutMeLayout->addWidget(info,1,0,2,3);
    aboutMeLayout->addWidget(okBtn,3,1,1,1);

    this->setLayout(aboutMeLayout);
    this->setAttribute(Qt::WA_DeleteOnClose);

    connect(okBtn, SIGNAL(clicked()), this, SLOT(close()));
}

aboutMe::~aboutMe()
{

}
