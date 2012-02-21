#include <QtCore/QCoreApplication>
#include "cperceptron.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    CPerceptron *cp = new CPerceptron("/home/mdecky/Projects/NS/NS/t1r.txt");
    cp->loadFromFile();
    printf("kuk");
    delete cp;
    return a.exec();
}
