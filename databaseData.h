#ifndef DATABASEDATA_H
#define DATABASEDATA_H

#include "IgraphData.h"
#include <memory>

#include <QAbstractSeries>
#include <QtCharts>

#include <QtSql>
#include <QMap>

class DatabaseData : public IGraphData
{
private:
    QMap<QString, float> data;
public:
    DatabaseData(QFileInfo);
    QMap<QString, float> GetRowData() override {return data;}
    //QAbstractSeries* GetSeries(QAbstractSeries*) override;
};

#endif // DATABASEDATA_H
