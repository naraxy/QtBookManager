#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QString>
#include <core/aboutMe/aboutme.h>
#include <core/addBook/addbook.h>
#include <core/allBook/allbook.h>
#include <core/delBook/delbook.h>
#include <core/init/initdb.h>

QT_BEGIN_NAMESPACE
class QAction;
class QMenu;
class QMenuBar;
class QPushButton;
class QGridLayout;
QT_END_NAMESPACE


class MainWidget : public QWidget
{
    Q_OBJECT

public:
    MainWidget(QWidget *parent = 0);
    ~MainWidget();
    void doInitDb();

public slots:
    void showWidget();

private slots:
    void showAboutMe();
    void showAddBook();
    void showAllBook();
    void showDelBook();

private:
    aboutMe *aboutMeDlg; //关于我对话框
    addBook *addBookDlg; //添加书籍界面
    allBook *allBookDlg; //浏览书籍界面
    delBook *delBookDlg; //删除书籍界面
    initDb *init; //初始化数据库

    QGridLayout *mainLayout; //主菜单样式
    QMenuBar *menuBar; //菜单栏
    QPushButton *newBtn,*viewBtn,*delBtn; //分页按键


    QMenu *aboutMenu; //关于菜单
    QAction *aboutMeAction; //关于我
    QAction *exitAction; //退出
};

#endif // MAINWIDGET_H
