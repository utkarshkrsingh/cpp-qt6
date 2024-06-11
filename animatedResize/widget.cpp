#include "widget.h"
#include "QtCore/qobjectdefs.h"
#include "QtWidgets/qboxlayout.h"
#include "QtWidgets/qlayoutitem.h"
#include "QtWidgets/qframe.h"
#include "QtWidgets/qlabel.h"
#include "QtWidgets/qpushbutton.h"
#include "QtCore/qpropertyanimation.h"

Widget::Widget(QWidget *parent):QWidget(parent){
    setWindowTitle("Animated Tab");
    resize(1000,800);
    setStyleSheet("background-color:rgb(30, 30, 46);");

    QVBoxLayout *baseLayout = new QVBoxLayout(this);
    setLayout(baseLayout);
    baseLayout -> setSpacing(0);
    baseLayout -> setContentsMargins(0, 0, 0, 0);

    header = new QFrame();
    header -> setMaximumHeight(60);
    header -> setStyleSheet("background-color:rgb(17, 17, 27)");
    baseLayout -> addWidget(header);

    QHBoxLayout *headerHBox = new QHBoxLayout(header);
    headerHBox -> setSpacing(5);
    headerHBox -> setContentsMargins(5, 10, 5, 10);

    QPushButton *menuButton = new QPushButton();
    menuButton -> setMaximumSize(70, 40);
    menuButton -> setIcon(QIcon("icons/menu-icon.png"));
    menuButton -> setIconSize(QSize(28,28));
    headerHBox -> addWidget(menuButton);
    connect(menuButton, SIGNAL(clicked()), this, SLOT(tabStatus()));
    menuButton -> setStyleSheet(
        "QPushButton {"
        "   background-color:rgb(30, 30, 46);"
        "   color:white;"
        "   border-style:solid;"
        "   border-radius: 5px;"
        "}"
        "QPushButton:hover {"
        "   background-color:rgb(17, 17, 27);"
        "}"
        "QPushButton:pressed {"
        "background-color:rgb(108, 112, 134);"
        "}"
    );

    QPushButton *homeButton = new QPushButton();
    homeButton -> setIcon(QIcon("icons/home-icon.png"));
    homeButton -> setIconSize(QSize(28,28));
    homeButton -> setMaximumSize(70, 40);
    headerHBox -> addWidget(homeButton);
    homeButton -> setStyleSheet(
        "QPushButton {"
        "   background-color:rgb(30, 30, 46);"
        "   color:white;"
        "   border-style:solid;"
        "   border-radius: 5px;"
        "}"
        "QPushButton:hover {"
        "   background-color:rgb(17, 17, 27);"
        "}"
        "QPushButton:pressed {"
        "background-color:rgb(108, 112, 134);"
        "}"
    );

    QPushButton *saveButton = new QPushButton();
    saveButton -> setIcon(QIcon("icons/save-icon.png"));
    saveButton -> setIconSize(QSize(28,28));
    saveButton -> setMaximumSize(70, 40);
    headerHBox -> addWidget(saveButton);
    saveButton -> setStyleSheet(
        "QPushButton {"
        "   background-color:rgb(30, 30, 46);"
        "   color:white;"
        "   border-style:solid;"
        "   border-radius: 5px;"
        "}"
        "QPushButton:hover {"
        "   background-color:rgb(17, 17, 27);"
        "}"
        "QPushButton:pressed {"
        "background-color:rgb(108, 112, 134);"
        "}"
    );

    QPushButton *notiButton = new QPushButton();
    notiButton -> setIcon(QIcon("icons/notification-icon.png"));
    notiButton -> setIconSize(QSize(28,28));
    notiButton -> setMaximumSize(70, 40);
    headerHBox -> addWidget(notiButton);
    notiButton -> setStyleSheet(
        "QPushButton {"
        "   background-color:rgb(30, 30, 46);"
        "   color:white;"
        "   border-style:solid;"
        "   border-radius: 5px;"
        "}"
        "QPushButton:hover {"
        "   background-color:rgb(17, 17, 27);"
        "}"
        "QPushButton:pressed {"
        "background-color:rgb(108, 112, 134);"
        "}"
    );

    QFrame *headerRightFrame = new QFrame();
    headerHBox -> addWidget(headerRightFrame);

    QHBoxLayout *hbox = new QHBoxLayout();
    baseLayout -> addLayout(hbox);

    tabBar = new QFrame();
    tabBar -> setMaximumWidth(75);
    tabBar -> setStyleSheet("background-color:rgb(17, 17, 27)");
    hbox -> addWidget(tabBar);

    baseFrame = new QFrame();
    hbox -> addWidget(baseFrame);

    QVBoxLayout *baseFrameHBox = new QVBoxLayout(baseFrame);

    label = new QLabel();
    label -> setText("Hello, Qt6");
    label -> setFont(QFont("Arial", 16));
    label -> setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    baseFrameHBox -> addWidget(label);
}
Widget::~Widget(){}

void Widget::tabStatus() {
    int maxWidth = tabBar->maximumWidth();
    //int newMaxWidth = (maxWidth == 75) ? 200 : 75;
    //tabBar->setMaximumWidth(newMaxWidth);
    int newMaxWidth;
    if (maxWidth < 100) {
        newMaxWidth = 200;
        label -> setText("Tab Expanded!");
    }
    else {
        newMaxWidth = 75;
        label -> setText("Tab Collapsed!");
    }

    QPropertyAnimation *animation = new QPropertyAnimation(tabBar, "maximumWidth");
    animation->setDuration(150);
    animation->setStartValue(maxWidth);
    animation->setEndValue(newMaxWidth);
    animation->start(QPropertyAnimation::DeleteWhenStopped);
}
