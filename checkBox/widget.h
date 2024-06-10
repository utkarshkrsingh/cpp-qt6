#ifndef WIDGET_H
#define WIDGET_H

#include <QtWidgets/qwidget.h>
#include <QtWidgets/qcheckbox.h>
#include <QtWidgets/qlabel.h>

class Widget:public QWidget {
    Q_OBJECT 

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

public slots:
    void changeCheck();

private:
    QLabel *questionLabel;
    QLabel *selectedOptionLabel;
    QCheckBox *option1;
    QCheckBox *option2;
    QCheckBox *option3;

};

#endif
