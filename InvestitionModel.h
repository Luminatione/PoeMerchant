#ifndef INVESTITIONMODEL_H
#define INVESTITIONMODEL_H

#include <QObject>
#include <QAbstractListModel>

#include "Investition.h"

class InvestitionModel : public QAbstractListModel
{
    Q_OBJECT
public:
    InvestitionModel(QObject *parent = nullptr);

    enum InvestitionRoles
     {
        CardAmountRole = Qt::UserRole,
        CardNameRole,
        ItemRole,
        ItemColorRole,
        CostRole,
        CostCurrencyIconRole,
        ProfitRole,
        ProfitCurrencyIconRole,
        ItemAmountRole,
    };

    void addInvestition(Investition& inverstition);

    int rowCount(const QModelIndex& parent = QModelIndex())const override;

    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;

    void clear();

protected:

    QHash<int, QByteArray> roleNames()const override;

public:

    QList<Investition> investitions;
};

#endif // INVESTITIONMODEL_H
