#ifndef CLIENTENTITY_H
#define CLIENTENTITY_H
#include <QString>
#include <QDate>
#include <QSqlQuery>
#include <QSqlDatabase>
#include <QSqlQueryModel>
#include <QDialog>
#include <QChart>
#include <QPainter>


class CLIENT
{
private:
    int ID_CLIENT;
    int NUMEROCLIENT;
    QDate DATE_INSCIPTION;
    QString NOM, COURRIEL, ADRESSE, PT_VENTE;

public:

    CLIENT();
    CLIENT(int, QString, QString, QString, QDate, QString, int);
    CLIENT(QString, QString, QString, QDate, QString, int);

    // Getters
    QString getNOM() const;
    QString getCOURRIEL() const;
    QString getADRESSE() const;
    QDate getDATE_INSCIPTION() const;
    QString getPT_VENTE() const;
    int getID_CLIENT() const;
    int getNUMEROCLIENT() const;

    // Setters
    void setNOM(const QString &n);
    void setCOURRIEL(const QString &c);
    void setADRESSE(const QString &a);
    void setDATE_INSCIPTION(const QDate &d);
    void setPT_VENTE(const QString &ptv);
    void setID_CLIENT(int idClient);
    void setNUMEROCLIENT(int numeroClient);

    // CRUD operations
    bool ajouter();
    bool modifier();
    QSqlQueryModel *afficher();
    bool supprimer(int);

    // Search and sort
    QSqlQueryModel* rechercherClient( QString critere);
    void findById( QString critere);
    QStringList rechercherClients();
    QSqlQueryModel* trierClient(QString critere);

    // Validation and existence checks
    bool isEmailValid(const QString &email);
    bool clientExists(int id);

    // Statistics
    static int statistique(QString);
    int obtenirPointsVenteParID(int idClient);

    // Custom paint event
};

// Global function to fetch all clients
QSqlQueryModel *afficherClients();

#endif // CLIENTENTITY_H
