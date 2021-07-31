#ifndef EASYSELLABLEREWARDFILTER_H
#define EASYSELLABLEREWARDFILTER_H

#include "DivinationCardFilter.h"

class EasySellableRewardFilter : public DivinationCardFilter
{
    QVector<QString> blacklistedKeywords {"<rareitem>", "<whiteitem>", "<magicitem>", "<normal>", " Item", "Item "};
public:
    void filter(QVector<DivinationCard*>* cards) override;
};

#endif // EASYSELLABLEREWARDFILTER_H
