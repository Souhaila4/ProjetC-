#include "cliententity.h"
#include <QDebug>
#include <iostream>
#include <regex>
#include <QRegularExpression>
#include <QDialog>
#include <QSqlQuery>

CLIENT::CLIENT()
{

}
CLIENT::CLIENT(int ID_CLIENT,QString NOM,QString COURRIEL,QString ADRESSE,QDate DATE_INSCIPTION,QString PT_VENTE,int NUMEROCLIENT)
{
    this->ID_CLIENT=ID_CLIENT;
    this->NOM=NOM;
    this->COURRIEL=COURRIEL;
    this->ADRESSE=ADRESSE;
    this->DATE_INSCIPTION=DATE_INSCIPTION;
    this->PT_VENTE=PT_VENTE;
    this->NUMEROCLIENT=NUMEROCLIENT;
}
CLIENT::CLIENT(QString NOM,QString COURRIEL,QString ADRESSE,QDate DATE_INSCIPTION,QString PT_VENTE,int NUMEROCLIENT)
{
    this->NOM=NOM;
    this->COURRIEL=COURRIEL;
    this->ADRESSE=ADRESSE;
    this->DATE_INSCIPTION=DATE_INSCIPTION;
    this->PT_VENTE=PT_VENTE;
    this->NUMEROCLIENT=NUMEROCLIENT;


}

int CLIENT::getNUMEROCLIENT() const
{
    return this->NUMEROCLIENT;
}

void CLIENT::setPT_VENTE(const QString &ptv)
{
    this->PT_VENTE = ptv;
}


void CLIENT::setID_CLIENT(int idClient)
{
    this->ID_CLIENT=idClient;
}

void CLIENT::setNUMEROCLIENT(int numeroClient)
{
    this->NUMEROCLIENT = numeroClient;
}
bool CLIENT::ajouter()
{

    QSqlQuery query(QSqlDatabase::database());

    QString res = QString::number(ID_CLIENT);

    query.prepare("insert into SYSTEM.CLIENT(nom,courriel,adresse,date_insciption,pt_vente,numeroClient) values(:NOM,:COURRIEL,:ADRESSE,:DATE_INSCIPTION,:PT_VENTE,:NUMEROCLIENT)");

    query.bindValue(":NOM",NOM);
    query.bindValue(":COURRIEL",COURRIEL);
    query.bindValue(":ADRESSE",ADRESSE);
    query.bindValue(":DATE_INSCIPTION",QString::number(DATE_INSCIPTION.day())+"/"+ QString::number(DATE_INSCIPTION.month())+"/" + QString::number(DATE_INSCIPTION.year()));
    query.bindValue(":PT_VENTE",PT_VENTE);
    query.bindValue(":NUMEROCLIENT",NUMEROCLIENT);

    return query.exec();

}

bool CLIENT::modifier()
{

    QSqlQuery query(QSqlDatabase::database());

    QString res = QString::number(ID_CLIENT);

    query.prepare("UPDATE SYSTEM.CLIENT SET nom=:NOM,courriel=:COURRIEL,adresse=:ADRESSE,date_insciption=:DATE_INSCIPTION,pt_vente=:PT_VENTE,numeroClient=:NUMEROCLIENT WHERE id_client=:ID_CLIENT ");

    query.bindValue(":ID_CLIENT",res);
    query.bindValue(":NOM",NOM);
    query.bindValue(":COURRIEL",COURRIEL);
    query.bindValue(":ADRESSE",ADRESSE);
    query.bindValue(":DATE_INSCIPTION",QString::number(DATE_INSCIPTION.day())+"/"+ QString::number(DATE_INSCIPTION.month())+"/" + QString::number(DATE_INSCIPTION.year()));
    query.bindValue(":PT_VENTE",PT_VENTE);
    query.bindValue(":NUMEROCLIENT",NUMEROCLIENT);


    return query.exec();

}



QSqlQueryModel * CLIENT::afficher()
{
    QSqlQueryModel * model=new QSqlQueryModel();

    model->setQuery("select * from CLIENT");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID_CLIENT"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("NOM"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("COURRIEL"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("ADRESSE"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("DATE_INSCIPTION"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("PT_VENTE"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("NUMEROCLIENT"));
    return model;

}
bool CLIENT::supprimer(int ID_CLIENT)
{
    QSqlQuery query;
    QString res=QString::number(ID_CLIENT);

    query.prepare("DELETE from CLIENT where ID_CLIENT=:ID_CLIENT");
    query.bindValue(":ID_CLIENT",res);

    return query.exec();
}


QSqlQueryModel *afficherClients()
{
    QSqlQueryModel * model=new QSqlQueryModel;

    model->setQuery("select * from SYSTEM.CLIENT;");


    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID_CLIENT"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("NOM"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("COURRIEL"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("ADRESSE"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("DATE_INSCIPTION"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("PT_VENTE"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("NUMEROCLIENT"));

    return model;
}


