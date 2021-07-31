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
    areAllPagesRequested = false;
    QString urlCopy = url.replace("{league}", league);
    for(int i = 0; i < itemTypes.size(); ++i)
    {
        url = url.replace("{type}", itemTypes[i]);
        load();
        url = urlCopy;
        areAllPagesRequested = i == (itemTypes.size() - 1);
    }
}
