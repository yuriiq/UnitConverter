#ifndef INPUTFORM_H
#define INPUTFORM_H

#include "common.h"
#include <QWidget>

namespace Ui {
class InputForm;
}

/// Форм для выбора исходной единицы измерения и ввода значения
class InputForm : public QWidget
{
    Q_OBJECT

public:
    explicit InputForm(QWidget *parent = 0);
    ~InputForm();
    void init(const UnitSelectData & data); ///< Функция инициализации, принимает набор доступных единиц измерения и префиксы к ним
    QString currentUnitName() const; ///< Текущая единица измерения
    QString currentPrefix() const; ///< Текущий префикс
    QString currentValue() const; ///< Текущее значение

signals:
    void dataChanged(); ///< Сигнал испускается при смене единицы измерения, префикса или введённого значения

private:
    Ui::InputForm *ui;
};

#endif // INPUTFORM_H
