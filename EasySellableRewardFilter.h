#ifndef EASYSELLABLEREWARDFILTER_H
#define EASYSELLABLEREWARDFILTER_H

#include "DivinationCardFilter.h"

class EasySellableRewardFilter : public DivinationCardFilter
{
    QVector<QString> blacklistedKeywords {"<rareitem>", "<whiteitem>", "<magicitem>", "<normal>", " Item", "Item "};
public:
    EasySellableRewardFilter(){};
    void filter(QVector<std::shared_ptr<DivinationCard>>* cards) override;
};

#endif // EASYSELLABLEREWARDFILTER_H
