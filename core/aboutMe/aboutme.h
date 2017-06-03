#ifndef ABOUTME_H
#define ABOUTME_H

#include <QDialog>
class QLabel;


class aboutMe : public QDialog
{
    Q_OBJECT
public:
    explicit aboutMe(QWidget *parent = 0);
    ~aboutMe();

private:
    QLabel *title;
    QLabel *info;
    QLabel *copyright;
    QPushButton *okBtn;

};

#endif // ABOUTME_H
