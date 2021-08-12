import QtQuick 2.15
import QtQuick.Controls 2.15
Item {
	property alias selectedOptionText: comboBox.currentText
	property int comboboxLabelMargin: 10
	property int outerMargin: 10
	property alias labelText: label.text
	property color textColor: "#FEEAC5"
	property color labelColor: "#875416"
	property color borderColor: "#88623b"
	property color selectionColor: "#8b5d35"
	property color backgroundColor: "#000000"
	property color popupBackgroundColor: "#000000"
	property color highligtedTextColor: "#fec176"
	property int fontSize: 18
	property int textEditWidth: 30
	property alias model: comboBox.model
	implicitWidth:  200
	implicitHeight: 30
	FontLoader
	{
		id: fontin
		source: "qrc:/Font/Fontin-SmallCaps.ttf"
	}
	ComboBox
	{
		id: comboBox
		x: parent.x + label.width + comboboxLabelMargin
		width: parent.width - label.width
		anchors.fill: parent
		background: Rectangle
		{
			color: backgroundColor
			border
			{
				width: 1
				color: borderColor
			}
		}
		delegate: ItemDelegate
		{
			width: comboBox.width
			height: 20
			contentItem: Text {
				id: itemText
				text: modelData
				color:  parent.highlighted ? highligtedTextColor : textColor
				verticalAlignment: Text.AlignVCenter
				font
				{
					family: fontin.name
					pixelSize: fontSize
				}
			}
			MouseArea
			{
				anchors.fill: parent
				onClicked:
				{
					comboBox.currentIndex = index;
					comboBox.popup.visible = false
				}
			}
		}


		contentItem: Text {
			text: comboBox.displayText
			font
			{
				family: fontin.name
				pixelSize: fontSize
			}
			color: textColor
			verticalAlignment: Text.AlignVCenter
			elide: Text.ElideLeft
			leftPadding: 10
		}
		popup: Popup
		{
			y:comboBox.height - 1
			width: comboBox.width
			implicitHeight: contentItem.implicitHeight
			padding: 0
			contentItem: ListView
			{
				clip: true
				implicitHeight: contentHeight
				model: comboBox.popup.visible ? comboBox.delegateModel : null
				currentIndex: comboBox.highlightedIndex
				ScrollIndicator.vertical: ScrollIndicator{}
				highlight: Rectangle
				{
					color: selectionColor
				}
			}
			background: Rectangle
			{
				color: popupBackgroundColor
				border
				{
					color: borderColor
					width: 1
				}
			}
		}
		indicator: Image {
			source: "qrc:/Graphic/PoeComboboxIcon.png"
			x: comboBox.width - width - 3
			y: comboBox.topPadding + (comboBox.availableHeight - height)/2

		}
	}
	Text {
		id: label
		font
		{
			family: fontin.name
			pixelSize: fontSize
		}
		anchors
		{
			top: parent.top
			bottom: parent.bottom
		}
		text: "text"
		x: parent.x
		width: implicitWidth
		color:  labelColor
		verticalAlignment: Text.AlignVCenter
	}
}