//********************************Rechercher Client********************************************************

QSqlQueryModel* CLIENT::rechercherClient(QString critere)
{
    QSqlQueryModel * model=new QSqlQueryModel();

    model->setQuery("SELECT * FROM SYSTEM.CLIENT WHERE NOM LIKE '%" + critere + "%' OR ADRESSE LIKE '%" + critere + "%' OR COURRIEL LIKE '%" + critere + "%'");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID_CLIENT"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("NOM"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("COURRIEL"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("ADRESSE"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("DATE_INSCIPTION"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("PT_VENTE"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("NUMEROCLIENT"));
    return model;
}

void CLIENT::findById(QString critere)
{
    QSqlQuery query;

    // Convertir la chaîne en entier
    bool conversionOK;
    int id = critere.toInt(&conversionOK);

    // Vérifier si la conversion est réussie
    if (conversionOK) {
        // Recherche par ID
        query.exec("SELECT * FROM SYSTEM.CLIENT WHERE ID_CLIENT = " + QString::number(id));
    } else {
        // Recherche par NOM ou ADRESSE
        query.exec("SELECT * FROM SYSTEM.CLIENT WHERE NOM LIKE '%" + critere + "%' OR ADRESSE LIKE '%" + critere + "%'");
    }
    if (query.next()) {
        // Retrieve data from the query result
        int id = query.value("id").toInt();
        QString num = query.value("numeroclient").toString();
        QString ptv = query.value("pt_vente").toString();
        this->setNUMEROCLIENT(num.toInt());
        this->setID_CLIENT(id);
        this->setPT_VENTE(ptv);
    } else {
    }
}


QStringList CLIENT::rechercherClients()
{

    QSqlQuery query;
    QStringList cblist;

    query.prepare("select * from SYSTEM.CLIENT ");
    query.exec();

    QString n;
    while(query.next())
            {
               // if (query.isValid())
                cblist.push_back(query.value(0).toString() );
                cblist.push_back(query.value(1).toString() );
                cblist.push_back(query.value(2).toString() );
                cblist.push_back(query.value(3).toString() );
                cblist.push_back(query.value(4).toString() );
                cblist.push_back(query.value(5).toString() );
                cblist.push_back(query.value(6).toString() );
             //   qDebug() << "test";

            }


    return  cblist;


}

QSqlQueryModel* CLIENT::trierClient(QString test)
{
    QSqlQueryModel * model=new QSqlQueryModel();

    if(test == "par défaut")
            {
                model->setQuery("SELECT * FROM SYSTEM.CLIENT");
            }
            else if(test == "ID")
            {
                model->setQuery("SELECT * FROM SYSTEM.CLIENT ORDER BY ID_CLIENT ASC");
            }
            else if(test == "NOM")
            {
                model->setQuery("SELECT * FROM SYSTEM.CLIENT ORDER BY NOM ASC");
            }
            else if(test == "COURRIEL")
            {
                model->setQuery("SELECT * FROM SYSTEM.CLIENT ORDER BY COURRIEL ASC");
            }
            else if(test == "ADRESSE")
            {
                model->setQuery("SELECT * FROM SYSTEM.CLIENT ORDER BY ADRESSE ASC");
            }
            model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID_CLIENT"));
            model->setHeaderData(1,Qt::Horizontal,QObject::tr("NOM"));
            model->setHeaderData(2,Qt::Horizontal,QObject::tr("COURRIEL"));
            model->setHeaderData(3,Qt::Horizontal,QObject::tr("ADRESSE"));
            model->setHeaderData(4,Qt::Horizontal,QObject::tr("DATE_INSCIPTION"));
            model->setHeaderData(5,Qt::Horizontal,QObject::tr("PT_VENTE"));
            model->setHeaderData(6,Qt::Horizontal,QObject::tr("NUMEROCLIENT"));
            return model;


}

bool CLIENT::isEmailValid(const QString &email)
{
    QRegularExpression regex("\\b[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\\.[A-Za-z]{2,4}\\b");

    return regex.match(email).hasMatch();
}





//**************tester si un num de id existe ou non ************************************************
bool CLIENT::clientExists(int ID_CLIENT)
{
bool exists = false;

QSqlQuery checkQuery;
checkQuery.prepare("select * from SYSTEM.CLIENT where ID_CLIENT=:ID_CLIENT");
checkQuery.bindValue(":ID_CLIENT",ID_CLIENT);


if (checkQuery.exec())
{
  if (checkQuery.next())
  {
      exists = true;
  }
}
else
{
   qDebug() << "Client not found";
}

return exists;
}


/************************************************************statistique_location**************/

int CLIENT::statistique(QString zone)
{
    QSqlQuery query;
    int count = 0;
    QSqlQuery requete("select * from SYSTEM.CLIENT where ADRESSE= '"+zone+"'");
    while (requete.next())
    {
       count++;
    }

    return count;
}


