import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Layouts 1.12
import "PoeControls"
import "Components"

Item {

	property alias myModel: list.model;

    width: 640
    height: 480

	Image {
		anchors.fill: parent
		source: "qrc:/Graphic/background.jpg"


	ColumnLayout
	{
		anchors.fill: parent
		SearchBar
		{
			Layout.fillWidth: true
			Layout.alignment: Qt.AlignTop
			Layout.preferredHeight: 50
		}
		Rectangle
		{
			Layout.fillHeight: true
			Layout.fillWidth: true
			Layout.margins: 5
			color:"#AA292929"
			border
			{
				width: 1
				color: "#88623b"
			}
			ListView
			{
				id: list
				objectName: "list"
				anchors.fill: parent
				model: [{cardAmount: 9, cardName: "House of Mirrors", item:"Mirror of Kalandra",  itemColor: "#aa9e82", cost: 1, costCurrencyIcon: "qrc:/Graphic/Currency/ChaosOrbIcon.png",
						profit: 999, profitCurrencyIcon: "qrc:/Graphic/Currency/ExaltedOrbIcon.png", itemAmount: 6}]
				clip: true
				delegate: InvestitionItem{

					_cardAmount: cardAmount
					_cardName: cardName
					_resultItem: item
					_resultItemColor: itemColor
					_cost:  cost
					_costCurrencyIcon: costCurrencyIcon
					_profit:  profit
					_profitCurrencyIcon: profitCurrencyIcon
				}
			}
		}
	}
}
}

