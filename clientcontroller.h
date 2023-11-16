// clientcontroller.h
#ifndef CLIENTCONTROLLER_H
#define CLIENTCONTROLLER_H

#include <QWidget>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>
#include <QPainter>
#include <QTableWidget>
#include "client.h"
#include "fediliter.h"

QT_BEGIN_NAMESPACE
namespace Ui { class ClientController ; }
QT_END_NAMESPACE
class ClientController : public QWidget {
    Q_OBJECT

public:
    ClientController(QWidget *parent = nullptr);
    ~ClientController();

private slots:
    void on_on_pushButton_ajouter_clicked_clicked();
    void on_on_pushButton_ajouter_clicked_2_clicked();
    void on_on_pushButton_supprimer_clicked_clicked();
    void on_pushButton_3_clicked();
    void on_comboBox_7_activated(const QString &arg1);

    // Ajoutez vos slots liés aux réclamations ici

    void on_techniqueRadioButton_clicked();

    void on_mecaniqueRadioButton_clicked();

    void on_eleveeRadioButton_clicked();

    void on_faibleRadioButton_clicked();

    void on_addButton_clicked();

    void on_table4_activated(const QModelIndex &index);

    void on_radioButton_6_clicked();

    void on_radioButton_5_clicked();

    void on_lineEdit_recherche_textChanged(const QString &arg1);

    void on_lineEdit_idClient_textChanged(const QString &arg1);

    void on_pushButton_calculer_clicked();

    void on_pushButton_14_clicked();

private:
    // Autres membres nécessaires pour la gestion des clients

    QLineEdit *lineEdit_idClient;
    QLineEdit *lineEdit_totalPrixAchat;
    QLabel *label_pointsVente;
    QLabel *label_pointsFidelite;
    QPushButton *pushButton_calculer;
    QPushButton *acceptButton;
    QPushButton *refuseButton;
    QTableWidget *reclamationsTableWidget;
    void Paint(QPaintEvent *);
    QString CP;
    QString PP;
    QString selectedNum;
    Fidelite *fidelite = new Fidelite();

    // Autres membres nécessaires

private:
    Ui::ClientController *ui;

};

#endif // CLIENTCONTROLLER_H
