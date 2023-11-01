#include "cliententity.h"
#include <QDebug>

CLIENT::CLIENT()
{

}
CLIENT::CLIENT(int ID_CLIENT,QString NOM,QString COURREIL,QString ADRESSE,QDate DATE_INSCIPTION,QString PT_VENTE,QString PT_LOCATION)
{
    this->ID_CLIENT=ID_CLIENT;
    this->NOM=NOM;
    this->COURREIL=COURREIL;
    this->ADRESSE=ADRESSE;
    this->DATE_INSCIPTION=DATE_INSCIPTION;
    this->PT_VENTE=PT_VENTE;
    this->PT_LOCATION=PT_LOCATION;
}
CLIENT::CLIENT(QString NOM,QString COURREIL,QString ADRESSE,QDate DATE_INSCIPTION,QString PT_VENTE,QString PT_LOCATION)
{
    this->NOM=NOM;
    this->COURREIL=COURREIL;
    this->ADRESSE=ADRESSE;
    this->DATE_INSCIPTION=DATE_INSCIPTION;
    this->PT_VENTE=PT_VENTE;
    this->PT_LOCATION=PT_LOCATION;


}
bool CLIENT::ajouter()
{

    QSqlQuery query(QSqlDatabase::database());

    QString res = QString::number(ID_CLIENT);

    query.prepare("insert into SYSTEM.CLIENT(nom,courriel,adresse,date_insciption,pt_vente,pt_location) values(:NOM,:COURREIL,:ADRESSE,:DATE_INSCIPTION,:PT_VENTE,:PT_LOCATION)");


    query.bindValue(":NOM",NOM);
    query.bindValue(":COURREIL",COURREIL);
    query.bindValue(":ADRESSE",ADRESSE);
    query.bindValue(":DATE_INSCIPTION",QString::number(DATE_INSCIPTION.day())+"/"+ QString::number(DATE_INSCIPTION.month())+"/" + QString::number(DATE_INSCIPTION.year()));
    query.bindValue(":PT_VENTE",PT_VENTE);
    query.bindValue(":PT_LOCATION",PT_LOCATION);

    return query.exec();

}

bool CLIENT::modifier()
{

    QSqlQuery query(QSqlDatabase::database());

    QString res = QString::number(ID_CLIENT);

    query.prepare("UPDATE SYSTEM.CLIENT SET nom=:NOM,courriel=:COURREIL,adresse=:ADRESSE,date_insciption=:DATE_INSCIPTION,pt_vente=:PT_VENTE,pt_location=:PT_LOCATION WHERE id_client=:ID_CLIENT");

    query.bindValue(":ID_CLIENT",res);
    query.bindValue(":NOM",NOM);
    query.bindValue(":COURREIL",COURREIL);
    query.bindValue(":ADRESSE",ADRESSE);
    query.bindValue(":DATE_INSCIPTION",QString::number(DATE_INSCIPTION.day())+"/"+ QString::number(DATE_INSCIPTION.month())+"/" + QString::number(DATE_INSCIPTION.year()));
    query.bindValue(":PT_VENTE",PT_VENTE);
    query.bindValue(":PT_LOCATION",PT_LOCATION);

    return query.exec();

}



QSqlQueryModel * CLIENT::afficher()
{
    QSqlQueryModel * model=new QSqlQueryModel();

    model->setQuery("select * from CLIENT");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID_CLIENT"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("NOM"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("COURREIL"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("ADRESSE"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("DATE_INSCIPTION"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("PT_VENTE"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("PT_LOCATION"));
    return model;

}
bool CLIENT::supprimer(int ID_CLIENT)
{
    QSqlQuery query;
    QString res=QString::number(ID_CLIENT);

    query.prepare("Delete from CLIENT where ID_CLIENT= :ID_CLIENT");
    query.bindValue(":ID_CLIENT",res);

    return query.exec();
}
