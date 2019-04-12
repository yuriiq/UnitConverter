#ifndef UNITCONVERTERCONFIGURATOR_H
#define UNITCONVERTERCONFIGURATOR_H

#include <QStringList>
#include "common.h"

class UnitConverterBase;
/// Базовый класс для настройщика конвертёра.
class UnitConverterConfiguratorBase
{
public:
    virtual ~UnitConverterConfiguratorBase() {}
    virtual QStringList baseQuantities() const = 0; ///< Список базовых физических величин (масса, объём и т.п.)
    virtual UnitSelectData units(const QString & quantityName) const = 0; ///< Набор единиц измерения и префиксов для заданной физической величины
    virtual UnitConverterBase * converter(const QString & quantityName) const = 0; ///< Указатель на конвертёр для заданной физической величины
};

#endif // UNITCONVERTERCONFIGURATOR_H
