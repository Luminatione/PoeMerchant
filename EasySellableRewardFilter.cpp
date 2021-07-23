#include "EasySellableRewardFilter.h"

void EasySellableRewardFilter::filter(QVector<DivinationCard> &cards)
{
    for(int i = 0; i < cards.size(); ++i)
    {
        for(int j = 0; j < blacklistedKeywords.size(); ++j)
        {
            if(cards[i].reward.contains(blacklistedKeywords[j]))
            {
                cards.remove(i);
                --i;
                break;
            }
        }
    }
}
