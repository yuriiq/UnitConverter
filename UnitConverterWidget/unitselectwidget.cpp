#include "unitselectwidget.h"
#include "ui_unitselectwidget.h"

UnitSelectWidget::UnitSelectWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UnitSelectWidget)
{
    ui->setupUi(this);
    connect(ui->unitComboBox, SIGNAL(currentTextChanged(QString)), this, SLOT(onCurrentUnitChanged(QString)));
    connect(ui->prefixComboBox, SIGNAL(currentIndexChanged(int)),  this, SIGNAL(unitChanged()));
    // Испускать сигнал при изменении текущей единицы измерения нет необходимости, поскольку в этом случае обновляются префиксы
}

UnitSelectWidget::~UnitSelectWidget()
{
    delete ui;
}

void UnitSelectWidget::init(const UnitSelectData & data_)
{
    data = data_;
    QStringList units = data.keys();
    units.removeDuplicates();
    ui->unitComboBox->clear();
    ui->unitComboBox->addItems(units);
    ui->unitComboBox->setCurrentIndex(0);
}

void UnitSelectWidget::onCurrentUnitChanged(const QString &unitName)
{ // Изменилась текущая единица измерения. Необходимо обновить префиксы
    QString currentPrefix = ui->prefixComboBox->currentText();
    QStringList prefixes = data.values(unitName);
    ui->prefixComboBox->clear();
    ui->prefixComboBox->addItems(prefixes);
    if (prefixes.contains(currentPrefix))
        ui->prefixComboBox->setCurrentText(currentPrefix);
}

QString UnitSelectWidget::currentUnitName() const
{
    return ui->unitComboBox->currentText();
}

QString UnitSelectWidget::currentPrefix() const
{
    return ui->prefixComboBox->currentText();
}
