//Main.qml ... creates some buttons on the fly
import QtQuick 2.1
Rectangle{
    id:root
    anchors.fill: parent
    color: "grey"

    signal bottleClicked(int col, int row);

    function bClicked(col, row)
    {
        bottleClicked(col, row);
    }

    function addBottle(x, y, color, col, row)
    {
        //Function creates 4 buttons
        var component = Qt.createComponent("qrc:/Bottle.qml");
        var bottle = component.createObject(root,{"x":x,"y":y,"col":col,"row":row, "color":color});

        //Connect the clicked signal of the newly created button
        //to the event handler buttonClicked.
        bottle.clicked.connect(bClicked)
    }

}
