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
};

#endif // DIVINATIONCARD_H
