#include "widget.h"
#include <QtWidgets/qlabel.h>
#include <QtWidgets/qboxlayout.h>
#include <QtGui/qmovie.h>

Widget::Widget(QWidget *parent):QWidget(parent){
    setWindowTitle("QLabel Example");
    resize(1000, 800);

    QVBoxLayout *vbox = new QVBoxLayout(this);
    setLayout(vbox);

    QLabel *label = new QLabel(this);
    label -> resize(900, 600);
    label -> setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    vbox -> addWidget(label);
    /*
    label -> setText("Hello, World!");
    label -> move(100,100);
    label -> setFont(QFont("JetBrainsMono Nerd Font", 24));
    label -> setStyleSheet("color:red;");
    */
    
    /* Adding image to QLabel
    label -> resize(900, 600);
    label -> setPixmap(QPixmap("image.png"));
    */

    // Adding gif image
    QMovie *movie = new QMovie("example-gif.gif");
    label -> setMovie(movie);
    movie -> start();

}
Widget::~Widget(){}
