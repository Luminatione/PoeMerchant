import QtQuick 2.15
import QtQuick.Layouts 1.12
import "../PoeControls"


Item {
	Layout.preferredHeight: 80
	Layout.fillWidth: true

	RowLayout
	{
		spacing: 6
		anchors.fill: parent
		PoeLineEdit
		{

			labelText: "";
			placeholderText: "Search Items"
			textEditWidth: 200
			Layout.leftMargin: 5
			Layout.minimumWidth: 200
			Layout.fillWidth: true


		}		
		PoeComboBox
		{
			model: ["Expeditions", "Standard", "Hardcore"]
			labelText: ""
			Layout.minimumWidth: 100
			Layout.preferredWidth: 150
		}
		PoeButton
		{
			text: "Search"
			Layout.minimumWidth: 100
			Layout.rightMargin: 5

		}
	}


	Rectangle
	{
		anchors.fill: parent
		color: "#1f1f1f"
		z: -100
	}
}

