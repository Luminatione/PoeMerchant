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
    readWebsiteContentDesiredHits = itemTypes.size();
    QString urlCopy = apiUrl.replace("{league}", league);
    for(int i = 0; i < itemTypes.size(); ++i)
    {
        apiUrl = apiUrl.replace("{type}", itemTypes[i]);
            QNetworkRequest request;
            request.setUrl(apiUrl);
            QNetworkReply* reply = accessManager->get(request);
            QObject::connect(reply, &QNetworkReply::finished,this, [this,  reply](){
                readWebsiteContent(reply);
            });
        apiUrl = urlCopy;
    }
}

MultipleItemsTypeLoader::MultipleItemsTypeLoader(QNetworkAccessManager *accessManager, QString league, QVector<QString> itemTypes) : ItemDataLoader(accessManager, league), itemTypes(itemTypes){}
