/*
  Основной элемент конвертёра.
  Позволяет конвертировать различные единицы измерения в рамках одной физической величины
  Набор доступных элементов задан в файле funcs.js
  */

import QtQuick 2.0
import QtQuick.Controls 2.2

Item {
    property alias header : headerLabel.text // Текст в заголовке до выбора физической величины
    property alias buttonHeight: selectPage.buttonHeight // Высота кнопок выбора физических величин
    property alias selectColor : selectPage.selectColor // Цвет выбранной физической величины
    property alias quantity: selectPage.quantity // Доступные физические величины и их цвета по умолчанию
    property alias convertFunc : inputPage.convertFunc // Функция конвертации физических величин
    property alias outputBorderColor: inputPage.outputBorderColor // Цвет рамки с результатом
    property alias outputBackgroundColor: inputPage.outputBackgroundColor // Цвет фона с результатом
    property alias precision : inputPage.precision // Точность вывода результата

    Label { // Заголовок с наименованием текущей физической величины
            //TODO: добавить возможность менять высоту и размер шрифта
        horizontalAlignment: Text.AlignHCenter
        id: headerLabel
        anchors.top: parent.top
        anchors.left: parent.left
        anchors.right: parent.right
    }

    SwipeView {
        id: view
        currentIndex: 0
        anchors.top: headerLabel.bottom
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.bottom: parent.bottom

        Item { // Страница с выбором физической величины
            QuantitySelectPage {
                id: selectPage
                anchors.fill: parent
                onClicked: function(a) {
                    view.currentIndex = 1;
                    headerLabel.text = a;
                }
            }
        }
        Item { // Страница с вводом и выводом данных
            UnitConvertPage {
                id: inputPage
                anchors.fill: parent
                quantityName : headerLabel.text
            }
        }
    }
    Keys.onBackPressed: view.currentIndex = 0;
}
