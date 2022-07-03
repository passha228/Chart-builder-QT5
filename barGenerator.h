#ifndef BARGENERATOR_H
#define BARGENERATOR_H

#include <graphGenerator.h>

#include <QtCharts>
#include <QChartView>
#include <QBarSet>
#include <QBarSeries>


// класс для обычных диаграмм
class BarGenerator : public GraphGenerator
{
public:    
    /*
      метод создает диаграмму и возвращает ее НО НЕ ВЫВОДИТ ЕЕ НА ЭКРАН
      принимает на вход сырые данные в словаре и флаг на цвет
      можно вызывать без экземпляра класса
     */
    static QChartView* GetGraph(QMap<QString, float>, bool);
};

#endif // BARGENERATOR_H
