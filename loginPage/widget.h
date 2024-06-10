#ifndef WIDGET_H
#define WIDGET_H

#include "QtWidgets/qlineedit.h"
#include <QtWidgets/qwidget.h>

class Widget:public QWidget {
    Q_OBJECT 

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    QLineEdit *userNameLineEdit;
    QLineEdit *passWordLineEdit;

public slots:
    void printUerInfo();
    void createUserAccount();
};

#endif
