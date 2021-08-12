#include "EasySellableRewardFilter.h"
#include "InvestitionModelFactory.h"
#include "ModelSetter.h"

#include <QQuickItem>

ModelSetter::ModelSetter(ItemDataLoader* cardsLoader, const QVector<ItemDataLoader*> &itemsLoaders, QVector<DivinationCardFilter*> filters, QQuickView* list) : cardsLoader(cardsLoader),
    itemsLoaders(itemsLoaders),
    filters(filters)
{
    this->list = list;
}

void ModelSetter::setModel()
{
    ++loadedData;
    if(loadedData == itemsLoaders.count() + 1)//if all itemsLoaders and cardLoader called this method
    {
        QVector<std::shared_ptr<ItemData>>* temp = cardsLoader->getItems();
        cards = reinterpret_cast<QVector<std::shared_ptr<DivinationCard>>*>(temp);
        for(auto& itemLoader : itemsLoaders)
        {
            items.append(*(itemLoader->getItems()));
        }
        modelFactory.initialize(*cards, items, filters);
        modelFactory.populateModel();
        loadedData = 0;
    }
}

ModelSetter::ModelSetter(QObject *parent) : QObject(parent){}


ModelSetter::~ModelSetter()
{
    for(auto& itemLoader : itemsLoaders)
    {
        delete itemLoader;
    }
}

void ModelSetter::initialize(ItemDataLoader *cardsLoader, const QVector<ItemDataLoader *> &itemsLoaders, QVector<DivinationCardFilter *> filters)
{
    this->cardsLoader = cardsLoader;
    this->itemsLoaders = itemsLoaders;
    this->filters = filters;
    this->list = list;
}

void ModelSetter::beginPopulatingModel()
{
    cardsLoader->load();
    connect(cardsLoader, &ItemDataLoader::allItemsLoaded, this, &ModelSetter::setModel);
    for(auto itemLoader : qAsConst(itemsLoaders))
    {
        itemLoader->load();
        connect(itemLoader, &ItemDataLoader::allItemsLoaded, this, &ModelSetter::setModel);
    }
}

void ModelSetter::setEmptyModel(QQuickView *list)
{
    modelFactory = InvestitionModelFactory();
    list->setInitialProperties({{"myModel", QVariant::fromValue(modelFactory.getModel())}});
    emit modelIsSet();
}

void ModelSetter::clearModel()
{
    modelFactory.clear();
}
