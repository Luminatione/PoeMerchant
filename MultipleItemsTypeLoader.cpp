#include "MultipleItemsTypeLoader.h"

void MultipleItemsTypeLoader::initialize()
{
    //doesn't have to do anything since evrything is done inside load() method
}

void MultipleItemsTypeLoader::connect()
{
    //doesn't have to do anything since evrything is done inside load() method
}

void MultipleItemsTypeLoader::load()
{
    QNetworkRequest request;
    request.setUrl(url);
    QNetworkReply* reply = accessManager->get(request);
    QObject::connect(reply, &QNetworkReply::finished,this, [this,  reply](){
        readWebsiteContent(reply);
    });
    QObject::connect(reply, &QNetworkReply::errorOccurred,[this](){ onError(QNetworkReply::BackgroundRequestNotAllowedError);});
}

MultipleItemsTypeLoader::MultipleItemsTypeLoader(QNetworkAccessManager *accessManager, QString league, QVector<QString> itemTypes) : ItemDataLoader<ItemData>(accessManager, league), itemTypes(itemTypes){}

void MultipleItemsTypeLoader::loadItems()
{
    QString urlCopy = url.replace("{league}", league);
    for(QString& type : itemTypes)
    {
        url = url.replace("{type}", type);
        load();
        url = urlCopy;
    }
}
