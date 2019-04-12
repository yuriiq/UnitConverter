/*
  Файл с набором функций для конвертации единиц измерения.
  Содержит массив данных и функции для конвертации.
*/

// Доступные префиксы и их коэффициенты
var prefixes = new Array;
prefixes["Кило"] = 1000;
prefixes["Гекто"] = 100;
prefixes["Дека"] = 10;
prefixes["-"] = 1;
prefixes["Деци"] = 0.1;
prefixes["Санти"] = 0.01;
prefixes["Мили"] = 0.001;

// Доступные величины и единицы измерения
var units = new Array;
units["Температура"] = ["Кельвин", "Градус Цельсия", "Градус Фаренгейта"];
units["Масса"] = ["Грамм", "Фунт", "Американская тонна"];
units["Объём"] = ["Литр", "Английский галлон", "Нефтяной баррель", "Кубический метр"];

// Функции конвертации из заданной единицы измерения в базовую
var convertFromFuncs = new Array;
convertFromFuncs["Грамм"]              = function(a, k) { return a * k; };
convertFromFuncs["Фунт"]               = function(a, k) { return a * k * 453.59237; };
convertFromFuncs["Американская тонна"] = function(a, k) { return a * k * 907184.74; };

convertFromFuncs["Кельвин"]           = function(a, k) { return a * k; };
convertFromFuncs["Градус Цельсия"]    = function(a, k) { return a * k + 273.15; };
convertFromFuncs["Градус Фаренгейта"] = function(a, k) { return (a * k - 32) * 5 / 9 + 273.15; };

convertFromFuncs["Литр"]              = function(a, k) { return a * k; };
convertFromFuncs["Английский галлон"] = function(a, k) { return a * k * 4.5461; };
convertFromFuncs["Нефтяной баррель"]  = function(a, k) { return a * k * 158.987; };
convertFromFuncs["Кубический метр"]   = function(a, k) { return a * k * 1000; };

// Функции конвертации из базовой единицы измерения в заданную
var convertToFuncs = new Array;
convertToFuncs["Грамм"]              = function(a, k) { return a / k; };
convertToFuncs["Фунт"]               = function(a, k) { return a / k / 453.59237; };
convertToFuncs["Американская тонна"] = function(a, k) { return a / k / 907184.74; };

convertToFuncs["Кельвин"]            = function(a, k) { return a / k; };
convertToFuncs["Градус Цельсия"]     = function(a, k) { return (a - 273.15)/k; };
convertToFuncs["Градус Фаренгейта"]  = function(a, k) { return ((a - 273.15) * 9 / 5 + 32) / k; };

convertToFuncs["Литр"]               = function(a, k) { return a / k; };
convertToFuncs["Английский галлон"]  = function(a, k) { return a / k / 4.5461; };
convertToFuncs["Нефтяной баррель"]   = function(a, k) { return a / k / 158.987; };
convertToFuncs["Кубический метр"]    = function(a, k) { return a / k / 1000; };

function getPrefix(unit) {
    //TODO: возвращать разные наборы префиксов в зависимости от единицы измерения
    return Object.keys(prefixes);
}

function getUnit(quantity) {
    return units[quantity];
}

function defColor () {
    return "pink";
}

function getQuantity() {
    return [ {"name":"Температура", "itemColor" : defColor ()},
             {"name":"Масса",       "itemColor" : defColor ()},
             {"name":"Объём",       "itemColor" : defColor ()}];
}

function getPrefixK(prefix, unit) {
    // Для некоторых единиц объёма префик необходимо возводить в третью степень
    if (unit === "Кубический метр") {
        var res = prefixes[prefix];
        return res * res * res;
    }
    else
        return prefixes[prefix];
}

function convert (inPrefix, inUnit, outPrefix, outUnit, value) {
    var v = convertFromFuncs[inUnit](value, getPrefixK(inPrefix, inUnit));
    v = convertToFuncs[outUnit](v, getPrefixK(outPrefix, outUnit));
    return v;
}
