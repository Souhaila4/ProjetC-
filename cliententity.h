#ifndef CLIENTENTITY_H
#define CLIENTENTITY_H
#include <QString>
#include <QDate>
#include<QSqlQuery>
#include <QSqlDatabase>
#include<QSqlQueryModel>


class CLIENT
{
    QDate DATE_INSCIPTION;
    QString NOM,COURREIL,ADRESSE,PT_VENTE,PT_LOCATION;
    int ID_CLIENT;
public:
    CLIENT();
    CLIENT(int,QString,QString,QString,QDate,QString,QString);
    CLIENT(QString,QString,QString,QDate,QString,QString);
    QString getNOM(){return NOM;}
    QString getCOURREIL(){return COURREIL;}
    QString getADRESSE(){return ADRESSE;}
    QDate getDATE_INSCIPTION(){return DATE_INSCIPTION;}
    QString getPT_VENTE(){return PT_VENTE;}
    QString getPT_LOCATION(){return PT_LOCATION;}
    int getID_CLIENT(){return ID_CLIENT;}

    void setNOM(QString n){NOM=n;}
    void setCOURRIEL(QString c){COURREIL=c;}
    void setADRESSE(QString a){ADRESSE=a;}
    void setDATE_INSCIPTION(QDate d){DATE_INSCIPTION=d;}
    void setPT_VENTE(QString ptv){PT_VENTE=ptv;}
    void setPT_LOCATION(QString ptl){PT_LOCATION=ptl;}

    void setID_CLIENT(int ID_CLIENT){this->ID_CLIENT=ID_CLIENT;}

    bool ajouter();
    bool modifier();
    QSqlQueryModel * afficher();
    bool supprimer(int);
};

#endif // CLIENTENTITY_H
