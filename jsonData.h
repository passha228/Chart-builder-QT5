#ifndef JSONDATA_H
#define JSONDATA_H

#include "printer.h"
#include "QJsonDocument"

// класс, который хранит сырые данные, собираемые из JSON
class JsonData: public GraphData
{
public:
    // конструктор принимает информацию о файле из которого будет происходить сбор
    JsonData(QFileInfo);
    // геттер на data
    QMap<QString, float> GetRowData() override {return data;}
};

#endif // JSONDATA_H
