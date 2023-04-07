#ifndef APIREST_H
#define APIREST_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>

class ApiRest : public QObject
{
    Q_OBJECT
public:
    explicit ApiRest(QObject *parent = nullptr);


signals:


public slots:

    void onRestApiFinished();

private:
    QNetworkReply *m_NetworkReply;
    QNetworkAccessManager *m_NetworkAccessManager;
};

#endif // APIREST_H
