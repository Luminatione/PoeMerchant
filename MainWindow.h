#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "DivinationCardLoader.h"
#include "EasySellableRewardFilter.h"
#include "ModelSetter.h"
#include "MultipleItemsTypeLoader.h"

#include <QNetworkAccessManager>
#include <QObject>
#include <QQuickView>

class MainWindow : public QObject
{
    Q_OBJECT

    QNetworkAccessManager* accessManager;
    DivinationCardLoader* cardLoader;
    MultipleItemsTypeLoader* itemLoader;
    QQuickView* view;
    std::shared_ptr<EasySellableRewardFilter> filter;
    std::unique_ptr<ModelSetter> modelSetter;

    QStringList itemTypesToLoad = {"UniqueAccessory", "UniqueArmour", "UniqueWeapon", "UniqueFlask", "UniqueJewel", "DivinationCard", "Prophecy", "SkillGem"};

    QString getSelectedLeague();
	QString getSearchLineEditContent();
public:
    explicit MainWindow(QObject *parent = nullptr);
    Q_INVOKABLE void search();
    void showWindow();
signals:

};

#endif // MAINWINDOW_H
