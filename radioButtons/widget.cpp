#include "widget.h"
#include "QtCore/qobjectdefs.h"
#include "QtWidgets/qboxlayout.h"
#include "QtGui/qicon.h"
#include "QtWidgets/qgridlayout.h"
#include "QtWidgets/qlabel.h"
#include "QtWidgets/qlayoutitem.h"

Widget::Widget(QWidget *parent):QWidget(parent) {
    setWindowTitle("QRadioButton");
    resize(1000,800);
    QVBoxLayout *baseLayout = new  QVBoxLayout(this);
    setLayout(baseLayout);

    QSpacerItem *vSpacer1 = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);
    baseLayout -> addItem(vSpacer1);

    questionLabel = new QLabel();
    baseLayout -> addWidget(questionLabel);
    questionLabel -> setText("Q. What Language You Are Learning ?");
    questionLabel -> setFont(QFont("Arial", 18));
    questionLabel -> setAlignment(Qt::AlignLeft | Qt::AlignBottom);
    questionLabel -> setStyleSheet(
        "QLabel {"
        "   border-style:none;"
        "   color:white;"
        "   font-weight:500;"
        "}"
    );

    QGridLayout *optionForm = new QGridLayout();
    baseLayout -> addLayout(optionForm);

    option1 = new QRadioButton();
    optionForm -> addWidget(option1, 0, 0);
    option1 -> setText(" C++");
    option1 -> setFont(QFont("Arial", 14));
    option1 -> setIcon(QIcon("icons/cpp-icon.png"));
    option1 -> setIconSize(QSize(40, 40));
    connect(option1, SIGNAL(toggled(bool)), SLOT(changeRadioButton()));

    option2 = new QRadioButton();
    optionForm -> addWidget(option2, 0, 1);
    option2 -> setText(" C");
    option2 -> setFont(QFont("Arial", 14));
    option2 -> setIcon(QIcon("icons/c-icon.png"));
    option2 -> setIconSize(QSize(40, 40));
    connect(option2, SIGNAL(toggled(bool)), SLOT(changeRadioButton()));

    option3 = new QRadioButton();
    optionForm -> addWidget(option3, 1, 0);
    option3 -> setText(" Java");
    option3 -> setFont(QFont("Arial", 14));
    option3 -> setIcon(QIcon("icons/java-icon.png"));
    option3 -> setIconSize(QSize(40, 40));
    connect(option3, SIGNAL(toggled(bool)), SLOT(changeRadioButton()));

    option4 = new QRadioButton();
    optionForm -> addWidget(option4, 1, 1);
    option4 -> setText(" Python");
    option4 -> setFont(QFont("Arial", 14));
    option4 -> setIcon(QIcon("icons/python-icon.png"));
    option4 -> setIconSize(QSize(40, 40));
    connect(option4, SIGNAL(toggled(bool)), SLOT(changeRadioButton()));

    selectedOptionLabel = new QLabel();
    baseLayout -> addWidget(selectedOptionLabel);
    selectedOptionLabel -> setText("");
    selectedOptionLabel -> setFont(QFont("Arial", 14));
    selectedOptionLabel -> setStyleSheet(
        "QLabel {"
        "   border-style:none;"
        "   color:white;"
        "}"
    );

    QSpacerItem *vSpacer2 = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);
    baseLayout -> addItem(vSpacer2);
}

Widget::~Widget(){}

void Widget::changeRadioButton() {
    if (option1 -> isChecked()) {
        selectedOptionLabel -> setText("C++ Selected !");
    }
    if (option2 -> isChecked()) {
        selectedOptionLabel -> setText("C Selected !");
    }
    if (option3 -> isChecked()) {
        selectedOptionLabel -> setText("Java Selected !");
    }
    if (option4 -> isChecked()) {
        selectedOptionLabel -> setText("Python Selected !");
    }
}
