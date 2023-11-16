#ifndef FIDELITE_H
#define FIDELITE_H

#include <QString>
#include <QList>
#include <QSqlQuery>
#include <QSqlQueryModel>

class Fidelite
{

private:
    int total;
    double prix;
public:
    Fidelite();
    int getTotal(){return this->total;};
    double getPrix(){return this->prix;};
    void calculerFidelite(QString );
    int getPTSVidelite();


};

#endif // FIDELITE_H
