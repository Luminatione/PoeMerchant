#ifndef ITEMDATALOADER_H
#define ITEMDATALOADER_H

#include <QHash>
#include <QSharedPointer>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>

#include "rapidjson/document.h"
#include "ItemData.h"

template <class T> class ItemDataLoader
{
protected:
    QSharedPointer<QVector<ItemData*>> items = QSharedPointer<QVector<ItemData*>>(reinterpret_cast<QVector<ItemData*>*>(new QVector<T*>()));
    QString url = "https://poe.ninja/api/data/itemoverview?type={type}&league={league}";
    QNetworkReply* currentReply;
    QSharedPointer<QNetworkAccessManager> accessManager;
    QString league;
    virtual void initialize() = 0;
    virtual void parseItem(rapidjson::Value::ConstValueIterator iter)
    {
        ItemData* item = new ItemData();
        item->name = (*iter)["name"].GetString();
        item->chaosValue = (*iter)["chaosValue"].GetDouble();
        items->push_back(item);
    }
    virtual void connect() = 0;
    void onError(QNetworkReply::NetworkError errorCode)//TODO: provide better implementation
    {
         qDebug() << errorCode;
    }
    virtual void readWebsiteContent(QNetworkReply* reply)
    {
        QString websiteContent = reply->readAll();
        rapidjson::Document jsonWebsiteContent;
        jsonWebsiteContent.Parse(websiteContent.toStdString().c_str());
        if(!jsonWebsiteContent.IsNull())
        {
            for(rapidjson::Value::ConstValueIterator iter = jsonWebsiteContent["lines"].Begin(); iter != jsonWebsiteContent["lines"].End(); ++iter)
            {
                parseItem(iter);
            }
        }
    }
public:
    ItemDataLoader(){}
    ItemDataLoader(QNetworkAccessManager* accessManager, QString league) : accessManager(accessManager), league(league){}
    virtual void load()
    {
        initialize();
        currentReply = accessManager->get(QNetworkRequest(QUrl(url)));
        connect();
    }
   QVector<T*>* get()
   {
       return items.get();
   }
};

#endif // ITEMDATALOADER_H
