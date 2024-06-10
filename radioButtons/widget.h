#ifndef WIDGET_H
#define WIDGET_H

#include "QtCore/qmath.h"
#include <QtWidgets/qwidget.h>
#include <QtWidgets/qradiobutton.h>
#include <QtWidgets/qlabel.h>

class Widget:public QWidget {
    Q_OBJECT 

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

public slots:
    void changeRadioButton();

private:
    QLabel *questionLabel;
    QRadioButton *option1;
    QRadioButton *option2;
    QRadioButton *option3;
    QRadioButton *option4;
    QLabel *selectedOptionLabel;
};

#endif
