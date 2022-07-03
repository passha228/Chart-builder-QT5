#ifndef PRINTER_H
#define PRINTER_H

#include "graphData.h"
#include "graphGenerator.h"


#include "databaseData.h"
#include "jsonData.h"

#include "barGenerator.h"
#include "pieGenerator.h"

#include <memory>


#include <QtCharts>
#include <QChartView>
#include <QBarSet>
#include <QBarSeries>
#include <QPieSeries>

#include <QFileDialog>


// отвечает за логику передачи данных для отображения
// также хранит текущую диаграмму
class Printer
{
private:
    // наши данные
    QList<GraphData*> data;
    // текущая диаграмма
    QChartView* view = nullptr;

public:
    /*
     создает диаграмму по входных параметрам
     принимает на вход номер строки в таблице, флаг на цвет и строку с типом графика
     возвращает готовую диаграмму или нулевой указатель(если не удалось построить диаграмму)
    */
    QChartView* CreateGraph (int i, bool, QString);

    // создает файл пдф по текущей диаграмме
    void CreatePdf(QChartView*);
    /*
     заполнение данных
     принимает на вход инфу о файле
     ничего не возвращает
    */
    void ParseData (QFileInfo fileInfo);
};

#endif // PRINTER_H
