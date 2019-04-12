/*
  Элемент выбора единицы измерения и префикса к ней
*/

import QtQuick 2.0
import QtQuick.Controls 2.2
import "funcs.js" as Funcs

Row {
    signal valueModified
    spacing: 2
    id: row
    property alias unitModel: unit.model // Набор единиц измерения (задаётся извне)
    property var prefixModel: Funcs.getPrefix(unit.currentText) // Набор единиц измерения
    property alias currentPrefix: prefix.currentText // Текущий префикс
    property alias currentUnit: unit.currentText // Текущая единица измерения
    property string backgroundColor: "red" // Цвет фона
    property string borderColor: "blue" // Цвет границы
    property string textColor: "black" // Цвет текста

    //TODO: добавить возможность менять размер шрифта и цвет текста у ComboBox
    ComboBox {
        id: prefix
        model: row.prefixModel
        width: parent.width / 2 - parent.spacing
        height: parent.height - parent.spacing
        enabled: true
        onActivated: valueModified()
        background: Rectangle {
            color: backgroundColor
            border.color: borderColor
        }
    }
    ComboBox {
        id: unit
        width: parent.width / 2 - parent.spacing
        height: parent.height - parent.spacing
        onActivated: valueModified()
        background: Rectangle {
            color: backgroundColor
            border.color: borderColor
        }
    }
}
