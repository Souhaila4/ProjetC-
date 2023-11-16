#include "clientcontroller.h"
#include "cliententity.h"
#include "reclamationentity.h"
#include "fediliter.h"
#include "ui_clientcontroller.h"
#include <QDebug>
#include <QDate>
#include <QMainWindow>
#include <iostream>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QChart>

ClientController::ClientController(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ClientController)
{
    ui->setupUi(this);
    Reclamation* rec = new Reclamation();
    ui->tableView->setModel(afficherClients());
    ui->table4->setModel(rec->afficher());
    this->Paint(nullptr);

}


ClientController::~ClientController()
{
    delete ui;
}

void ClientController::on_on_pushButton_ajouter_clicked_clicked()
{

    QString NOM = ui->lineEdit_nom->text();
    QString COURREIL = ui->lineEdit_courreil->text();
    QString ADRESSE = ui->comboBox_adresse->currentText();
    QDate DATE_INSCIPTION = QDate::fromString(ui->lineEdit_date->text(), "dd/MM/yyyy");
    QString PT_VENTE = ui->lineEdit_ptv->text();
    int NUMEROCLIENT=ui->lineEdit_num->text().toInt();
    //CLIENT *client = new CLIENT(NOM, COURRIEL, ADRESSE, DATE_INSCIPTION, PT_VENTE, PT_LOCATION);
    if(ui->lineEdit_nom->text().size()<=0) {
        ui->label_error->setText("NOM INVALID");
    } else if(ui->lineEdit_courreil->text().size()<=0) {
        ui->label_error->setText("COURREIL INVALID");
    } else if(ui->comboBox_adresse->currentText().size()<=0) {
        ui->label_error->setText("ADRESSE INVALID");

    } else if(ui->lineEdit_date->text().size()<=0) {
        ui->label_error->setText("DATE INVALID");

    } else if(ui->lineEdit_ptv->text().size()<=0) {
        ui->label_error->setText("PTV INVALID");

    } else if(ui->lineEdit_num->text().size()<=0){
            ui->label_error->setText("Numero INVALID");
        }
     else {
        CLIENT* cl=new CLIENT(NOM,COURREIL,ADRESSE,DATE_INSCIPTION,PT_VENTE, NUMEROCLIENT);
        cl->ajouter();
        ui->lineEdit_nom->setText("");
        ui->lineEdit_courreil->setText("");
        ui->comboBox_adresse->setCurrentText("");
        ui->lineEdit_ptv->setText("");
        ui->lineEdit_num->setText("");
    }

}

void ClientController::on_on_pushButton_ajouter_clicked_2_clicked()
{
    QString NOM = ui->lineEdit_nom->text();
    QString COURREIL = ui->lineEdit_courreil->text();
    QString ADRESSE = ui->comboBox_adresse->currentText();
    QDate DATE_INSCIPTION = QDate::fromString(ui->lineEdit_date->text(), "dd/MM/yyyy");
    QString PT_VENTE = ui->lineEdit_ptv->text();
    int NUMEROCLIENT =ui->lineEdit_num->text().toInt();

    if(ui->lineEdit_nom->text().isEmpty()) {
        ui->label_error->setText("NOM INVALID");
    } else if(ui->lineEdit_courreil->text().isEmpty()) {
        ui->label_error->setText("COURREIL INVALID");
    } else if(ui->comboBox_adresse->currentText().isEmpty()) {
        ui->label_error->setText("ADRESSE INVALID");
    } else if(ui->lineEdit_date->text().isEmpty()) {
        ui->label_error->setText("DATE INVALID");
    } else if(ui->lineEdit_ptv->text().isEmpty()) {
        ui->label_error->setText("PTV INVALID");
    } else {
        CLIENT* cl = new CLIENT(NOM, COURREIL, ADRESSE, DATE_INSCIPTION, PT_VENTE, NUMEROCLIENT);
        cl->modifier();
        ui->lineEdit_nom->setText("");
        ui->lineEdit_courreil->setText("");
        ui->comboBox_adresse->setCurrentText("");
        ui->lineEdit_ptv->setText("");
        ui->lineEdit_num->setText("");
        ui->label_error->setText("");
    }
}


void ClientController::on_on_pushButton_supprimer_clicked_clicked()
{
    QSqlQuery query;
    std::cout << ui->llineEdit_IDS->text().toStdString() << std::endl;
    //QString id = QString::number(ui->llineEdit_IDS->text().toInt());
    QString id = ui->llineEdit_IDS->text();
    query.prepare("DELETE from SYSTEM.CLIENT where ID_CLIENT = :id");
    query.bindValue(":id", id);
    query.exec();
}

void ClientController::on_pushButton_3_clicked()
{
    ui->tableView->setModel(afficherClients());
}


void ClientController::on_comboBox_7_activated(const QString &arg1)
{
    CLIENT client;  // Créez une instance de la classe CLIENT
    QString critere = ui->comboBox_7->currentText();
    ui->tableView_2->setModel(client.trierClient(critere));
}




