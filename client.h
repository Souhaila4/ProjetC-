#ifndef CLIENT_H
#define CLIENT_H
#include<QString>
#include <QWidget>
#include<QSqlQuery>
#include<QSqlQueryModel>

QT_BEGIN_NAMESPACE

namespace Ui { class Client; }
QT_END_NAMESPACE;

class Client : public QWidget
{
    Ui::Client *ui;

public:

    Client(){};
    ~Client();
    Client(QWidget*);


};

#endif // CLIENT_H
