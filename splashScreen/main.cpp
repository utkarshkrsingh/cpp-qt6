#include "splashScreen.h"
#include "widget.h"
#include "QtWidgets/qapplication.h"
#include "QtCore/qtimer.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    AppSplashScreen splashScreen;
    splashScreen.show();

    QTimer::singleShot(6000, [&]() {
        splashScreen.close();
        Widget *mainWindow = new Widget();
        mainWindow->setAttribute(Qt::WA_DeleteOnClose);
        mainWindow->show();
    });

    return app.exec();
}
