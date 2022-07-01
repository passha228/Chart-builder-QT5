#ifndef IGRAPHGENERATOR_H
#define IGRAPHGENERATOR_H

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
    static void CreatePdf(QChartView* chartView);
};

#endif // IGRAPHGENERATOR_H
