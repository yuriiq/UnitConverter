#ifndef OUTPUTFORM_H
#define OUTPUTFORM_H
#include "common.h"
#include <QWidget>

/// Форма для выбора результирующей единицы измерения и вывода конечного значения
namespace Ui {
class OutputForm;
}

class OutputForm : public QWidget
{
    Q_OBJECT

public:
    explicit OutputForm(QWidget *parent = 0);
    ~OutputForm();
    void init(const UnitSelectData & data); ///< Функция инициализации, принимает набор доступных единиц измерения и префиксы к ним
    void setValue(const QString & value); ///< Функция устанавливает результирующее значения

    QString currentUnitName() const; ///< Текущая единица измерения
    QString currentPrefix() const; ///< Текущий префикс

signals:
    void dataChanged(); ///< Сигнал испускается при смене единицы измерения или префикса
private:
    Ui::OutputForm *ui;
};

#endif // OUTPUTFORM_H
