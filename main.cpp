/*
* =======================
* Inlämnings_uppgift_del5
* kalkylatorn
* Kursprogram i C++
* Handledare: Gladyz Pabon
* Datum:  2018-03-09
* @auktor: Amer Ahmed
*========================
*/

#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
