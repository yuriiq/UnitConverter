/*
Кнопка, которая умеет
- выводить текст
- масштабировать текст в зависимости от своего размера
- посылать сигнал о нажатии
*/

import QtQuick 2.0
Rectangle {
    signal clicked
    property alias text: text.text
    property real textHeight: height - 2
    property real textWidth: width - 2
    property real fontSize: 0.3
    property bool pressed: mouse.pressed
    property real implicitMargin: (width - text.implicitWidth) / 2
    property string textColor: "#1b1c1d"
    id: button
    border.width: 1
    border.color: "blue"

    Text {
        id: text
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.top: parent.top
        height: parent.textHeight
        width: parent.textWidth
        color: parent.textColor
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        font.pixelSize: height < width ? height * fontSize : width * fontSize
        font.family: "Open Sans Regular"
    }

    MouseArea {
        id: mouse
        anchors.fill: parent
        onClicked: button.clicked()
    }
}
