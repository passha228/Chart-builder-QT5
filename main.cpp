#include "mainwindow.h"

#include <QApplication>

// точка входа в программу
// здесь мы создаем окно и заставляем его работать
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
