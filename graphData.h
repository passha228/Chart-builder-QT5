#ifndef GRAPHDATA_H
#define GRAPHDATA_H

#include <QAbstractSeries>
#include <QtCharts>
#include <QFileInfo>


// базовый класс для данных
//
class GraphData
{
protected:
    QMap<QString, float> data;
public:
    // ифнормация о кол-ве данных которые надо собрать (по-моему не используется)
    int seriesCount = 10;
    // геттер на получение данных
    virtual QMap<QString, float> GetRowData() = 0;
    // функция для показа ошибки
    // принмает сообщение с ошибкой
    void except(QString str);
};

#endif // GRAPHDATA_H
