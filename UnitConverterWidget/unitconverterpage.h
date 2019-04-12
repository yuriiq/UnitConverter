#ifndef UNITCONVERTERPAGE_H
#define UNITCONVERTERPAGE_H

#include <QWidget>

namespace Ui {
class UnitConverterPage;
}

class UnitConverterBase;
class UnitConverterConfiguratorBase;

/// Страница для ввода и вывода информации по одной физической величине
/// Состоит из InputForm и OutputForm
class UnitConverterPage : public QWidget
{
    Q_OBJECT

public:
    explicit UnitConverterPage(QWidget *parent = 0);
    ~UnitConverterPage();
    void init(const UnitConverterConfiguratorBase & conf);

private slots:
    void onDataChanged(); /// Обработчик изменений на InputForm и OutputForm.

private:
    Ui::UnitConverterPage *ui;
    UnitConverterBase * converter;
};

#endif // UNITCONVERTERPAGE_H
