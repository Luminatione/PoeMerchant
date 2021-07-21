import QtQuick 2.0
import QtQuick.Layouts 1.12

Item {
	property alias cardAmount: cardAmountLabel.text
	property alias cardName: cardNameLabel.text
	property alias resultItem: resultItemLabel.text
	property color resultItemColor: "white"
	anchors.fill: parent

	FontLoader
	{
		id: fontin
		source: "qrc:/Font/Fontin-SmallCaps.ttf"
	}
	Rectangle
	{
		anchors.margins: 3
		anchors.fill: parent
		color: "#525252"
		RowLayout
		{
			Text {
				id: cardAmountLabel
				color: "white"
				font
				{
					family: fontin.name
					pixelSize: 15
				}
			}
			Text {
				id: cardNameLabel
				color: "#0ebaf1"
				font
				{
					family: fontin.name
					pixelSize: 15
				}
			}
			Text {
				text: "to"
				color: "white"
				font
				{
					family: fontin.name
					pixelSize: 15
				}

			}
			Text {
				id: resultItemLabel
				font
				{
					family: fontin.name
					pixelSize: 15
				}
				color: resultItemColor
			}
		}


	}

}
