//Button.qml ... This component's objects will be dynamically
// created
import QtQuick 2.1

Rectangle {
    width: 20
    height: 20
    radius: 10
    property int col;
    property int row;
    signal clicked(int col, int row);

    MouseArea {
        anchors.fill: parent
        onClicked:parent.clicked(parent.col, parent.row)
    }
}
