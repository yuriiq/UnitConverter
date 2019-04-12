#include "unitconverterconfiguratorsimple.h"
#include "unitconverterjs.h"

UnitConverterConfiguratorSimple::UnitConverterConfiguratorSimple()
{
    UnitConverterJS::PrefixData prefixes;
    prefixes.insert("Кило", 1000);
    prefixes.insert("-", 1); // Единичный префикс (без префикса)
    prefixes.insert("Мили", 0.001);

    // Примеры функций для перевода величин: a - значение, k - коэффициент префикса
    UnitConverterJS::ConvertData datas;
    datas.insert("Грамм", UnitConverterJS::ScriptData("(function(a, k) { return a * k; })",
                                                      "(function(a, k) { return a / k; })"));
    datas.insert("Фунт", UnitConverterJS::ScriptData("(function(a, k) { return a * k * 453.59237; })",
                                                     "(function(a, k) { return a / k / 453.59237; })"));
    datas.insert("Американская тонна", UnitConverterJS::ScriptData("(function(a, k) { return a * k * 907184.74; })",
                                                     "(function(a, k) { return a / k / 907184.74; })"));
    unitConverters.insert("Масса", new UnitConverterJS(datas, prefixes));

    datas.clear();
    datas.insert("Кельвин", UnitConverterJS::ScriptData
                 ("(function(a, k) { return a * k; })",
                  "(function(a, k) { return a / k; })"));
    datas.insert("Градус Цельсия", UnitConverterJS::ScriptData
                 ("(function(a, k) { return a * k + 273.15; })",
                  "(function(a, k) { return (a - 273.15)/k; })"));
    datas.insert("Градус Фаренгейта", UnitConverterJS::ScriptData
                 ("(function(a, k) { return (a * k - 32) * 5 / 9 + 273.15; })",
                  "(function(a, k) { return ((a - 273.15) * 9 / 5 + 32) / k; })"));
    unitConverters.insert("Температура", new UnitConverterJS(datas, prefixes));

    datas.clear();
    datas.insert("Литр", UnitConverterJS::ScriptData
                 ("(function(a, k) { return a * k; })",
                  "(function(a, k) { return a / k; })"));
    datas.insert("Английский галлон", UnitConverterJS::ScriptData
                 ("(function(a, k) { return a * k * 4.5461; })",
                  "(function(a, k) { return a / k / 4.5461; })"));
    datas.insert("Нефтяной баррель", UnitConverterJS::ScriptData
                 ("(function(a, k) { return a * k * 158.987; })",
                  "(function(a, k) { return a / k / 158.987; })"));
    datas.insert("Кубический метр", UnitConverterJS::ScriptData
                 ("(function(a, k) { return a * k * 1000; })",
                  "(function(a, k) { return a / k / 1000; })"));
    unitConverters.insert("Объём", new UnitConverterJS(datas, prefixes));

    UnitSelectData unitList;
    unitList.insertMulti("Грамм", "Кило");
    unitList.insertMulti("Грамм", "Мили");
    unitList.insertMulti("Грамм", "-");
    unitList.insertMulti("Фунт", "Кило");
    unitList.insertMulti("Фунт", "-");
    unitList.insertMulti("Американская тонна", "-");
    unitData.insert("Масса", unitList);

    unitList.clear();
    unitList.insertMulti("Кельвин", "Кило");
    unitList.insertMulti("Кельвин", "-");
    unitList.insertMulti("Градус Цельсия", "Кило");
    unitList.insertMulti("Градус Цельсия", "-");
    unitList.insertMulti("Градус Фаренгейта", "Кило");
    unitList.insertMulti("Градус Фаренгейта", "-");
    unitData.insert("Температура", unitList);

    unitList.clear();
    unitList.insertMulti("Литр", "Кило");
    unitList.insertMulti("Литр", "-");
    unitList.insertMulti("Английский галлон", "Кило");
    unitList.insertMulti("Английский галлон", "-");
    unitList.insertMulti("Нефтяной баррель", "Кило");
    unitList.insertMulti("Нефтяной баррель", "-");
    unitList.insertMulti("Кубический метр", "-");
    unitData.insert("Объём", unitList);

}

UnitConverterConfiguratorSimple::~UnitConverterConfiguratorSimple()
{
    foreach (UnitConverterBase * converter, unitConverters)
    {
        delete converter;
    }
}

QStringList UnitConverterConfiguratorSimple::baseQuantities() const
{
    QStringList res = unitData.keys();
    std::sort(res.begin(), res.end()); // Порядок отображения табов зависит от порядка в этом списке.
    return res;
}

UnitSelectData UnitConverterConfiguratorSimple::units(const QString &quantityName) const
{
    return unitData.value(quantityName);
}

UnitConverterBase *UnitConverterConfiguratorSimple::converter(const QString &quantityName) const
{
    return unitConverters.value(quantityName, Q_NULLPTR);
}

