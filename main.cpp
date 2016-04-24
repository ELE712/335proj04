#include "databaseform.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    DatabaseForm w;
    w.show();

    return a.exec();
}
