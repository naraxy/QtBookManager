#include "core/mainwidget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
//    Q_INIT_RESOURCE(images); /*初始化资源*/
    QApplication a(argc, argv);
    MainWidget mainWidget;
    mainWidget.showWidget();

    return a.exec();
}
