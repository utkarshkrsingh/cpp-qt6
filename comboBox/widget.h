#ifndef WIDGET_H
#define WIDGET_H

#include <QtWidgets/qwidget.h>
#include <QtWidgets/qcombobox.h>
#include <QtWidgets/qlabel.h>

class Widget:public QWidget {
    Q_OBJECT 

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

public slots:
    void changeComboBox();

private:
    QComboBox *comboBox;
    QLabel *labelResult;
};

#endif
