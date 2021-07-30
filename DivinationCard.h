#ifndef DIVINATIONCARD_H
#define DIVINATIONCARD_H

#include <QString>

#include "ItemData.h"

struct DivinationCard : public ItemData
{
    int stackSize;
    QString reward;
};

#endif // DIVINATIONCARD_H
