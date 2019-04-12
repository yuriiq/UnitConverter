#include "unitconverterjs.h"
#include <QJSEngine>

UnitConverterJS::UnitConverterJS(const UnitConverterJS::ConvertData &d, const PrefixData &p, int prec)
{
    data = d;
    prefixes = p;
    precision = prec;
}

UnitConverterJS::~UnitConverterJS()
{

}

QString UnitConverterJS::convert(const QString &fromUnit, const QString &fromPrefix,
                                 const QString &toUnit,   const QString &toPrefix,
                                 const QString &value) const
{
    const QString & fs = data[fromUnit].first; // Текущая единица измерения, откуда переводим
    double fp = prefixes[fromPrefix]; // Коэффициент префикса к ней

    const QString & ts = data[toUnit].second; // Текущая единица измерения, куда переводим
    double tp = prefixes[toPrefix]; // Коэффициент префикса к ней

    QJSEngine jsEngine;
    // Построение JS-объектов на основе строк
    QJSValue from = jsEngine.evaluate(fs);
    QJSValue to = jsEngine.evaluate(ts);

    // Добавление набора аргументов и вычисление значения физической величины
    QJSValueList args;
    args << value << fp;
    QJSValue fromResult = from.call(args);
    args.clear();
    args << fromResult << tp;
    QJSValue jsResult = to.call(args);
    return QString::number(jsResult.toNumber(), 'g', precision);
}
