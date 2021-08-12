#ifndef MODELSETTER_H
#define MODELSETTER_H

#include "DivinationCardFilter.h"
#include "InvestitionModel.h"
#include "InvestitionModelFactory.h"
#include "ItemDataLoader.h"

#include <QObject>
#include <QQuickView>

class ModelSetter : public QObject
{
    Q_OBJECT

    ItemDataLoader* cardsLoader;
    QVector<ItemDataLoader*> itemsLoaders;
    QVector<std::shared_ptr<ItemData>> items;
    QQuickView* list;
    QVector<DivinationCardFilter*> filters;
    QVector<std::shared_ptr<DivinationCard>>* cards;
    InvestitionModelFactory modelFactory;

    int loadedData = 0;

    void setModel();
public:
    explicit ModelSetter(QObject *parent = nullptr);
    ModelSetter(ItemDataLoader *cardsLoader, const QVector<ItemDataLoader *> &itemsLoaders, QVector<DivinationCardFilter*> filters, QQuickView* list);
    ~ModelSetter();
    void initialize(ItemDataLoader *cardsLoader, const QVector<ItemDataLoader *> &itemsLoaders, QVector<DivinationCardFilter*> filters);
    void beginPopulatingModel();
    void setEmptyModel(QQuickView *list);
    void clearModel();
signals:
    void modelIsSet();
};

#endif // MODELSETTER_H