void ClientController::Paint(QPaintEvent *) {
    // Assuming that cv is an instance of your CLIENT class

    QString address1 = "ARIANA";
    QString address2 = "MANOUBA";
    QString address3 = "BON LIEUX SUD";
    QString address4 = "BON LIEUX NORD";

    int A = CLIENT::statistique(address1);
    int B = CLIENT::statistique(address2);
    int C = CLIENT::statistique(address3);
    int D = CLIENT::statistique(address4);

    float s1 = A * 100;
    float s2 = B * 100;
    float s3 = C * 100;
    float s4 = D * 100;

    float nb = A + B + C + D;

    float q1 = (nb != 0) ? (s1 / nb) : 0;
    float q2 = (nb != 0) ? (s2 / nb) : 0;
    float q3 = (nb != 0) ? (s3 / nb) : 0;
    float q4 = (nb != 0) ? (s4 / nb) : 0;

    float y = (q1 * 360) / 100;
    float m = (q2 * 360) / 100;
    float n = (q3 * 360) / 100;
    float o = (q4 * 360) / 100;

    // Create the chart view
    QtCharts::QChartView *chartView = new QtCharts::QChartView(this);
    chartView->setRenderHint(QPainter::Antialiasing);

    // Create the pie series
    QtCharts::QPieSeries *series = new QtCharts::QPieSeries();

    // Add data to the series
    series->append(address1, y);
    series->append(address2, m);
    series->append(address3, n);
    series->append(address4, o);

    // Create the chart
    QtCharts::QChart *chart = new QtCharts::QChart();
    chart->addSeries(series);
    chart->setTitle("Statistique par rapport aux adresses");

    // Set up the legend
    chart->legend()->setAlignment(Qt::AlignRight);
    chart->legend()->setFont(QFont("Arial", 9));

    // Set up the chart view
    chartView = new QtCharts::QChartView(chart, ui->label);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->setMinimumSize(850, 600);

    // Show the chart
    chartView->show();



}





void ClientController::on_techniqueRadioButton_clicked()
{
        this->CP = "Panne Mechnique";
}


void ClientController::on_mecaniqueRadioButton_clicked()
{
        this->CP = "Panne Technique";
}


void ClientController::on_eleveeRadioButton_clicked()
{
        this->PP = "Priorité Elevée";
}


void ClientController::on_faibleRadioButton_clicked()
{
        this->PP = "Priorité Faible";
}


void ClientController::on_addButton_clicked()
{
        QString nom = ui->nomLineEdit->text();
        QString num = ui->numeroLineEdit->text();
        QString marque = ui->marqueVoitureLineEdit->text();
        QString desc = ui->descriptionPanneTextEdit->toPlainText();
        Reclamation::CategoriePanne CP = this->CP == "Panne Mechanique" ? Reclamation::CategoriePanne::PanneMecanique : Reclamation::CategoriePanne::PanneTechnique ;
        Reclamation::PrioritePanne PP = this->PP == "Priorité Elevée" ? Reclamation::PrioritePanne::Elevee : Reclamation::PrioritePanne::Faible ;
        Reclamation * rec = new Reclamation();
        rec->setNom(nom);
        rec->setNumeroClient(num);
        rec->setMarqueVoiture(marque);
        rec->setDescriptionPanne(desc);
        rec->setCategoriePanne(CP);
        rec->setPrioritePanne(PP);
        rec->ajouter();
        ui->table4->setModel(rec->afficher());
}


void ClientController::on_table4_activated(const QModelIndex &index)
{
        Reclamation* rec = new Reclamation();
        QItemSelectionModel* model = ui->table4->selectionModel();
        int idx = model->selectedIndexes().first().row();
        QString num = ui->table4->model()->data(ui->table4->model()->index(idx,1)).toString();
        this->selectedNum=num;
}


void ClientController::on_radioButton_6_clicked()
{
        Reclamation* rec = new Reclamation();
        CLIENT* c = new CLIENT();
        c->findById(this->selectedNum);
        rec->envoyerSMS(QString(c->getNUMEROCLIENT()),"Reclamation Acceptée");
}


void ClientController::on_radioButton_5_clicked()
{
        Reclamation* rec = new Reclamation();
        CLIENT* c = new CLIENT();
        c->findById(this->selectedNum);
        rec->envoyerSMS(QString(c->getNUMEROCLIENT()),"Reclamation Réfusée");
}


void ClientController::on_lineEdit_recherche_textChanged(const QString &arg1)
{
        CLIENT client;
        ui->tableView_3->setModel(client.rechercherClient(ui->lineEdit_recherche->text()));
}


void ClientController::on_lineEdit_idClient_textChanged(const QString &arg1)
{
        QString id = ui->lineEdit_idClient->text();
        this->fidelite->calculerFidelite(id);
        ui->lineEdit_totalPrixAchat->setText(QString::number(this->fidelite->getPrix())+" DT");
        ui->lineEdit_nom_4->setText(QString::number(this->fidelite->getTotal()));
}


void ClientController::on_pushButton_calculer_clicked()
{
        this->ui->label_pts_fidelite->setText(QString::number(this->fidelite->getPTSVidelite())+" PTS");
}



void ClientController::on_pushButton_14_clicked()
{
        ui->tableView->setModel(afficherReclamations());
}

