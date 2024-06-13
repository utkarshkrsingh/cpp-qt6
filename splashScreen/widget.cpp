#include "widget.h"
#include "QtCore/qnamespace.h"
#include "QtWidgets/QApplication"
#include "QtWidgets/qboxlayout.h"
#include "QtWidgets/qlabel.h"
#include "QtGui/qscreen.h"

Widget::Widget(QWidget *parent):QWidget(parent){
    setWindowTitle("Main WIndow");
    QScreen *screen = QApplication::primaryScreen();
    QRect screenGeometry = screen->availableGeometry();
    setGeometry(screenGeometry);
    setStyleSheet("background-color: rgb(55, 38, 93);");

    QVBoxLayout *baseLayout = new QVBoxLayout(this);
    setLayout(baseLayout);

    QLabel *label = new QLabel();
    label -> setText(QCoreApplication::translate("parent", "<strong>WELCOME TO</strong> MAIN WINDOW"));
    label -> setFont(QFont("JetBrainsMono Nerd Font", 32));
    label -> setAlignment(Qt::AlignVCenter | Qt::AlignHCenter);
    label -> setStyleSheet("color: rgb(192, 97, 203);");
    baseLayout -> addWidget(label);
}
Widget::~Widget(){}
