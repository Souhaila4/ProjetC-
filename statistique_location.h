#ifndef STATISTIQUE_LOCATION_SCOOTER_H
#define STATISTIQUE_LOCATION_SCOOTER_H

#include <QDialog>
#include <QtCharts/QCategoryAxis>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QPainter>
#include <QSqlQuery>

namespace Ui {
class statistique_location;
}

class statistique_location : public QDialog
{
    Q_OBJECT

public:
    explicit statistique_location(QWidget *parent = nullptr);
    int statistique_ariena();
    int statistique_manouba();
    int statistique_bon_lieux_sud();
    int statistique_bon_lieux_nord();
    void paintEvent(QPaintEvent *);

    ~statistique_location();

private:
    Ui::statistique_location *ui;
};

#endif // STATISTIQUE_LOCATION_SCOOTER_H
