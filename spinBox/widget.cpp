#include "widget.h"
#include "QtCore/qobject.h"
#include "QtCore/qobjectdefs.h"
#include "QtWidgets/qboxlayout.h"
#include "QtWidgets/qlabel.h"

Widget::Widget(QWidget *parent):QWidget(parent) {
    setWindowTitle("QSpinBox");
    QHBoxLayout *baseLayout = new QHBoxLayout(this);
    setLayout(baseLayout);

    QLabel *label = new QLabel();
    label -> setText("Laptop Price : ");
    label -> setFont(QFont("Arial", 16));
    baseLayout -> addWidget(label);

    priceLineEidt = new QLineEdit();
    priceLineEidt -> setFont(QFont("Arial", 16));
    baseLayout -> addWidget(priceLineEidt);

    spinBox = new QSpinBox();
    spinBox -> setFont(QFont("Arial", 16));
    connect(spinBox, SIGNAL(valueChanged(int)), SLOT(totalPrice()));
    baseLayout -> addWidget(spinBox);

    totalLineEdit = new QLineEdit();
    totalLineEdit -> setFont(QFont("Arial", 16));
    baseLayout -> addWidget(totalLineEdit);
}
Widget::~Widget(){}

void Widget::totalPrice() {
    int myPrice = priceLineEidt -> text().toInt();
    int totalPrice = myPrice * spinBox -> value();
    totalLineEdit -> setText(QString::number(totalPrice));
}
