#include "apirest.h"
#include <QObject>
#include <QDebug>
ApiRest::ApiRest(QObject *parent)
    : QObject{parent}
{
    m_NetworkAccessManager = new QNetworkAccessManager(this);
    m_NetworkReply = m_NetworkAccessManager->get(QNetworkRequest(QUrl("https://dataservice.accuweather.com/forecasts/v1/daily/1day/425639?apikey=ymI7fvIwWHcOoAGGIkGv47nRz7P79QZF")));
    connect(m_NetworkReply,&QNetworkReply::readyRead,this,&ApiRest::onRestApiFinished);
}

void ApiRest::onRestApiFinished()
{
    QString strReply = m_NetworkReply->readAll();
//    qDebug() << strReply;

    QJsonDocument jsonResponse = QJsonDocument::fromJson(strReply.toUtf8());
    QJsonObject jsonObj = jsonResponse.object();
    QJsonObject headLine = jsonObj["Headline"].toObject();
    qDebug() <<"headLine "<<headLine;
    qDebug() << "EffectiveDate:" << headLine["EffectiveDate"].toString();
    qDebug() << "Category:" << headLine["Category"].toString();
    qDebug() << "Date:" << headLine["Text"].toString();
    qDebug() << "EffectiveDate:" << headLine["EffectiveDate"].toString();
    foreach (auto key, headLine.keys()) {
        qDebug() << key;
        qDebug() << headLine[key].toString();
    }
}


