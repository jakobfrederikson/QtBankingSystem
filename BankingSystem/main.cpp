#include "loginwindow.h"
#include "system.h"
#include <QDebug>
#include <QApplication>
#include <QFontDatabase>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    System::CreateFiles();

    QFontDatabase::addApplicationFont(":/fonts/BebasNeue-Regular.ttf");

    LoginWindow l;
    l.setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    l.show();
    return a.exec();
}
