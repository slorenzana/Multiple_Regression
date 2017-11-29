#include "regre_multi.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Regre_Multi w;
    w.show();

    return a.exec();
}
