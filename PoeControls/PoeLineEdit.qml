import QtQuick 2.0

Item {
	property int textEditLabelMargin: 10
	property int outerMargin: 10
	property alias labelText: label.text
	property color textColor: "#FEEAC5"
	property color labelColor: "#875416"
	property color borderColor: "#88623b"
	property color selectionColor: "#8b5d35"
	property color backgroundColor: "#AA000000"
	property int fontSize: 18
	property int maxLength: 0
	property int textEditWidth: 30
	property alias placeholderText: placeHolder.text
	implicitHeight: 30
	implicitWidth: textEditWidth + label.width + textEditLabelMargin + outerMargin
	FontLoader
	{
		id: fontin
		source: "qrc:/Font/Fontin-SmallCaps.ttf"
	}

	anchors.margins: outerMargin
	Text {
		x: parent.x
		id: label
		text: "text"
		color: labelColor
		font
		{
			pixelSize: fontSize
			family: fontin.name
		}
		anchors
		{
			verticalCenter: parent.verticalCenter
		}
	}
	TextEdit
	{

		verticalAlignment: Qt.AlignVCenter
		x: parent.x + label.width + textEditLabelMargin
		id: textEdit
		width: parent.width - label.width - textEditLabelMargin
		anchors
		{
			top: parent.top
			bottom: parent.bottom
		}
		clip: true
		color: textColor
		cursorVisible: true
		font
		{
			pixelSize: fontSize
			family: fontin.name
		}
		selectByMouse: true
		selectionColor: "#8b5d35"
		onTextChanged:
		{
			if(maxLength > 0 && textEdit.length > maxLength)
			{
				textEdit.remove(maxLength, textEdit.length)
			}
		}


		Rectangle
		{
			z: parent.z-1
			id: border
			anchors.fill: parent
			color: "#AA000000"
			border
			{
				color: borderColor
				width: 1
			}
		}
		Text
		{
			id: placeHolder
			visible: !textEdit.text
			verticalAlignment: Qt.AlignVCenter
			color: labelColor
			anchors.fill: parent
			font
			{
				pixelSize: fontSize
				family: fontin.name
			}
		}
	}

}
