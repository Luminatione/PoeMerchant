#include "NameFilter.h"

NameFilter::NameFilter(QString pharse) : pharse(pharse)
{
	pharse = pharse.toLower();
}

bool NameFilter::match(DivinationCard *card)
{
	bool isNumber;
	int pharseValue = pharse.toInt(&isNumber);
	return pharse.isEmpty() || card->name.toLower().contains(pharse) || card->rewardRawName.toLower().contains(pharse) || card->reward.name.toLower().contains(pharse) ||
			(isNumber && (card->amount == pharseValue || card->chaosValue == pharseValue ||
						 card->stackSize == pharseValue || card->reward.chaosValue == pharseValue ||
						 card->reward.amount == pharseValue));//if any field of card contains pharse or pharse is empty
}

void NameFilter::filter(QVector<std::shared_ptr<DivinationCard> > *cards)
{
	for(int i = 0; i < cards->size(); ++i)
	{
		if(match(cards->at(i).get()))
		{
			continue;
		}
		cards->remove(i);
		--i;
	}
}
