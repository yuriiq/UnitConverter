#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "unitconverterconfiguratorsimple.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    UnitConverterConfiguratorSimple simple; ///< Основной объект, который хранит все параметры и функции для конвертёра
    /// Поскольку конфигуратор управляет временем жизни UnitConverter, необходимо, чтобы он существовал пока существует convertWidget
};

#endif // MAINWINDOW_H
