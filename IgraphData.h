#ifndef IGRAPHDATA_H
#define IGRAPHDATA_H

#include <QAbstractSeries>
#include <QtCharts>
#include <QFileInfo>


// базовый класс для данных
//
class IGraphData
{
public:
    // ифнормация о кол-ве данных которые надо собрать (по-моему не используется)
    int seriesCount = 10;
    // геттер на получение данных
    virtual QMap<QString, float> GetRowData() = 0;
};

#endif // IGRAPHDATA_H
