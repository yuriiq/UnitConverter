#include "outputform.h"
#include "ui_outputform.h"

OutputForm::OutputForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::OutputForm)
{
    ui->setupUi(this);
    connect(ui->selectWidget, SIGNAL(unitChanged()), this, SIGNAL(dataChanged()));
}

OutputForm::~OutputForm()
{
    delete ui;
}

void OutputForm::init(const UnitSelectData &data)
{
    ui->selectWidget->init(data);
}

void OutputForm::setValue(const QString &value)
{
    ui->label->setText(value);
}

QString OutputForm::currentUnitName() const
{
    return ui->selectWidget->currentUnitName();
}

QString OutputForm::currentPrefix() const
{
    return ui->selectWidget->currentPrefix();
}
