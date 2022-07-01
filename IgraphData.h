#ifndef IGRAPHDATA_H
#define IGRAPHDATA_H

#include <QAbstractSeries>
#include <QtCharts>
#include <QFileInfo>


class IGraphData
{
public:
    int seriesCount = 10;
    //virtual QAbstractSeries* GetSeries(QAbstractSeries*) = 0;
    virtual QMap<QString, float> GetRowData() = 0;
};

#endif // IGRAPHDATA_H
