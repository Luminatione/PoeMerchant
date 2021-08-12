import QtQuick 2.15
import QtQuick.Layouts 1.12
import "../PoeControls"
import com.MainWindow 1

Item {
	Layout.preferredHeight: 80
	Layout.fillWidth: true

	RowLayout
	{
		spacing: 6
		anchors.fill: parent
		PoeLineEdit
		{
            objectName: "searchLineEdit"
			labelText: "";
			placeholderText: "Search Items"
			textEditWidth: 200
			Layout.leftMargin: 5
			Layout.minimumWidth: 200
			Layout.fillWidth: true


		}		
		PoeComboBox
		{
			id: leagueSelection
			objectName: "leagueSelection"
			model: ["Expedition", "Standard"]
			labelText: ""
			Layout.minimumWidth: 100
			Layout.preferredWidth: 150
		}
		PoeButton
		{
			objectName: "searchButton"
			property MainWindow mainWindow
			text: "Search"
			Layout.minimumWidth: 100
			Layout.rightMargin: 5
			mouseAreaObject.onClicked:
			{
				mainWindow.search();
			}
		}
	}


	Rectangle
	{
		anchors.fill: parent
		color: "#1f1f1f"
		z: -100
	}
}

