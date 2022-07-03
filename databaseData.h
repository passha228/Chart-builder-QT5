#ifndef DATABASEDATA_H
#define DATABASEDATA_H

#include "IgraphData.h"
#include <memory>

#include <QAbstractSeries>
#include <QtCharts>

#include <QtSql>
#include <QMap>

// класс, который хранит сырые данные, собираемые из БД SQLITE
class DatabaseData : public IGraphData
{
private:
    // словарь со всеми данными
    QMap<QString, float> data;
public:
    // конструктор принимает информацию о файле из которого будет происходить сбор
    DatabaseData(QFileInfo); // для БД
    // геттер на data
    QMap<QString, float> GetRowData() override {return data;}
};

#endif // DATABASEDATA_H
