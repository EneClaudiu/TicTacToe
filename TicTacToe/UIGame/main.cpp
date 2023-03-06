#include "UIGame.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    UIGame w;
    w.show();
    return a.exec();
}
