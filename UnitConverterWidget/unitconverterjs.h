#ifndef UNITCONVERTERJS_H
#define UNITCONVERTERJS_H
#include "unitconverterbase.h"
#include <QHash>

/// Пример реализации конвертёра на основе функций JavaScript
class UnitConverterJS : public UnitConverterBase
{
public:
    typedef QPair<QString, QString> ScriptData; ///< Пара скриптов для конвертации: из текущей единицы в базовую - из базовой в текущую
    typedef QHash<QString, ScriptData> ConvertData; ///< Данные для работы с конкретной единицей измерения
    typedef QHash<QString, double> PrefixData; ///< Информация о префиксах: единица измерения - коэффициент

    UnitConverterJS(const ConvertData & d, const PrefixData & p, int pres = 6);
    ~UnitConverterJS();
    virtual QString convert(const QString & fromUnit, const QString & fromPrefix,
                            const QString & toUnit,   const QString & toPrefix,
                            const QString & value) const override;

private:
    ConvertData data;
    PrefixData prefixes;
    int precision = 6;
};

#endif // UNITCONVERTERJS_H
