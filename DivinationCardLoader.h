#ifndef DIVINATIONCARDLOADER_H
#define DIVINATIONCARDLOADER_H

#include "rapidjson/document.h"
#include "DivinationCard.h"
#include "ItemDataLoader.h"


class  DivinationCardLoader : public QObject, public ItemDataLoader<DivinationCard>
{
    Q_OBJECT
    DATA_LOADER("DivinationCard")
    void parseItem(rapidjson::Value::ConstValueIterator iter) override;
public:
    using ItemDataLoader::ItemDataLoader;
};

#endif // DIVINATIONCARDLOADER_H
