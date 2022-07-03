#ifndef PIEGENERATOR_H
#define PIEGENERATOR_H

#include <IgraphGenerator.h>

#include <QtCharts>
#include <QChartView>
#include <QPieSeries>


// класс для создания круговых диаграмм
class PieGenerator : public GraphGenerator
{
public:
    /*
      метод создает диаграмму и возвращает ее НО НЕ ВЫВОДИТ ЕЕ НА ЭКРАН
      принимает на вход сырые данные в словаре и флаг на цвет
      можно вызывать без экземпляра класса
     */
    static QChartView* GetGraph(QMap<QString, float> map, bool colorState);
};

#endif // PIEGENERATOR_H
