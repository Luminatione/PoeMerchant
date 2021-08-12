#ifndef MULTIPLEITEMSTYPELOADER_H
#define MULTIPLEITEMSTYPELOADER_H

#include <QObject>

#include "ItemDataLoader.h"

class MultipleItemsTypeLoader : public ItemDataLoader
{
    Q_OBJECT
    QVector<QString> itemTypes;
    void initialize() override;
    void connect() override;
    using ItemDataLoader::readWebsiteContent;
public:
    void load() override;
    MultipleItemsTypeLoader(QNetworkAccessManager* accessManager, QString league, QVector<QString> itemTypes);
};

#endif // MULTIPLEITEMSTYPELOADER_H
