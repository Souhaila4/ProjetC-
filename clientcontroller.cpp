#include "clientcontroller.h"
#include "cliententity.h"
#include "ui_clientcontroller.h"
#include <QDebug>
#include <QDate>

ClientController::ClientController(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ClientController)
{
    ui->setupUi(this);
}

ClientController::~ClientController()
{
    delete ui;
}

void ClientController::on_on_pushButton_ajouter_clicked_clicked()
{
    int ID = ui->llineEdit_IDS->text().toInt();
    QString NOM = ui->lineEdit_nom->text();
    QString COURREIL = ui->lineEdit_courreil->text();
    QString ADRESSE = ui->lineEdit_adresse->text();
    QDate DATE_INSCIPTION = QDate::fromString(ui->lineEdit_date->text(), "dd/MM/yyyy");
    qDebug() << ui->lineEdit_date->text() + " || " + DATE_INSCIPTION.day();
    QString PT_VENTE = ui->lineEdit_ptv->text();
    QString PT_LOCATION = ui->lineEdit_ptl->text();
    //CLIENT *client = new CLIENT(NOM, COURRIEL, ADRESSE, DATE_INSCIPTION, PT_VENTE, PT_LOCATION);
    if(ui->lineEdit_nom->text().size()<=0) {
        ui->label_error->setText("NOM INVALID");
    } else if(ui->lineEdit_courreil->text().size()<=0) {
        ui->label_error->setText("COURREIL INVALID");
    } else if(ui->lineEdit_adresse->text().size()<=0) {
        ui->label_error->setText("ADRESSE INVALID");

    } else if(ui->lineEdit_date->text().size()<=0) {
        ui->label_error->setText("DATE INVALID");

    } else if(ui->lineEdit_ptv->text().size()<=0) {
        ui->label_error->setText("PTV INVALID");

    } else if(ui->lineEdit_ptl->text().size()<=0) {
        ui->label_error->setText("PTL INVALID");

    } else {
        CLIENT* cl=new CLIENT(NOM,COURREIL,ADRESSE,DATE_INSCIPTION,PT_VENTE,PT_LOCATION);
        cl->ajouter();
        ui->lineEdit_nom->setText("");
        ui->lineEdit_courreil->setText("");
        ui->lineEdit_adresse->setText("");
        ui->lineEdit_ptv->setText("");
        ui->lineEdit_ptl->setText("");
    }



}

void ClientController::on_on_pushButton_ajouter_clicked_2_clicked()
{
    int ID = ui->lineEdit_id->text().toInt();
    QString NOM = ui->lineEdit_nom->text();
    QString COURREIL = ui->lineEdit_courreil->text();
    QString ADRESSE = ui->lineEdit_adresse->text();
    QDate DATE_INSCIPTION = QDate::fromString(ui->lineEdit_date->text(), "dd/MM/yyyy");
    qDebug() << ui->lineEdit_date->text() + " || " + DATE_INSCIPTION.day();
    QString PT_VENTE = ui->lineEdit_ptv->text();
    QString PT_LOCATION = ui->lineEdit_ptl->text();
    if(ui->lineEdit_id->text().size()<=0) {
        ui->label_error->setText("ID INVALID");
    } else if(ui->lineEdit_nom->text().size()<=0) {
        ui->label_error->setText("NOM INVALID");
    } else if(ui->lineEdit_courreil->text().size()<=0) {
        ui->label_error->setText("COURREIL INVALID");
    } else if(ui->lineEdit_adresse->text().size()<=0) {
        ui->label_error->setText("ADRESSE INVALID");

    } else if(ui->lineEdit_date->text().size()<=0) {
        ui->label_error->setText("DATE INVALID");

    } else if(ui->lineEdit_ptv->text().size()<=0) {
        ui->label_error->setText("PTV INVALID");

    } else if(ui->lineEdit_ptl->text().size()<=0) {
        ui->label_error->setText("PTL INVALID");

    } else {
        CLIENT* cl=new CLIENT(ID,NOM,COURREIL,ADRESSE,DATE_INSCIPTION,PT_VENTE,PT_LOCATION);
        cl->modifier();
        ui->lineEdit_id->setText("");
        ui->lineEdit_nom->setText("");
        ui->lineEdit_courreil->setText("");
        ui->lineEdit_adresse->setText("");
        ui->lineEdit_ptv->setText("");
        ui->lineEdit_ptl->setText("");
        ui->label_error->setText("");
    }
}
