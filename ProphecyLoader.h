#ifndef PROPHECYLOADER_H
#define PROPHECYLOADER_H

#include "ItemDataLoader.h"
#include <QObject>

class ProphecyLoader :public QObject, public ItemDataLoader<ItemData>
{
    Q_OBJECT
    DATA_LOADER("Prophecy");
public:
    using ItemDataLoader::ItemDataLoader;
};

#endif // PROPHECYLOADER_H
