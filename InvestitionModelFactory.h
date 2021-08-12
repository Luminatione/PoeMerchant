#ifndef INVESTITIONMODELFACTORY_H
#define INVESTITIONMODELFACTORY_H

#include <InvestitionModel.h>
#include <QObject>
#include <QSharedPointer>

#include "DivinationCard.h"
#include "DivinationCardFilter.h"


class InvestitionModelFactory
{
   QVector<std::shared_ptr<DivinationCard>> cards;
   QVector<std::shared_ptr<ItemData>> items;
   QVector<DivinationCardFilter*> filters;
    InvestitionModel* model;
   void translateRewardRawNameToItemData(DivinationCard* divinationCard);
   QString getRewardItemColor(DivinationCard* divinationCard);
public:

   explicit InvestitionModelFactory();

   InvestitionModelFactory(const QVector<std::shared_ptr<DivinationCard>> &cards, const QVector<std::shared_ptr<ItemData>> &items, const QVector<DivinationCardFilter *> &filters);

    ~InvestitionModelFactory();

    InvestitionModel* getModel();
    void populateModel();
    void initialize(const QVector<std::shared_ptr<DivinationCard>> &cards, const QVector<std::shared_ptr<ItemData>> &items, const QVector<DivinationCardFilter *> &filters);
    void clear();
};

#endif // INVESTITIONMODELFACTORY_H
