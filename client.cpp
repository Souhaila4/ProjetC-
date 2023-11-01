#include "client.h"
#include "ui_client.h"
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QObject>

Client::~Client()
{
    delete ui;
}
