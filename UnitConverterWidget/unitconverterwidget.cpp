#include "unitconverterwidget.h"
#include "ui_unitconverterwidget.h"
#include "unitconverterconfigurator.h"
#include "unitconverterpage.h"

UnitConverterWidget::UnitConverterWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UnitConverterWidget)
{
    ui->setupUi(this);
}

void UnitConverterWidget::init(const UnitConverterConfiguratorBase & conf)
{
    // Перед добавлением новых табов, необходимо удалить все старые.
    removeTabs();
    QStringList baseQ = conf.baseQuantities();
    foreach (const QString & quantity, baseQ)
    {
        UnitConverterPage * p = new UnitConverterPage(this);
        p->setObjectName(quantity); // UnitConverterPage определяет физическую величину через свой objectName
        p->init(conf);
        ui->tabWidget->addTab(p, quantity);
    }
}

void UnitConverterWidget::removeTabs()
{
    QWidget * w = ui->tabWidget->widget(0);
    while (w)
    {
        ui->tabWidget->removeTab(0);
        w->deleteLater();
        w = ui->tabWidget->widget(0);
    }
}
UnitConverterWidget::~UnitConverterWidget()
{
    delete ui;
}
