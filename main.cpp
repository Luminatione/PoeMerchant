#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QNetworkAccessManager>
#include <QQuickItem>

#include "DivinationCardLoader.h"
#include "MultipleItemsTypeLoader.h"
#include "EasySellableRewardFilter.h"
#include "ModelSetter.h"
#include "MainWindow.h"

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(5, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
    QGuiApplication app(argc, argv);
    MainWindow* mainWindow = new MainWindow();
    mainWindow->showWindow();

    return app.exec();
}

