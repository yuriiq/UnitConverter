#ifndef UNITSELECTWIDGET_H
#define UNITSELECTWIDGET_H

#include "common.h"
#include <QWidget>
#include <QMultiHash>

namespace Ui {
class UnitSelectWidget;
}

/// Виджет для выбора текущей единицы измерения и префикса к ней
class UnitSelectWidget : public QWidget
{
    Q_OBJECT

public:
    explicit UnitSelectWidget(QWidget *parent = 0);
    ~UnitSelectWidget();
    void init(const UnitSelectData & data);
    QString currentUnitName() const; ///< Текущая единица измерения
    QString currentPrefix() const; ///< Текущий префикс
signals:
    void unitChanged(); ///< Испускается когда пользхователь меняет текущий префикс или единицу измерения
private slots:
    void onCurrentUnitChanged(const QString & unitName); ///< Заполняет префиксы для текущей единицы измерения

private:
    Ui::UnitSelectWidget *ui;
    UnitSelectData data; ///< Набор доступных единиц измерения и префиксов
};

#endif // UNITSELECTWIDGET_H
