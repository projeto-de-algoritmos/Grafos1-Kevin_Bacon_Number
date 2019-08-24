#include "window.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    window tela;
    tela.resize(900, 420);
    tela.setWindowTitle("Projeto de Algoritmos - Lista 1");
    tela.show();
    return app.exec();
}
