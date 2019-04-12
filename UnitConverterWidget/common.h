#ifndef COMMON_H
#define COMMON_H

/// Файл для общих параметров и структур
///
#include <QString>
#include <QMultiHash>

/// UnitSelectData - структура для хранения данных вида: единица измерения - префикс
/// Пример: метр - кило, метр - мили
typedef QMultiHash<QString, QString> UnitSelectData;

#endif // COMMON_H
