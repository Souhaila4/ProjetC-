#include "connection.h"
#include "QDebug"


bool Connection::createConnection(){
    db = QSqlDatabase::addDatabase("QODBC");
    bool test=false;
    db.setDatabaseName("Source_Project2A");
    db.setUserName("Souhaila");//inserer nom de l'utilisateur
    db.setPassword("esprit23");//inserer mot de passe de cet utilisateur

    if (db.open())
        test=true;

    return  test;
}

void Connection::closeConnection(){
    db.close();
}
