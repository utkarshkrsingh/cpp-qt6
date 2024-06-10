#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "QtWidgets/qwidget.h"
#include <QtWidgets/qmainwindow.h>

class MainWindow:public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
};

#endif // MAINWINDOW_H
