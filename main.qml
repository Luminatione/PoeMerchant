import QtQuick 2.15
import QtQuick.Window 2.15
import "PoeControls"

Window {
	width: 640
	height: 480
	visible: true
	title: qsTr("Poe Merchant")
	PoeLineEdit
	{
		id: lineEdit
		x: 50
		y: 50
	}
	PoeButton
	{
		anchors.left: lineEdit.right
	}
	PoeComboBox
	{
		x: 50
		y: 100
		model: ["aaa", "bbb", "ggsg", "sesfg", "aaa", "bbb", "ggsg", "sesfg"]
	}
}
