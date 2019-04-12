#include "unitconverterpage.h"
#include "ui_unitconverterpage.h"
#include "unitconverterconfigurator.h"
#include "unitconverterbase.h"

UnitConverterPage::UnitConverterPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UnitConverterPage)
{
    ui->setupUi(this);
    connect(ui->inputWidget, SIGNAL(dataChanged()), this, SLOT(onDataChanged()));
    connect(ui->outputWidget, SIGNAL(dataChanged()), this, SLOT(onDataChanged()));
}

UnitConverterPage::~UnitConverterPage()
{
    delete ui;
}

void UnitConverterPage::init(const UnitConverterConfiguratorBase &configurator)
{
    // Объектом, на который указывает converter, владеет configurator, поэтому нет необходимости в дополнительных действиях
    converter = configurator.converter(this->objectName());
    UnitSelectData data = configurator.units(this->objectName());
    ui->inputWidget->init(data);
    ui->outputWidget->init(data);
}

void UnitConverterPage::onDataChanged()
{
    if(converter) {
        QString toUnit = ui->outputWidget->currentUnitName();
        QString toPrefix = ui->outputWidget->currentPrefix();
        QString fromUnit = ui->inputWidget->currentUnitName();
        QString fromPrefix = ui->inputWidget->currentPrefix();
        QString value = ui->inputWidget->currentValue();
        QString result = converter->convert(fromUnit, fromPrefix, toUnit, toPrefix, value);
        ui->outputWidget->setValue(result);
    } else {
        ui->outputWidget->setValue("No Converter!");
    }
}

