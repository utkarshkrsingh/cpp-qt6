#include "splashScreen.h"
#include "QtCore/qcoreapplication.h"
#include "QtCore/qnamespace.h"
#include "QtCore/qobjectdefs.h"
#include "QtCore/qvariant.h"
#include "QtWidgets/qboxlayout.h"
#include "QtWidgets/qgraphicseffect.h"
#include "QtWidgets/qlabel.h"
#include "QtWidgets/qprogressbar.h"
#include "QtWidgets/qframe.h"

AppSplashScreen::AppSplashScreen(QWidget *parent):QWidget(parent){
    resize(800,400);
    setWindowFlag(Qt::FramelessWindowHint);
    setAttribute(Qt::WA_TranslucentBackground);
    setWindowOpacity(0.0);

    QVBoxLayout *baseLayout = new QVBoxLayout(this);
    baseLayout -> setContentsMargins(0, 0, 0, 0);
    setLayout(baseLayout);

    QFrame *mainBackground = new QFrame();
    baseLayout -> addWidget(mainBackground);
    mainBackground -> setStyleSheet(
        "QFrame {"
        "   background-color: rgb(55, 38, 93);"
        "   border-style:none;"
        "   border-radius:10px;"
        "}"
    );
    // Drop Shadow
    QGraphicsDropShadowEffect *shadow = new QGraphicsDropShadowEffect(mainBackground);
    shadow -> setBlurRadius(20);
    shadow -> setXOffset(0);
    shadow -> setYOffset(0);
    shadow -> setColor(QColor(0, 0, 0, 60));
    mainBackground -> setGraphicsEffect(shadow);

    QLabel *appName = new QLabel(mainBackground);
    appName -> setGeometry(QRect(0, 90, 801, 61));
    appName -> setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    appName -> setFont(QFont("JetBrainsMono Nerd Font", 32));
    appName -> setText(QCoreApplication::translate("parent" ,"<strong>YOUR</strong> APP NAME"));
    appName -> setStyleSheet(
        "QLabel {"
        "   color: rgb(192, 97, 203);\n"
        "}"
    );

    QLabel *appDesc = new QLabel(mainBackground);
    appDesc -> setGeometry(QRect(0, 140, 801, 31));
    appDesc -> setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    appDesc -> setFont(QFont("JetBrainsMono Nerd Font", 16));
    appDesc -> setText(QCoreApplication::translate("parent", "<strong>APP</strong> DESCRIPTION"));
    appDesc -> setStyleSheet(
        "QLabel {"
        "   color: rgb(98, 73, 140);"
        "}"
    );

    progressBar = new QProgressBar(mainBackground);
    progressBar -> setGeometry(QRect(100, 290, 601, 23));
    progressBar -> setFont(QFont("JetBrainsMono Nerd Font", 11));
    progressBar -> setValue(0);
    progressBar -> setStyleSheet(
        "QProgressBar {"
        "	background-color: rgb(98, 73, 140);\n"
        "	color: rgb(200, 200, 200);\n"
        "	border-style:none;\n"
        "	border-radius: 10px;\n"
        "	text-align:center;\n"
        "}"
        ""
        "QProgressBar::chunk {"
        "	border-radius:10px;"
        "	background-color: qlineargradient(spread:pad, x1:0, y1:0.5, x2:1, y2:0.489, stop:0 rgba(192, 97, 203, 255), stop:1 rgba(181, 0, 255, 255));"
        "}");

    animation = new QPropertyAnimation(progressBar, "value");
    animation -> setDuration(5000);
    animation -> setStartValue(0);
    animation -> setEndValue(100);
    animation -> start(QPropertyAnimation::DeleteWhenStopped);

    QLabel *loadingLabel = new QLabel(mainBackground);
    loadingLabel -> setText("loading...");
    loadingLabel -> setFont(QFont("JetBrainsMono Nerd Font", 12));
    loadingLabel -> setGeometry(QRect(0, 320, 801, 20));
    loadingLabel -> setStyleSheet("color: rgb(98, 73, 140);");
    loadingLabel -> setAlignment(Qt::AlignVCenter | Qt::AlignHCenter);

    QLabel *creatorName = new QLabel(mainBackground);
    creatorName -> setText(QCoreApplication::translate("parent", "<strong>Created:</strong> Utkarsh Kumar Singh"));
    creatorName -> setGeometry(QRect(0, 350, 795, 20));
    creatorName -> setFont(QFont("JetBrainsMono Nerd Font", 12));
    creatorName -> setAlignment(Qt::AlignRight | Qt::AlignVCenter);
    creatorName -> setStyleSheet("color: rgb(98, 73, 140);");
}
AppSplashScreen::~AppSplashScreen(){}
