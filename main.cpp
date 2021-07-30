#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QNetworkAccessManager>

#include "DivinationCardLoader.h"
#include "MultipleItemsTypeLoader.h"

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
    DivinationCardLoader* loader = new DivinationCardLoader(accessManager, "Standard");
    loader->load();
    MultipleItemsTypeLoader* itemLoader = new  MultipleItemsTypeLoader(accessManager, "Standard", {"UniqueAccessory", "UniqueArmour", "UniqueWeapon", "UniqueFlask", "UniqueJewel", "DivinationCard", "Prophecy", "SkillGem"});
    itemLoader->loadItems();
    return app.exec();
}
