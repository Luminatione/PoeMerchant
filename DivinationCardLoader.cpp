#include "DivinationCardLoader.h"
#include "rapidjson/document.h"

void DivinationCardLoader::parseItem(rapidjson::Value::ConstValueIterator iter)
{
    DivinationCard* card = new DivinationCard();
    card->name = (*iter)["name"].GetString();
    card->rewardRawName = (*iter)["explicitModifiers"][0]["text"].GetString();
    card->chaosValue = (*iter)["chaosValue"].GetDouble();
    if((*iter).HasMember("stackSize"))
    {
        card->stackSize = (*iter)["stackSize"].GetInt();
    }
    else
    {
        card->stackSize = 1;
    }
    items->push_back(std::shared_ptr<ItemData>(card));
}
