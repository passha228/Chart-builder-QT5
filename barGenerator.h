#ifndef BARGENERATOR_H
#define BARGENERATOR_H

#include <IgraphGenerator.h>

#include <QtCharts>
#include <QChartView>
#include <QBarSet>
#include <QBarSeries>


#include <QPainter>
#include <QPdfWriter>
#include <QtPrintSupport/QPrintDialog>
#include <QtPrintSupport/QPrinter>

class BarGenerator : public GraphGenerator
{
public:    
    static QChartView* GetGraph(QMap<QString, float>, bool);
    //void CreatePdf(QChartView* chartView) override;
};

#endif // BARGENERATOR_H
