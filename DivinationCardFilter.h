#ifndef DIVINATIONCARDFILTER_H
#define DIVINATIONCARDFILTER_H

#include <QVector>
#include <memory>

#include "DivinationCard.h"

class DivinationCardFilter
{
public:
    DivinationCardFilter(){};
    virtual void filter(QVector<std::shared_ptr<DivinationCard>>* cards) = 0;
    virtual ~DivinationCardFilter(){};
};

#endif // DIVINATIONCARDFILTER_H
