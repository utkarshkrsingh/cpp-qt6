#include "widget.h"
#include "QtCore/qlogging.h"
#include "QtCore/qnamespace.h"
#include "QtCore/qobject.h"
#include "QtCore/qobjectdefs.h"
#include "QtWidgets/qframe.h"
#include "QtWidgets/qboxlayout.h"
#include "QtWidgets/qlayoutitem.h"
#include "QtWidgets/qlineedit.h"
#include "QtWidgets/qpushbutton.h"
#include "QtWidgets/qlabel.h"
#include "QtCore/qdebug.h"

Widget::Widget(QWidget *parent):QWidget(parent) {
    setWindowTitle("Login Page");
    resize(QSize(1200, 800));

    QVBoxLayout *baseLayout = new QVBoxLayout(this);
    setLayout(baseLayout);

    QSpacerItem *vSpacer1 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);
    baseLayout -> addItem(vSpacer1);

    QHBoxLayout *hbox = new QHBoxLayout();
    baseLayout -> addLayout(hbox);

    QSpacerItem *hSpacer1 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);
    hbox -> addItem(hSpacer1);

    QFrame *loginFrame = new QFrame;
    hbox -> addWidget(loginFrame);
    loginFrame -> setMinimumSize(800, 600);
    loginFrame -> setStyleSheet(
        "QFrame {"
        "    background: rgba(0, 0, 0, 0.3);"
        "    border: 1px solid rgba(255, 255, 255, 0.5);"
        "    border-radius: 15px;"
        "}"
    );

    QVBoxLayout *frameVbox = new QVBoxLayout();
    loginFrame -> setLayout(frameVbox);
    frameVbox -> setContentsMargins(100, 50, 100, 100);

    QSpacerItem *framevSpacer1 = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);
    frameVbox -> addItem(framevSpacer1);

    QLabel *loginLabel = new QLabel();
    frameVbox -> addWidget(loginLabel);
    loginLabel -> setText("Login");
    loginLabel -> setMaximumHeight(100);
    loginLabel -> setFont(QFont("Arial", 25));
    loginLabel -> setAlignment(Qt::AlignHCenter | Qt::AlignTop);
    loginLabel -> setStyleSheet(
        "QLabel {"
        "   background-color:rgba(0,0,0,0);"
        "   border-style:none;"
        "   font-weight: 900;"
        "}"
    );
    
    /*
    QLabel *userNameLabel = new QLabel();
    frameVbox -> addWidget(userNameLabel);
    userNameLabel -> setText("Username");
    userNameLabel -> setMinimumHeight(20);
    userNameLabel -> setAlignment(Qt::AlignHCenter | Qt::AlignBottom);
    userNameLabel -> setFont(QFont("Arial", 14));
    userNameLabel -> setStyleSheet(
        "QLabel {"
        "   background-color:rgba(0,0,0,0);"
        "   border-style:none;"
        "   font-weight:500;"
        "}"
    );
    */

    userNameLineEdit = new QLineEdit();
    frameVbox -> addWidget(userNameLineEdit);
    userNameLineEdit -> setFont(QFont("FreeSans", 18));
    userNameLineEdit -> setPlaceholderText("Username");
    userNameLineEdit -> setAlignment(Qt::AlignHCenter);
    userNameLineEdit -> clearFocus();
    userNameLineEdit -> setStyleSheet(
        "QLineEdit {"
        "   border-style:none;"
        "   background-color:white;"
        "   color: black;"
        "   border-radius: 5px"
        "}"
    );

    /*
    QLabel *passWordLabel = new QLabel();
    frameVbox -> addWidget(passWordLabel);
    passWordLabel -> setText("Password");
    passWordLabel -> setMinimumHeight(20);
    passWordLabel -> setAlignment(Qt::AlignHCenter | Qt::AlignBottom);
    passWordLabel -> setFont(QFont("Arial", 14));
    passWordLabel -> setStyleSheet(
        "QLabel {"
        "   background-color:rgba(0,0,0,0);"
        "   border-style:none;"
        "   font-weight:500;"
        "}"
    );
    */

    passWordLineEdit = new QLineEdit();
    frameVbox -> addWidget(passWordLineEdit);
    passWordLineEdit -> setPlaceholderText("Password");
    passWordLineEdit -> setFont(QFont("FreeSans", 18));
    passWordLineEdit -> setEchoMode(QLineEdit::EchoMode::Password);
    passWordLineEdit -> setAlignment(Qt::AlignHCenter);
    passWordLineEdit -> clearFocus();
    passWordLineEdit -> setStyleSheet(
        "QLineEdit {"
        "   border-style:none;"
        "   background-color:white;"
        "   color: black;"
        "   border-radius: 5px"
        "}"
    );

    QPushButton *loginButton = new QPushButton();
    frameVbox -> addWidget(loginButton);
    connect(loginButton, SIGNAL(clicked()), SLOT(printUerInfo()));
    loginButton -> setText("Login");
    loginButton -> setFont(QFont("Arial", 18));
    loginButton -> setStyleSheet(
        "QPushButton {"
        "   border-style:none;"
        "   padding-bottom: 3px;"
        "   border-radius:5px;"
        "   color:white;"
        "   background-color:rgb(0, 166, 255);"
        "}"
        "QPushButton:hover {"
        "   color:rgb(0, 166, 255);"
        "   background-color:white;"
        "}"
        "QPushButton:pressed {"
        "   color:white;"
        "   background-color:rgb(6, 199, 67);"
        "}"
    );

    QPushButton *createAccountLabel = new QPushButton();
    frameVbox -> addWidget(createAccountLabel);
    connect(createAccountLabel, SIGNAL(clicked()), SLOT(createUserAccount()));
    createAccountLabel -> setText("Create an account");
    createAccountLabel -> setFont(QFont("Arial", 14));
    createAccountLabel -> setStyleSheet(
        "QPushButton {"
        "   border-style:none;"
        "   background-color:rgba(0,0,0,0);"
        "}"
        "QPushButton:hover {"
        "   color:rgb(0, 119, 255);"
        "}"
        "QPushButton:pressed {"
        "   color:rgb(6, 199, 67);"
        "}"
    );
    

    QSpacerItem *framevSpacer2 = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);
    frameVbox -> addItem(framevSpacer2);

    QSpacerItem *hSpacer2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);
    hbox -> addItem(hSpacer2);

    QSpacerItem *vSpacer2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);
    baseLayout -> addItem(vSpacer2);
};

Widget::~Widget(){}

void Widget::printUerInfo() {
    QString userName = userNameLineEdit -> text();
    QString passWord = passWordLineEdit -> text();
    userNameLineEdit -> setText("");
    passWordLineEdit -> setText("");
    qDebug() << "Username : " << userName;
    qDebug() << "Password : " << passWord;
}

void Widget::createUserAccount() {
    qDebug() << "Redirecting to sign-up page";
}
