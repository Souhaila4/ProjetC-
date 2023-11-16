#ifndef RECLAMATIONENTITY_H
#define RECLAMATIONENTITY_H

#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDialog>

class Reclamation
{
public:
    enum CategoriePanne {
        PanneTechnique,
        PanneMecanique
    };

    enum PrioritePanne {
        Elevee,
        Faible
    };

private:
    int id;
    QString nom;
    QString numeroClient;
    QString marqueVoiture;
    QString descriptionPanne;
    CategoriePanne categoriePanne;
    PrioritePanne prioritePanne;

public:
    Reclamation();
    Reclamation(int id, const QString &nom, const QString &numeroClient, const QString &marqueVoiture, const QString &descriptionPanne, CategoriePanne categoriePanne, PrioritePanne prioritePanne);
    Reclamation(const QString &nom, const QString &numeroClient, const QString &marqueVoiture, const QString &descriptionPanne, CategoriePanne categoriePanne, PrioritePanne prioritePanne);

    // Getters
    int getId() const;
    QString getNom() const;
    QString getNumeroClient() const;
    QString getMarqueVoiture() const;
    QString getDescriptionPanne() const;
    CategoriePanne getCategoriePanne() const;
    PrioritePanne getPrioritePanne() const;

    // Setters
    void setId(int id);
    void setNom(const QString &nom);
    void setNumeroClient(const QString &numeroClient);
    void setMarqueVoiture(const QString &marqueVoiture);
    void setDescriptionPanne(const QString &descriptionPanne);
    void setCategoriePanne(CategoriePanne categoriePanne);
    void setPrioritePanne(PrioritePanne prioritePanne);

    // CRUD operations
    bool ajouter();
    bool modifier();
    QSqlQueryModel *afficher();
    bool envoyerSMS(const QString &numero, const QString &message);


};
QSqlQueryModel *afficherReclamations();

#endif // RECLAMATIONENTITY_H
