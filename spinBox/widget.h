#ifndef WIDGET_H
#define WIDGET_H

#include <QtWidgets/qwidget.h>
#include <QtWidgets/qlineedit.h>
#include <QtWidgets/qspinbox.h>

class Widget:public QWidget {
    Q_OBJECT 

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

public slots:
    void totalPrice();

private:
    QLineEdit *priceLineEidt;
    QLineEdit *totalLineEdit;
    QSpinBox *spinBox;

};

#endif
