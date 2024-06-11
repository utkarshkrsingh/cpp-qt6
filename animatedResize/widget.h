#ifndef WIDGET_H
#define WIDGET_H

#include <QtWidgets/qwidget.h>
#include <QtWidgets/qframe.h>
#include <QtWidgets/qlabel.h>

class Widget:public QWidget {
    Q_OBJECT 

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();;

public slots:
    void tabStatus();

private:
    QFrame *header;
    QFrame *tabBar;
    QFrame *baseFrame;
    QLabel *label;
};

#endif
