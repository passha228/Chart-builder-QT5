#ifndef PRINTER_H
#define PRINTER_H

#include "graphData.h"

#include <memory>


#include <QtCharts>
#include <QChartView>
#include <QBarSet>
#include <QBarSeries>
#include <QPieSeries>

#include <QMap>
#include <QString>


class Printer
{
public:
    GraphData* data;
    QBarSeries* barSeries;
    QPieSeries* pieSeries;
public:
    Printer();

    // пока нз как сделать возврат любого Series,
    //template<typename T>
    //std::shared_ptr<T*> GetData(QMap<QString, int>);

    virtual void GetData (QMap<QString, int>) = 0;
    QBarSeries* BarSeries() const{return barSeries;}
    QPieSeries* PieSeries() const{return pieSeries;}
    //virtual void PrintGraph();
};

#endif // PRINTER_H
