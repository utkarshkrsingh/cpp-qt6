#include "mainwindow.h"
#include <QtWidgets/qapplication.h>

int main(int argc, char *argv[]){
    QApplication app(argc, argv);
    MainWindow win;
    win.show();
    return app.exec();
}
