#include "InvestitionModel.h"

InvestitionModel::InvestitionModel(QObject *parent) : QAbstractListModel(parent){}

void InvestitionModel::addInvestition(Investition &investition)
{
    beginInsertRows(QModelIndex(), rowCount(), rowCount());
    investitions << investition;
    endInsertRows();
}

int InvestitionModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return investitions.count();
}

QVariant InvestitionModel::data(const QModelIndex &index, int role) const
{
    if(index.row() < 0 || index.row() >= investitions.count())
    {
        return QVariant();
    }

    switch (role) {
        case CardAmountRole:
        {
            return investitions[index.row()].cardAmount();
        }
        case  CardNameRole:
        {
            return investitions[index.row()].cardName();
        }
        case ItemRole:
        {
            return investitions[index.row()].item();
        }
        case ItemColorRole:
        {
            return investitions[index.row()].itemColor();
        }
        case CostRole:
        {
            return investitions[index.row()].cost();
        }
        case CostCurrencyIconRole:
        {
            return investitions[index.row()].costCurrencyIcon();
        }
        case ProfitRole:
        {
            return investitions[index.row()].profit();
        }
        case ProfitCurrencyIconRole:
        {
            return investitions[index.row()].profitCurrencyIcon();
        }
        case ItemAmountRole:
        {
            return investitions[index.row()].itemAmount();
        }
        default:
            return QVariant();
    }
}

void InvestitionModel::clear()
{
    if(investitions.count() > 0)
    {
        beginRemoveRows(QModelIndex(), 0, rowCount() - 1);
        investitions.clear();
        endRemoveRows();
    }
}

QHash<int, QByteArray> InvestitionModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[CardAmountRole] = "cardAmount";
    roles[CardNameRole] = "cardName";
    roles[ItemRole] = "item";
    roles[ItemColorRole] = "itemColor";
    roles[CostRole] = "cost";
    roles[CostCurrencyIconRole] = "costCurrencyIcon";
    roles[ProfitRole] = "profit";
    roles[ProfitCurrencyIconRole] = "profitCurrencyIcon";
    roles[ItemAmountRole] = "itemAmount";
    return roles;
}
