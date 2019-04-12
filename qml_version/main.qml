import QtQuick.Window 2.2
import QtQuick.Controls 2.2

Window {
    visible: true
    width: 400
    height: 400
    id: window
    title: "UnitConverter"
    UnitConverter {
        anchors.fill: parent
        header: "---"
        selectColor: "#83BE94"
        outputBackgroundColor: "#D1E1C6"
        precision: 5
    }
}
