#include "Investition.h""

int Investition::cardAmount() const
{
    return m_cardAmount;
}

const QString &Investition::cardName() const
{
    return m_cardName;
}

const QString &Investition::item() const
{
    return m_item;
}

const QString &Investition::itemColor() const
{
    return m_itemColor;
}

int Investition::cost() const
{
    return m_cost;
}

const QString &Investition::costCurrencyIcon() const
{
    return m_costCurrencyIcon;
}

int Investition::profit() const
{
    return m_profit;
}

const QString &Investition::profitCurrencyIcon() const
{
    return m_profitCurrencyIcon;
}

int Investition::itemAmount() const
{
    return m_itemAmount;
}

Investition::Investition(){}

Investition::Investition(int cardAmount, const QString &cardName, const QString &item, const QString &itemColor, int cost, const QString &costCurrencyIcon, int profit, const QString &profitCurrencyIcon, int itemAmount) : m_cardAmount(cardAmount),
    m_cardName(cardName),
    m_item(item),
    m_itemColor(itemColor),
    m_cost(cost),
    m_costCurrencyIcon(costCurrencyIcon),
    m_profit(profit),
    m_profitCurrencyIcon(profitCurrencyIcon),
    m_itemAmount(itemAmount)
{}

