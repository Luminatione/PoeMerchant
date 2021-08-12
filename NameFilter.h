#ifndef NAMEFILTER_H
#define NAMEFILTER_H

#include "DivinationCardFilter.h"

class NameFilter : public DivinationCardFilter
{
	QString pharse;
public:
	NameFilter(QString pharse = "");
	bool match(DivinationCard* card);
	void filter(QVector<std::shared_ptr<DivinationCard>> *cards) override;
};

#endif // NAMEFILTER_H
