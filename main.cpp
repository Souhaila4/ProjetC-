#include "mainwindow.h"
#include "clientcontroller.h"
#include "connection.h"
#include <QApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Connection *db = new Connection();
    bool isOpen = db->createConnection();
    if(isOpen){
        qDebug() << "DB open";
    } else {
        qDebug() << "DB NOT open";
    }

    MainWindow w;
    ClientController c;
    c.show();
    return a.exec();
}
