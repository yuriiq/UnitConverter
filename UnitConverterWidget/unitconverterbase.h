#ifndef UNITCONVERTERBASE_H
#define UNITCONVERTERBASE_H
#include <QString>

/// Базовый класс для конвертёров физических величин.
class UnitConverterBase
{
public:
    virtual ~UnitConverterBase() {}

    /// Интерфейс функции для конвертирования физической величины.
    /// Принимает: наименования физических величин и префиксов
    /// Возвращает: результат конвертации (значение или сообщение об ошибке)
    virtual QString convert(const QString & fromUnit, const QString & fromPrefix,
                            const QString & toUnit,   const QString & toPrefix,
                            const QString & value) const = 0;
};

#endif // UNITCONVERTERBASE_H
