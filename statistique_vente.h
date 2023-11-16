#ifndef STATISTIQUE_VENTE_H
#define STATISTIQUE_VENTE_H
#include <QDialog>
#include <QtCharts/QCategoryAxis>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QPainter>
#include <QSqlQuery>

namespace Ui {
class statistique_vente;
}

class statistique_vente : public QDialog
{
    Q_OBJECT

public:
    explicit statistique_vente(QWidget *parent = nullptr);
    int statistique_bizerte();
    int statistique_nabeul();
    int statistique_sfax();
    int statistique_sousse();
    int statistique_tunis();
    void paintEvent(QPaintEvent *);

    ~statistique_vente();

private:
    Ui::statistique_vente *ui;
};

#endif // STATISTIQUE_VENTE_H
