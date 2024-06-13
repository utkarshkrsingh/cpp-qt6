#ifndef SPLASH_SCREEN_H
#define SPLASH_SCREEN_H

#include "QtWidgets/qprogressbar.h"
#include <QtWidgets/qwidget.h>
#include "QtCore/qpropertyanimation.h"

class AppSplashScreen:public QWidget {
    Q_OBJECT 

public:
    AppSplashScreen(QWidget *parent = nullptr);
    ~AppSplashScreen();

private:
    QProgressBar *progressBar;
    QPropertyAnimation *animation;
};

#endif
