#ifndef WIDGET_H
#define WIDGET_H

#include <QtWidgets/qwidget.h>

class Widget:public QWidget {
    Q_OBJECT 

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();;

};

#endif
