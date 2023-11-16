#include "statistique_vente.h"
#include <iostream>

statistique_vente::statistique_vente(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::statistique_vente)
{
    ui->setupUi(this);
}

statistique_vente::~statistique_vente()
{
    delete ui;
}

int statistique_vente::statistique_bizerte()
{
    QSqlQuery query;
    int count = 0;
    QSqlQuery requete("select * from SYSTEM.CLIENT where ADRESSE= 'Bizerte'");
    while (requete.next())
    {
        count++;
    }

    return count;
}

int statistique_vente::statistique_tunis()
{
    QSqlQuery query;
    int count = 0;
    QSqlQuery requete("select * from SYSTEM.CLIENT where ADRESSE= 'Tunis'");
    while (requete.next())
    {
        count++;
    }

    return count;
}

int statistique_vente::statistique_nabeul()
{
    QSqlQuery query;
    int count = 0;
    QSqlQuery requete("select * from SYSTEM.CLIENT where ADRESSE= 'Nabeul'");
    while (requete.next())
    {
        count++;
    }

    return count;
}

int statistique_vente::statistique_sfax()
{
    QSqlQuery query;
    int count = 0;
    QSqlQuery requete("select * from SYSTEM.CLIENT where ADRESSE= 'Sfax'");
    while (requete.next())
    {
        count++;
    }

    return count;
}

int statistique_vente::statistique_sousse()
{
    QSqlQuery query;
    int count = 0;
    QSqlQuery requete("select * from SYSTEM.CLIENT where ADRESSE= 'Sousse'");
    while (requete.next())
    {
        count++;
    }

    return count;
}



void statistique_vente::paintEvent(QPaintEvent *)
{
    int bizerte = statistique_bizerte();
    std::cout << bizerte << std::endl;
    int tunis = statistique_tunis();
    std::cout << tunis << std::endl;
    int nabeul = statistique_nabeul();
    std::cout << nabeul << std::endl;
    int sfax = statistique_sfax();
    std::cout << sfax << std::endl;
    int sousse = statistique_sousse();
    std::cout << sousse << std::endl;


    float s_bizerte = bizerte * 100;
    float s_tunis = tunis * 100;
    float s_nabeul = nabeul * 100;
    float s_sfax = sfax * 100;
    float s_sousse = sousse * 100;

    float nb = bizerte + tunis + nabeul + sfax + sousse ;
    float q_bizerte = s_bizerte / nb;
    float q_tunis = s_tunis / nb;
    float q_nabeul = s_nabeul / nb;
    float q_sfax = s_sfax / nb;
    float q_sousse = s_sousse / nb;

    float y;
    y = (q_bizerte * 360) / 100;
    float z;
    z = (q_tunis * 360) / 100;
    float p;
    p = (q_nabeul * 360) / 100;
    float v;
    v = (q_sfax * 360) / 100;
    float w;
    w = (q_sousse * 360) / 100;


    QPainter painter(this);
    QRectF size = QRectF(150, 40, this->width() - 600, this->width() - 600);

    painter.setBrush(Qt::blue);
    painter.drawPie(size, 0, 16 * y);

    // ui->label_2->setText("Bizerte");  // Cette ligne est commentée ou supprimée

    painter.setBrush(Qt::green);
    painter.drawPie(size, 16 * y, 16 * p);

    painter.setBrush(Qt::black);
    painter.drawPie(size, 16 * (y + p), 16 * v);

    painter.setBrush(Qt::yellow);
    painter.drawPie(size, 16 * (y + p + v), 16 * w);

    painter.setBrush(Qt::red);
    painter.drawPie(size, 16 * (y + p + v + w), 16 * z);

    painter.setBrush(Qt::cyan);
    painter.drawPie(size, 16 * (y + p + v + w + z), 16 * remainingValue);

}
