#include "inputform.h"
#include "ui_inputform.h"

InputForm::InputForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::InputForm)
{
    ui->setupUi(this);
    connect(ui->doubleSpinBox, SIGNAL(valueChanged(double)), this, SIGNAL(dataChanged()));
    connect(ui->selectWidget, SIGNAL(unitChanged()), this, SIGNAL(dataChanged()));
}

InputForm::~InputForm()
{
    delete ui;
}

void InputForm::init(const UnitSelectData &data)
{
    ui->selectWidget->init(data);
}

QString InputForm::currentUnitName() const
{
    return ui->selectWidget->currentUnitName();
}

QString InputForm::currentPrefix() const
{
    return ui->selectWidget->currentPrefix();
}

QString InputForm::currentValue() const
{
    return QString::number(ui->doubleSpinBox->value());
}
