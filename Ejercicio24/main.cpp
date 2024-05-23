#include "htmlparser.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    htmlparser w;
    w.show();
    return a.exec();
}
