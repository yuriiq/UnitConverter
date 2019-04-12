/*
  Страница выбора физической величины.
  Получает список визических величин через quantitis
  и отображает их в виде столбика кнопок
*/

import QtQuick 2.0
import "funcs.js" as Funcs

Rectangle {
    property alias model : dataModel // Модель с физическими величинами
    property int buttonHeight: 100 // Высота одной кнопки
    property string selectColor : "red" // Цвет выбранной физической величины
    property string defaultColor: Funcs.defColor() // Цвет невыбранной физической величины
    property var quantity: Funcs.getQuantity() // Набор доступных физических величин
    signal clicked(string text) // Сигнал, который испускается при выборе физической величины
    id: selectPage

    ListModel {
        id: dataModel
    }

    ListView {
        id: view
        anchors.fill: parent
        spacing: 10
        model: selectPage.model

        delegate: Button {
            id: button
            width: view.width
            height: selectPage.buttonHeight
            color: itemColor
            text: name
            onClicked: {
                resetColor();
                itemColor = selectPage.selectColor;
                selectPage.clicked(text);
            }
        }
    }

    function resetColor() {
        for (var i=0; i < dataModel.count; i++) {
            dataModel.get(i).itemColor = defaultColor;
        }
    }

    function initialization() {
        dataModel.clear();
        dataModel.append(quantity);
    }
    Component.onCompleted: initialization();
}


