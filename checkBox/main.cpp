#include "widget.h"
#include <QtWidgets/qapplication.h>

int main(int argc, char * argv[]) {
    QApplication app(argc, argv);
    Widget win;
    win.show();
    return app.exec();
}
