#include "widget.h"
#include "QtCore/qnamespace.h"
#include "QtCore/qobjectdefs.h"
#include "QtWidgets/qboxlayout.h"
#include "QtWidgets/qlabel.h"

Widget::Widget(QWidget *parent):QWidget(parent){
    setWindowTitle("QComboBox");
    resize(500, 100);

    QVBoxLayout *baseLayout = new QVBoxLayout(this);
    setLayout(baseLayout);

    QHBoxLayout *selectComponentLayout = new QHBoxLayout();
    baseLayout -> addLayout(selectComponentLayout);

    QLabel *label = new QLabel();
    label -> setText("Select Account Type : ");
    label -> setFont(QFont("Arial", 18));
    selectComponentLayout -> addWidget(label);

    comboBox = new QComboBox();
    comboBox -> setFont(QFont("Arial", 18));
    comboBox -> addItem("Current Account");
    comboBox -> addItem("Deposit Account");
    comboBox -> addItem("Saving Account");
    connect(comboBox, SIGNAL(currentTextChanged(QString)), SLOT(changeComboBox()));
    selectComponentLayout -> addWidget(comboBox);

    labelResult = new QLabel();
    labelResult -> setText("");
    labelResult -> setFont(QFont("Arial", 18));
    labelResult -> setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    baseLayout -> addWidget(labelResult);
    
}
Widget::~Widget(){}

void Widget::changeComboBox() {
    QString item = comboBox -> currentText();
    labelResult -> setText("Your Account Type is : " + item);
}
