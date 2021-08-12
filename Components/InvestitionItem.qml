import QtQuick 2.0
import QtQuick.Layouts 1.12
import QtQuick.Window 2.12
import "../PoeControls"
Item {
	property alias _cardAmount: cardAmountLabel.text
	property alias _cardName: cardNameLabel.text
	property alias _resultItem: resultItemLabel.text
	property alias _cost: costLabel.text
	property alias _profit: profitLabel.text
	property string _profitCurrencyIcon: ""
	property string _costCurrencyIcon: ""
	property color _resultItemColor: "white"

	property int upperPartFontSize: 17
	implicitHeight: 60
    anchors.right: parent ? parent.right : undefined
    anchors.left: parent ? parent.left : undefined
    TextEdit
    {
        id: copyTextEdit
        visible: false
    }
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
                        MouseArea {
                            anchors.fill: parent;
                            onClicked:
                            {
                                copyTextEdit.text = parent.text;
                                copyTextEdit.selectAll();
                                copyTextEdit.copy();
                            }
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
						color: _resultItemColor
                        MouseArea {
                            anchors.fill: parent;
                            onClicked:
                            {
                                copyTextEdit.text = parent.text;
                                copyTextEdit.selectAll();
                                copyTextEdit.copy();
                            }
                        }
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
				}
			}
		}
	}
}

