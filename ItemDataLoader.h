#ifndef ITEMDATALOADER_H
#define ITEMDATALOADER_H

#include <QHash>
#include <QSharedPointer>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>

#include "rapidjson/document.h"
#include "ItemData.h"

#define DATA_LOADER(type)


class ItemDataLoader : public QObject
{

    Q_OBJECT

protected:
    std::shared_ptr<QVector<std::shared_ptr<ItemData>>> items =  std::shared_ptr<QVector<std::shared_ptr<ItemData>>>(new QVector<std::shared_ptr<ItemData>>());

    QString apiUrl = "https://poe.ninja/api/data/itemoverview?type={type}&league={league}";

    std::unique_ptr<QNetworkReply> currentReply;
    QNetworkAccessManager* accessManager;

    int readWebsiteContentDesiredHits = 1;
    int readWebsiteContentHits = 0;

    QString itemType;
    QString league;

    virtual void connect();

    virtual void initialize();

    virtual void parseItem(rapidjson::Value::ConstValueIterator iter);

    virtual void onError(QNetworkReply::NetworkError errorCode);

    virtual void readWebsiteContent(QNetworkReply* reply);

public:
    ItemDataLoader(){}

    ItemDataLoader(QNetworkAccessManager* accessManager, QString league) : accessManager(accessManager), league(league){}

    virtual void load();

    QVector<std::shared_ptr<ItemData>>* getItems();
signals:
    void allItemsLoaded();
};

#endif // ITEMDATALOADER_H
