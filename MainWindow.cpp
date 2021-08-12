#include "EasySellableRewardFilter.h"
#include "MainWindow.h"
#include "ModelSetter.h"
#include "NameFilter.h"

#include <QQuickItem>

QString MainWindow::getSelectedLeague()
{
	return view->rootObject()->findChild<QObject*>("leagueSelection")->property("selectedOptionText").toString();
}

QString MainWindow::getSearchLineEditContent()
{
	return view->rootObject()->findChild<QObject*>("searchLineEdit")->property("text").toString();
}

MainWindow::MainWindow(QObject *parent) : QObject(parent)
{
    filter = std::unique_ptr<EasySellableRewardFilter>(new EasySellableRewardFilter());
    accessManager = new QNetworkAccessManager(this);
    view = new QQuickView();
    view->setResizeMode(QQuickView::SizeRootObjectToView);
    qmlRegisterType<MainWindow>("com.MainWindow", 1, 0, "MainWindow");
}

void MainWindow::search()
{
    modelSetter.get()->clearModel();
    cardLoader = new DivinationCardLoader(accessManager, getSelectedLeague());
    itemLoader = new  MultipleItemsTypeLoader(accessManager, getSelectedLeague(), itemTypesToLoad.toVector());
	modelSetter->initialize(cardLoader, {itemLoader}, {new EasySellableRewardFilter(), new NameFilter(getSearchLineEditContent())});
    modelSetter->beginPopulatingModel();
}

void MainWindow::showWindow()
{
    modelSetter = std::unique_ptr<ModelSetter>(new ModelSetter(this));
    modelSetter->setEmptyModel(view);
    view->setSource(QUrl("qrc:/main.qml"));
    view->show();
    view->rootObject()->findChild<QObject*>("searchButton")->setProperty("mainWindow", QVariant::fromValue(this));
    search();
}

