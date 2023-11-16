#include "reclamationentity.h"
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrl>
#include <QUrlQuery>
#include <QByteArray>
#include <QDebug>
#include <QEventLoop>

Reclamation::Reclamation()
{

}

void Reclamation::setNom(const QString &nom)
{
    this->nom=nom;
}

void Reclamation::setNumeroClient(const QString &numeroClient)
{
    this->numeroClient = numeroClient;
}

void Reclamation::setMarqueVoiture(const QString &marqueVoiture)
{
    this->marqueVoiture=marqueVoiture;
}

void Reclamation::setDescriptionPanne(const QString &descriptionPanne)
{
    this->descriptionPanne = descriptionPanne;
}

void Reclamation::setCategoriePanne(CategoriePanne categoriePanne)
{
    this->categoriePanne=categoriePanne;
}

void Reclamation::setPrioritePanne(PrioritePanne prioritePanne)
{
    this->prioritePanne=prioritePanne;
}
Reclamation::Reclamation(int id, const QString &nom, const QString &numeroClient, const QString &marqueVoiture, const QString &descriptionPanne, CategoriePanne categoriePanne, PrioritePanne prioritePanne)
{
    this->id=id;
    this->nom=nom;
    this->numeroClient=numeroClient;
    this->marqueVoiture=marqueVoiture;
    this->descriptionPanne=descriptionPanne;
    this->categoriePanne=categoriePanne;
    this->prioritePanne=prioritePanne;
}

bool Reclamation::ajouter()
{

    QSqlQuery query(QSqlDatabase::database());

    QString res = QString::number(id);

    query.prepare("insert into SYSTEM.RECLAMATION(nom,numeroClient,marqueVoiture,descriptionPanne,categoriePanne,prioritePanne) values(:nom,:numeroClient,:marqueVoiture,:descriptionPanne,:categoriePanne,:prioritePanne)");


    query.bindValue(":nom",nom);
    query.bindValue(":numeroClient",numeroClient);
    query.bindValue(":marqueVoiture",marqueVoiture);
    query.bindValue(":descriptionPanne",descriptionPanne);
    query.bindValue(":categoriePanne",categoriePanne);
    query.bindValue(":prioritePanne=",prioritePanne);

    return query.exec();

}

QSqlQueryModel * Reclamation::afficher()
{
    QSqlQueryModel * model=new QSqlQueryModel();

    model->setQuery("select * from SYSTEM.RECLAMATION");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("id"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("numeroClient"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("marqueVoiture"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("descriptionPanne"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("categoriePanne"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("prioritePanne"));
    return model;

}

QSqlQueryModel *afficherReclamations()
{
    QSqlQueryModel * model=new QSqlQueryModel();

    model->setQuery("select * from SYSTEM.RECLAMATION");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("id"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("numeroClient"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("marqueVoiture"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("descriptionPanne"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("categoriePanne"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("prioritePanne"));
    return model;

}



bool Reclamation::envoyerSMS(const QString &numero, const QString &message) {
    // Remplacez ces valeurs par les vôtres obtenues lors de l'inscription à Twilio
    const QString accountSid = "US73dab7640d4a55455677a7ae866a41c8";
    const QString authToken = "a78fb03574840fca650240cc6e9e598f";
    const QString twilioNumber = "+12565889169";

    QNetworkAccessManager manager;

    QNetworkRequest request(QUrl("https://api.twilio.com/2010-04-01/Accounts/" + accountSid + "/Messages.json"));
    request.setRawHeader("Authorization", "Basic " + QByteArray(QString("%1:%2").arg(accountSid, authToken).toUtf8()).toBase64());
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");

    QByteArray postData;
    postData.append("To=+216" + numero.toUtf8());
    postData.append("&From=" + twilioNumber.toUtf8());
    postData.append("&Body=" + message.toUtf8());

    QNetworkReply *reply = manager.post(request, postData);
    QEventLoop loop;

    loop.exec();

    if (reply->error() == QNetworkReply::NoError) {
        qDebug() << "SMS envoyé avec succès.";
        return true;
    } else {
        qDebug() << "Échec de l'envoi du SMS:" << reply->errorString();
                                                  return false;
    }
}



