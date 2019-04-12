#ifndef UNITCONVERTERCONFIGURATORSIMPLE_H
#define UNITCONVERTERCONFIGURATORSIMPLE_H
#include "unitconverterconfigurator.h"
#include <QHash>

/// Пример реализации простого настройщика
/// В данном примере все параметры заданы в коде без возможности изменения
/// Но при необходимости такие данные могут быть загружены из внешних источников (xml, json, http...)
class UnitConverterConfiguratorSimple : public UnitConverterConfiguratorBase
{
    typedef QHash <QString, UnitSelectData > UnitData;
    UnitData unitData;
    QHash <QString, UnitConverterBase *> unitConverters;
public:
    UnitConverterConfiguratorSimple();
    virtual ~UnitConverterConfiguratorSimple();
    virtual QStringList baseQuantities() const override;
    virtual UnitSelectData units(const QString & quantityName) const override;
    virtual UnitConverterBase * converter(const QString & quantityName) const override;
};

#endif // UNITCONVERTERCONFIGURATORSIMPLE_H
