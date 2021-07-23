#ifndef ITEMDATALOADER_H
#define ITEMDATALOADER_H

#include <QHash>
#include <QSharedPointer>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>

#include "ItemData.h"

template <class T> class ItemDataLoader : public QObject
{
    Q_OBJECT
    QSharedPointer<QVector<ItemData*>> items = QSharedPointer<QVector<T*>>(new QVector<T*>());
    QString url = "https://poe.ninja/api/data/itemoverview?type=DivinationCard&league=Standard";
    QNetworkReply* currentReply;
    QSharedPointer<QNetworkAccessManager> accessManager;

    virtual void readWebsiteContent() = 0;

    void onError(QNetworkReply::NetworkError errorCode)//TODO: provide better implementation
    {
         qDebug() << errorCode;
    }
public:
    ItemDataLoader()
    {

    }
    ItemDataLoader(QNetworkAccessManager* accessManager) : accessManager(accessManager)
    {

    }
    void load()
    {
        currentReply = accessManager->get(QNetworkRequest(QUrl(url)));
        connect(accessManager.get(), &QNetworkAccessManager::finished, this, &ItemDataLoader::readWebsiteContent);
        connect(currentReply, &QNetworkReply::errorOccurred, this, &ItemDataLoader::onError);
    }
   QVector<T*>* get()
   {
       return items.get();
   }
};

#endif // ITEMDATALOADER_H
