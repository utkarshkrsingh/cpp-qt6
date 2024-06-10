#include "widget.h"
#include <QtWidgets/qlineedit.h>
#include <QtWidgets/qboxlayout.h>

Widget::Widget(QWidget *parent):QWidget(parent) {
    setWindowTitle("QLineEdit Example");
    resize(1000,800);

    QVBoxLayout *vbox = new QVBoxLayout(this);
    setLayout(vbox);

    QLineEdit *lineEdit = new QLineEdit(this);
    vbox -> addWidget(lineEdit);
    lineEdit -> setPlaceholderText("Enter Line");
    lineEdit -> setEchoMode(QLineEdit::EchoMode::Password);
    lineEdit -> setFont(QFont("Arial", 24));
}

Widget::~Widget(){}
