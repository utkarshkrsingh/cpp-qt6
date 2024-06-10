#include "widget.h"
#include "QtCore/qobject.h"
#include "QtCore/qobjectdefs.h"
#include "QtWidgets/qboxlayout.h"
#include "QtWidgets/qlabel.h"
#include "QtWidgets/qlayoutitem.h"

Widget::Widget(QWidget *parent):QWidget(parent) {
    setWindowTitle("QCheckBox");
    resize(1000,800);
    QVBoxLayout *baseLayout = new QVBoxLayout(this);
    setLayout(baseLayout);

    QSpacerItem *vSpacer1 = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);
    baseLayout -> addItem(vSpacer1);

    questionLabel = new QLabel();
    baseLayout -> addWidget(questionLabel);
    questionLabel -> setText("Q. What language are you learning ?");
    questionLabel -> setFont(QFont("Arial", 20));
    questionLabel -> setStyleSheet(
        "QLabel {"
        "   border-style:none;"
        "   font-weight:500;"
        "}"
    );

    QHBoxLayout *answersLayout = new QHBoxLayout();
    baseLayout -> addLayout(answersLayout);

    option1 = new QCheckBox();
    answersLayout -> addWidget(option1);
    option1 -> setText(" Rust");
    option1 -> setFont(QFont("Arial", 16));
    option1 -> setIcon(QIcon("images/rust-icon.png"));
    option1 -> setIconSize(QSize(32,32));
    option1 -> setStyleSheet("color:white;");
    connect(option1, SIGNAL(stateChanged(int)), SLOT(changeCheck()));

    option2 = new QCheckBox();
    answersLayout -> addWidget(option2);
    option2 -> setText(" Go");
    option2 -> setFont(QFont("Arial", 16));
    option2 -> setIcon(QIcon("images/golang-icon.png"));
    option2 -> setIconSize(QSize(32,32));
    option2 -> setStyleSheet("color:white;");
    connect(option2, SIGNAL(stateChanged(int)), SLOT(changeCheck()));

    option3 = new QCheckBox();
    answersLayout -> addWidget(option3);
    option3 -> setText(" C++");
    option3 -> setFont(QFont("Arial", 16));
    option3 -> setIcon(QIcon("images/cpp-icon.png"));
    option3 -> setIconSize(QSize(32,32));
    option3 -> setStyleSheet("color:white;");
    connect(option3, SIGNAL(stateChanged(int)), SLOT(changeCheck()));

    selectedOptionLabel = new QLabel();
    baseLayout -> addWidget(selectedOptionLabel);
    selectedOptionLabel -> setText("");
    selectedOptionLabel -> setFont(QFont("Arial", 16));
    selectedOptionLabel -> setStyleSheet("color:white;");

    QSpacerItem *vSpacer2 = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);
    baseLayout -> addItem(vSpacer2);
}

Widget::~Widget(){}

void Widget::changeCheck() {
    QString value = "";
    if (option1 -> isChecked()) {
        value = option1 -> text();
    }
    if (option2 -> isChecked()) {
        value = option2 -> text();
    }
    if (option3 -> isChecked()) {
        value = option3 -> text();
    }

    selectedOptionLabel -> setText("You have selected : " + value);
}
