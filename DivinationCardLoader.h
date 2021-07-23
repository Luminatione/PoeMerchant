#ifndef DIVINATIONCARDLOADER_H
#define DIVINATIONCARDLOADER_H

#include <QHash>
#include <QSharedPointer>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>

#include "rapidjson/document.h"
#include "DivinationCard.h"

#define DIVINATION_CARDS_AMOUNT 355

template <typename T> class  DivinationCardLoader : public QObject
{
    Q_OBJECT
    QSharedPointer<QVector<DivinationCard>> cards = QSharedPointer<QVector<DivinationCard>>(new QVector<DivinationCard>());
    QString url = "https://poe.ninja/api/data/itemoverview?type=DivinationCard&league=Standard";
    QNetworkReply* currentReply;
    QSharedPointer<QNetworkAccessManager> accessManager;

    void loadStashTab();
    void readWebsiteContent();
    void onError(QNetworkReply::NetworkError errorCode);
public:
    DivinationCardLoader();
    void load();
   QVector<DivinationCard>* get();
};

#endif // DIVINATIONCARDLOADER_H
