#ifndef MULTIPLEITEMSTYPELOADER_H
#define MULTIPLEITEMSTYPELOADER_H

#include <QObject>

#include "ItemDataLoader.h"

class MultipleItemsTypeLoader : public QObject, public ItemDataLoader<ItemData>
{
    Q_OBJECT
    QVector<QString> itemTypes;
    void initialize() override;
    void connect() override;
    void load() override;
    using ItemDataLoader<ItemData>::readWebsiteContent;
public:
    MultipleItemsTypeLoader(QNetworkAccessManager* accessManager, QString league, QVector<QString> itemTypes);
    void loadItems();
};

#endif // MULTIPLEITEMSTYPELOADER_H
