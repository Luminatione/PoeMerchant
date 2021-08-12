#ifndef ITEMDATA_H
#define ITEMDATA_H
#include <QString>

struct ItemData
{
    QString name;
    int chaosValue;
    int amount = 1;
    int gemLevel = 0;
};

#endif // ITEMDATA_H
