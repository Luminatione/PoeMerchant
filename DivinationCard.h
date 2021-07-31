#ifndef DIVINATIONCARD_H
#define DIVINATIONCARD_H

#include <QString>
#include <QRegularExpression>

#include "ItemData.h"


struct DivinationCard : public ItemData
{
    int stackSize;
    QString rewardRawName;
    ItemData reward;
    void translateRewardRawNameToItemData()
    {
        QString rewardName = QRegularExpression("\{(.*?)\}").match(rewardRawName).captured(1);
        QString amountStr = QRegularExpression("[\\d]+x").match(rewardName).captured(0);
        if(!amountStr.isEmpty())
        {
            rewardName = rewardName.remove(amountStr);
        }
        reward = {rewardName, amountStr.replace("x", "").toInt()};

    }
};

#endif // DIVINATIONCARD_H
