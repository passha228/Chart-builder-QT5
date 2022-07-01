#ifndef PIEGENERATOR_H
#define PIEGENERATOR_H

#include <IgraphGenerator.h>

#include <QtCharts>
#include <QChartView>
#include <QPieSeries>

class PieGenerator : public GraphGenerator
{
public:
    static QChartView* GetGraph(QMap<QString, float> map, bool colorState);
    //void CreatePdf(QChartView* chartView) override;
};

#endif // PIEGENERATOR_H
