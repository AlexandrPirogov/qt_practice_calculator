#include "mainwindow.h"

#include <QtWidgets>
#include "calculator.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    Calculator* c = new Calculator();
    c->setWindowTitle("Simple Calculator");
    c->show();
    return app.exec();
}
