import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Layouts 1.12
import "PoeControls"
import "Components"

Window {
	width: 640
	height: 480
	visible: true
	title: qsTr("Poe Merchant")

	Rectangle
	{
		anchors.fill: parent
		color: "#363636"
	}

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
			color:"#292929"
			border
			{
				width: 1
				color: "#88623b"
			}
			ListView
			{
				anchors.fill: parent
				model: [{cardAmount: 9, cardName: "House of Mirrors", item:"Mirror of Kalandra",  itemColor: "#aa9e82", investition: 1, investitionCurrencyIcon: "", profit: 999, profitCurrencyIcon: ""}, ]
				clip: true
				delegate: InvestitionItem{
					cardAmount: modelData.cardAmount
					cardName: modelData.cardName
					resultItem: modelData.item
					resultItemColor: modelData.itemColor
				}
			}
		}
	}
}
