#ifndef GRAPHGENERATOR_H
#define GRAPHGENERATOR_H

#include <QtCharts>
#include <QChartView>
#include <QBarSet>
#include <QBarSeries>
#include <QPieSeries>


#include <QPainter>
#include <QPdfWriter>
#include <QtPrintSupport/QPrintDialog>
#include <QtPrintSupport/QPrinter>

class GraphGenerator
{
public:
    GraphGenerator();
    QChartView* GeneratePie(QPieSeries*, bool);
    QChartView* GenerateBar(QBarSeries*, bool);

    void CreatePdf(QChartView* chartView);
};

#endif // GRAPHGENERATOR_H
