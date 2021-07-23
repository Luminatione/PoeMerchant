#ifndef DIVINATIONCARDFILTER_H
#define DIVINATIONCARDFILTER_H

#include <QVector>

#include "DivinationCard.h"

class DivinationCardFilter
{
public:
    virtual void filter(QVector<DivinationCard> &cards) = 0;
};

#endif // DIVINATIONCARDFILTER_H
