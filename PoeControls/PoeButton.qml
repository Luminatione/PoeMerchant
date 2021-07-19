import QtQuick 2.0

Item {
	property alias text: label.text

	readonly property int horizontalMargin: 35
	readonly property int verticalMargin: 17

	implicitWidth: label.implicitWidth + horizontalMargin
	implicitHeight: label.implicitHeight + verticalMargin
	FontLoader
	{
		id: fontin
		source: "qrc:/Font/Fontin-SmallCaps.ttf"
	}

	BorderImage
	{
		anchors.fill: parent
		id: image
		source: mouseArea.pressed ? "qrc:/Graphic/PoeButtonClicked.png" : mouseArea.containsMouse ? "qrc:/Graphic/PoeButtonHovered.png" : "qrc:/Graphic/PoeButton.png"
		border
		{
			right: 10
			left: 10
		}
		Text {
			color: "#fec076"
			font.pixelSize: 14
			font.family: fontin.name
			id: label
			text: "LONG TEXT"
			anchors.centerIn: parent
		}

		MouseArea
		{
			id: mouseArea
			anchors.fill: parent
			hoverEnabled: true
		}
	}
}
