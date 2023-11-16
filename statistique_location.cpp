#include "statistique_location.h"
#include<iostream>
#include "mainwindow.h"

statistique_location::statistique_location(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::statistique_location)
{
    ui->setupUi(this);
}

statistique_location::~statistique_location()
{
    delete ui;
}

int statistique_location::statistique_ariena()
{
    QSqlQuery query;
    int count = 0;
    QSqlQuery requete("select * from SYSTEM.CLIENT where ADRESSE= 'ARIENA'");
    while (requete.next())
    {
        count++;
    }

    return count;
}

int statistique_location::statistique_manouba()
{
    QSqlQuery query;
    int count = 0;
    QSqlQuery requete("select * from SYSTEM.CLIENT where ADRESSE= 'MANOUBA'");
    while (requete.next())
    {
        count++;
    }

    return count;
}

int statistique_location::statistique_bon_lieux_sud()
{
    QSqlQuery query;
    int count = 0;
    QSqlQuery requete("select * from SYSTEM.CLIENT where ADRESSE= 'BON LIEUX SUD'");
    while (requete.next())
    {
        count++;
    }

    return count;
}

int statistique_location::statistique_bon_lieux_nord()
{
    QSqlQuery query;
    int count = 0;
    QSqlQuery requete("select * from SYSTEM.CLIENT where ADRESSE= 'BON LIEUX NORD'");
    while (requete.next())
    {
        count++;
    }

    return count;
}

void statistique_location::paintEvent(QPaintEvent *)
{
    int a = statistique_ariena();
    cout << a << endl;
    int b = statistique_manouba();
    cout << b << endl;
    int c = statistique_bon_lieux_sud();
    cout << c << endl;
    int d = statistique_bon_lieux_nord();
    cout << d << endl;

    float s1 = a * 100;
    float s2 = b * 100;
    float s3 = c * 100;
    float s4 = d * 100;

    float nb = a + b + c + d;

    float q1 = s1 / nb;
    float q2 = s2 / nb;
    float q3 = s3 / nb;
    float q4 = s4 / nb;

    float x1 = (q1 * 360) / 100;
    float x2 = (q2 * 360) / 100;
    float x3 = (q3 * 360) / 100;
    float x4 = (q4 * 360) / 100;

    QPainter painter(this);
    QRectF size = QRectF(150, 40, this->width() - 600, this->width() - 600);

    painter.setBrush(Qt::blue);
    painter.drawPie(size, 0, 16 * x1);
    ui->label_2->setText("ARIENA");

    painter.setBrush(Qt::green);
    painter.drawPie(size, 16 * x1, 16 * x2);
    ui->label_3->setText("MANOUBA");

    painter.setBrush(Qt::black);
    painter.drawPie(size, 16 * (x1 + x2), 16 * x3);
    ui->label_4->setText("BON LIEUX SUD");

    painter.setBrush(Qt::yellow);
    painter.drawPie(size, 16 * (x1 + x2 + x3), 16 * x4);
    ui->label_5->setText("BON LIEUX NORD");
}
