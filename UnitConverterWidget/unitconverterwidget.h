#ifndef UNITCONVERTERWIDGET_H
#define UNITCONVERTERWIDGET_H

#include <QWidget>

namespace Ui {
class UnitConverterWidget;
}

class UnitConverterConfiguratorBase;

/// Основной виджет конвертёра. Содержит несколько UnitConverterPage, по одной на каждую физичекую величину.
class UnitConverterWidget : public QWidget
{
    Q_OBJECT

public:
    explicit UnitConverterWidget(QWidget *parent = 0);
    void init(const UnitConverterConfiguratorBase &conf);
    ~UnitConverterWidget();

private:
    Ui::UnitConverterWidget *ui;
    void removeTabs(); /// Удаляет все UnitConverterPage перед добавлением новых
};

#endif // UNITCONVERTERWIDGET_H
