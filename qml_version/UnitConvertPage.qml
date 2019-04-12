/*
  Страница конвертации единиц измерения для выбранной физической величины
*/

import QtQuick 2.0
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.2
import "funcs.js" as Funcs

Grid {
    columns: 2
    spacing: 10
    rows: 2
    id: grid
    property string quantityName: "" // Наименование текущей физической величины
    property string outputBorderColor: "red"
    property string outputBackgroundColor: "white"
    property string inputBorderColor: outputBorderColor
    property string inputBackgroundColor: outputBackgroundColor
    property string textColor: "black" // Цвет текста. TODO: распространить на все элементы
    property int precision : 3 // Точность вывода
    property int decimals : 3 //  Количество знаков после запятой при вводе
    property var convertFunc : Funcs.convert // Функция конвертации единиц измерения
    property real fontSize: 0.15 // Размер шрафта. TODO: распространить на все элементы

    SpinBox { // Новый SpinBox работает только с целыми числами
        id: spinBox
        maximumValue : 9999
        minimumValue: -9999
        width: parent.width / 3 - parent.spacing / 2
        height: parent.height / parent.rows - parent.spacing / 2
        decimals: grid.decimals
        style: SpinBoxStyle {
            background: Rectangle {
                border.color: inputBorderColor
                color: inputBackgroundColor
            }
        }
        font.pixelSize: height < width ? height * fontSize : width * fontSize
        onValueChanged: updateUnitValue()
    }

    UnitSelector {
        id: inputUnit
        width: parent.width  * 2 / 3 - parent.spacing / 2
        height: parent.height / parent.rows - parent.spacing / 2
        unitModel : Funcs.getUnit(grid.quantityName)
        onValueModified: updateUnitValue()

        backgroundColor: grid.outputBackgroundColor
        borderColor: grid.outputBorderColor
        textColor: grid.textColor
    }

    Rectangle {
        border.width: 1
        border.color: grid.outputBorderColor
        width: parent.width / 3 - parent.spacing / 2
        height: parent.height / parent.rows - parent.spacing / 2
        TextInput { // TextInput - самый простой способ позволить скопировать результат в буфер обмена, но, к сожалению, не самый удобный.
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            readOnly: true
            selectByMouse: true
            anchors.fill: parent
            id: result
            text: "0"
            font.pixelSize: height < width ? height * fontSize : width * fontSize
        }
        color: grid.outputBackgroundColor
    }

    UnitSelector {
        id: outputUnit
        width: parent.width * 2 / 3 - parent.spacing / 2
        height: parent.height / parent.rows - parent.spacing / 2
        unitModel : Funcs.getUnit(grid.quantityName)
        onValueModified: updateUnitValue()
        backgroundColor: grid.outputBackgroundColor
        borderColor: grid.outputBorderColor
        textColor: grid.textColor
    }

    function updateUnitValue() {
        var v = grid.convertFunc(inputUnit.currentPrefix,  inputUnit.currentUnit,
                                    outputUnit.currentPrefix, outputUnit.currentUnit,
                                    spinBox.value);
        result.text = v.toPrecision(grid.precision);
    }
}
