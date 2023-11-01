#ifndef CLIENTCONTROLLER_H
#define CLIENTCONTROLLER_H

#include <QWidget>

namespace Ui {
class ClientController;
}

class ClientController : public QWidget
{
    Q_OBJECT

public:
    explicit ClientController(QWidget *parent = nullptr);
    ~ClientController();

private slots:
    void on_on_pushButton_ajouter_clicked_clicked();

    void on_on_pushButton_ajouter_clicked_2_clicked();

private:
    Ui::ClientController *ui;
};

#endif // CLIENTCONTROLLER_H
