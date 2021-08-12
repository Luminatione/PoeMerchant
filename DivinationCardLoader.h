#ifndef DIVINATIONCARDLOADER_H
#define DIVINATIONCARDLOADER_H

#include "rapidjson/document.h"
#include "DivinationCard.h"
#include "ItemDataLoader.h"


class  DivinationCardLoader : public ItemDataLoader
{
    Q_OBJECT
    void parseItem(rapidjson::Value::ConstValueIterator iter) override;
public:
    DivinationCardLoader(QNetworkAccessManager* accessManager, QString league) : ItemDataLoader(accessManager, league)
    {
        itemType = "DivinationCard";
    }
};

#endif // DIVINATIONCARDLOADER_H
