#ifndef INVESTITION_H
#define INVESTITION_H

#include <QString>


class Investition
{
    int m_cardAmount;
    QString m_cardName;
    QString m_item;
    QString m_itemColor;
    int m_cost;
    QString m_costCurrencyIcon;
    int m_profit;
    QString m_profitCurrencyIcon;
    int m_itemAmount;

public:
    Investition();

    Investition(int cardAmount, const QString &cardName, const QString &item, const QString &itemColor, int cost, const QString &costCurrencyIcon, int profit, const QString &profitCurrencyIcon, int itemAmount);

    int cardAmount() const;

    const QString &cardName() const;

    const QString &item() const;

    const QString &itemColor() const;

    int cost() const;

    const QString &costCurrencyIcon() const;

    int profit() const;

    const QString &profitCurrencyIcon() const;

    int itemAmount() const;
};

#endif // INVESTITION_H
