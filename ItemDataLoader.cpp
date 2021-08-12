#include "ItemDataLoader.h"
#include "rapidjson/document.h"

void ItemDataLoader::connect()
{
    QObject::connect(currentReply.get(), &QNetworkReply::finished, [this](){readWebsiteContent(currentReply.get());});
}

void ItemDataLoader::initialize()
{
    apiUrl = apiUrl.replace("{type}", itemType).replace("{league}", league);\
}

void ItemDataLoader::parseItem(rapidjson::Value::ConstValueIterator iter)
{
    ItemData* item = new ItemData();
    item->name = (*iter)["name"].GetString();
    item->chaosValue = (*iter)["chaosValue"].GetDouble();
    if((*iter).HasMember("gemLevel"))
    {
        item->gemLevel = (*iter)["gemLevel"].GetInt();
    }
    items->push_back(std::shared_ptr<ItemData>(item));
}

void ItemDataLoader::onError(QNetworkReply::NetworkError errorCode)//TODO: provide better implementation
{
    qDebug() << errorCode;
}

void ItemDataLoader::readWebsiteContent(QNetworkReply *reply)
{
    ++readWebsiteContentHits;
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
    if(readWebsiteContentHits == readWebsiteContentDesiredHits)
    {
        emit allItemsLoaded();
    }
}

void ItemDataLoader::load()
{
    initialize();
    currentReply = std::unique_ptr<QNetworkReply>(accessManager->get(QNetworkRequest(QUrl(apiUrl))));
    connect();
}

QVector<std::shared_ptr<ItemData>>* ItemDataLoader::getItems()
{
    return items.get();
}
