import QtQuick 2.0
import QtQuick.Layouts 1.12
import "../PoeControls"
Item {
	property alias cardAmount: cardAmountLabel.text
	property alias cardName: cardNameLabel.text
	property alias resultItem: resultItemLabel.text
	property alias cost: costLabel.text
	property alias profit: profitLabel.text
	property alias confidency: confidencyLabel.text
	property string profitCurrencyIcon: ""
	property string costCurrencyIcon: ""
	property color resultItemColor: "white"

	property int upperPartFontSize: 17
	implicitHeight: 60
	anchors.right: parent.right
	anchors.left: parent.left
	FontLoader
	{
		id: fontin
		source: "qrc:/Font/Fontin-SmallCaps.ttf"
	}
	Rectangle
	{
		anchors.margins: 3
		anchors.fill: parent
		color: "#303030"
		RowLayout
		{
			anchors.fill: parent
			anchors.margins: 2
			ColumnLayout
			{
				RowLayout
				{
					Text {
						id: cardAmountLabel
						color: "white"
						font
						{
							family: fontin.name
							pixelSize: upperPartFontSize
						}
					}
					Text {
						id: cardNameLabel
						color: "#0ebaf1"
						font
						{
							family: fontin.name
							pixelSize: upperPartFontSize
						}
					}
					Text {
						text: "to"
						color: "white"
						font
						{
							family: fontin.name
							pixelSize: upperPartFontSize
						}

					}
					Text {
						id: resultItemLabel
						font
						{
							family: fontin.name
							pixelSize: upperPartFontSize
						}
						color: resultItemColor
					}
				}
				RowLayout
				{
					spacing: 5
					Text
					{
						text: "Cost: "
						color: "white"
						font
						{
							family: fontin.name
							pixelSize: 15
						}
					}
					Text
					{
						id: costLabel
						color: "#c7a55f"
						font
						{
							family: fontin.name
							pixelSize: 15
						}
					}
					Image
					{
						Layout.preferredWidth: 22
						Layout.preferredHeight: 22
						source: costCurrencyIcon
					}
					Item //spacer
					{
						implicitWidth: 30
					}

					Text
					{
						text: "Profit: "
						color: "white"
						font
						{
							family: fontin.name
							pixelSize: 15
						}
					}
					Text
					{
						id: profitLabel
						color: "#c7a55f"
						font
						{
							family: fontin.name
							pixelSize: 15
						}
					}
					Image
					{
						Layout.preferredWidth: 22
						Layout.preferredHeight: 22
						source: profitCurrencyIcon
					}
					Text
					{
						text: "Confidency: "
						color: "white"
						font
						{
							family: fontin.name
							pixelSize: 15
						}
					}
					Text
					{
						id: confidencyLabel
						color: text>70 ? "#7fbf4b" : text>50 ? "#f0c51a" : "#f0451a"
						font
						{
							family: fontin.name
							pixelSize: 15
						}
					}
					Text
					{
						text: "%"
						color: confidencyLabel.color
						font
						{
							family: fontin.name
							pixelSize: 15
						}
					}
				}
			}

			PoeButton
			{
				Layout.alignment: Qt.AlignRight | Qt.AlignVCenter
				text: "Lookup"
				//mouseAreaObject.onClicked:  <- needs  c++ side

			}
		}
	}
}

