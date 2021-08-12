#include "InvestitionModelFactory.h"

#include <QtAlgorithms>
#include <map>
#include <qdebug.h>

void InvestitionModelFactory::translateRewardRawNameToItemData(DivinationCard *divinationCard)
{
    QString rewardName = QRegularExpression("\{(.*?)\}").match(divinationCard->rewardRawName).captured(1);
    QString amountStr = QRegularExpression("[\\d]+x").match(rewardName).captured(0);
    int gemLevel = 0;
    if(!amountStr.isEmpty())
    {
        rewardName = rewardName.remove(amountStr);
    }
    if(rewardName.contains("Level "))
    {
        gemLevel = rewardName.mid(5, 2).toInt();
        rewardName = rewardName.remove(0, 8) + " Support";
    }
    if(rewardName[0] == ' ')
    {
        rewardName = rewardName.remove(0, 1);
    }
    divinationCard->reward = {rewardName, amountStr.replace("x", "").toInt(), 1, gemLevel};

}

QString InvestitionModelFactory::getRewardItemColor(DivinationCard *divinationCard)
{
    std::map<QString, QString> keywordsAndItsColors = {{"<prophecy>", "#b54bff"}, {"<currencyitem>", "#aa9e82"}, {"<uniqueitem>", "#af6025"}, {"<divination>", "#0ebaff"}, {"<gemitem>", "#1ba29b"}};
    for(auto &entery : keywordsAndItsColors)
    {
        if(divinationCard->rewardRawName.contains(entery.first))
        {
            return entery.second;
        }
    }
}

InvestitionModelFactory::InvestitionModelFactory(){}

InvestitionModelFactory::InvestitionModelFactory(const QVector<std::shared_ptr<DivinationCard>> &cards, const QVector<std::shared_ptr<ItemData>> &items, const QVector<DivinationCardFilter *> &filters) : cards(cards),
    items(items),
    filters(filters){}

InvestitionModelFactory::~InvestitionModelFactory()
{
}

InvestitionModel* InvestitionModelFactory::getModel()
{
    model = new InvestitionModel();
    return model;
}

void InvestitionModelFactory::populateModel()
{
    for(auto filter : qAsConst(filters))
    {
        filter->filter(&cards);
    }
    for(auto card : qAsConst(cards))
    {
        translateRewardRawNameToItemData(card.get());
        auto correspondingItem = std::find_if(items.begin(), items.end(), [card](std::shared_ptr<ItemData> item)
        {
                return item->name == card->reward.name && ((item->gemLevel == card->reward.gemLevel && card->reward.gemLevel != 0) || card->reward.gemLevel == 0);
        });
        if(correspondingItem == items.end())
        {
            continue;
        }
        Investition investition {card->stackSize, card->name, (*correspondingItem)->name, getRewardItemColor(card.get()), card->stackSize*card->chaosValue,
                    "qrc:/Graphic/Currency/ChaosOrbIcon.png", (*correspondingItem)->chaosValue*(*correspondingItem)->amount - card->stackSize*card->chaosValue,
                    "qrc:/Graphic/Currency/ChaosOrbIcon.png", (*correspondingItem)->amount};

        model->addInvestition(investition);

    }
}

void InvestitionModelFactory::initialize(const QVector<std::shared_ptr<DivinationCard>> &cards, const QVector<std::shared_ptr<ItemData>> &items, const QVector<DivinationCardFilter *> &filters)
{
    this->cards = cards;
    this->items = items;
    this->filters = filters;
}

void InvestitionModelFactory::clear()
{
    model->clear();
}
