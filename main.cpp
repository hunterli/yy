#include <QtGui/QApplication>
#include <QLocale>
#include <QTranslator>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QString locale = QLocale::system().name();

    QTranslator t;
    t.load(QString("yy_")+locale);
    a.installTranslator(&t);
    MainWindow w;
    w.show();

    return a.exec();
}
