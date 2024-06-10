#include "widget.h"
#include <QtWidgets/qmenu.h>
#include <QtWidgets/qboxlayout.h>
#include <QtWidgets/qpushbutton.h>

Widget::Widget(QWidget *parent):QWidget(parent) {
    setWindowTitle("QPushButton Example");
    resize(1000, 900);

    QVBoxLayout *vbox = new QVBoxLayout(this);
    setLayout(vbox);

    QPushButton *button = new QPushButton(this);
    button -> setMinimumHeight(100);
    vbox -> addWidget(button);

    button -> setText("Click Me");
    button -> setFont(QFont("Arial", 30));

    QMenu *menu = new QMenu();
    menu -> setFont(QFont("JetBrainsMono Nerd Font", 24));
    menu -> setStyleSheet("background-color:white;\ncolor:black;");
    menu -> addAction("Copy");
    menu -> addAction("Cut");
    menu -> addAction("Paste");
    button -> setMenu(menu);
}

Widget::~Widget(){}
