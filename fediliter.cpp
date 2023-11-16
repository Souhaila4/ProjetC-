#include "fediliter.h"
#include <QList>


Fidelite::Fidelite()
{

}

void Fidelite::calculerFidelite(QString id )
{

    QSqlQuery query(QSqlDatabase::database());


    query.prepare("SELECT SYSTEM.Client.id_client, COUNT(SYSTEM.Vente.id_vente) AS total_ventes,SUM(vehicule.prix) AS total_prix FROM SYSTEM.Client LEFT JOIN SYSTEM.Vente ON SYSTEM.Client.id_client = SYSTEM.Vente.id_client LEFT JOIN SYSTEM.Vehicule ON SYSTEM.Vente.id_vehicule = SYSTEM.Vehicule.id_vehicule WHERE SYSTEM.Client.id_client="+id+" GROUP BY SYSTEM.Client.id_client"
    );

    query.exec();
    this->total = 0;
    this->prix = 0;
    while(query.next()){
        this->total = query.value("total_ventes").toInt();
        this->prix = query.value("total_prix").toDouble();
    }
}

int Fidelite::getPTSVidelite()
{
    return this->prix * this->total;
}
