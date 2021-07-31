#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QNetworkAccessManager>

#include "DivinationCardLoader.h"
#include "MultipleItemsTypeLoader.h"
#include "EasySellableRewardFilter.h"

DivinationCardLoader* loader;

void print()
{
    auto a = loader->get();
    EasySellableRewardFilter filter;
    filter.filter(a);
    for(auto& card : *a)
    {
        card->translateRewardRawNameToItemData();
        qDebug() << card->reward.name << '\n';
    }
}

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(5, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);
    QNetworkAccessManager* accessManager = new QNetworkAccessManager();
    loader = new DivinationCardLoader(accessManager, "Standard");
    loader->setOnItemsReadyToRead(print);
    loader->load();
    MultipleItemsTypeLoader* itemLoader = new  MultipleItemsTypeLoader(accessManager, "Standard", {"UniqueAccessory", "UniqueArmour", "UniqueWeapon", "UniqueFlask", "UniqueJewel", "DivinationCard", "Prophecy", "SkillGem"});
    itemLoader->loadItems();
    return app.exec();
}

