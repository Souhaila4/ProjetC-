#include "mainwindow.h"
#include "clientcontroller.h"
#include "connection.h"
#include <QApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    Connection *db = new Connection();
    ClientController c;
    bool isOpen = db->createConnection();
    if(isOpen){
        qDebug() << "DB open";
    } else {
        qDebug() << "DB NOT open";
    }
    c.show();
    return a.exec();
}
