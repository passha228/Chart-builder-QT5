#ifndef PRINTER_H
#define PRINTER_H

#include "IgraphData.h"
#include "IgraphGenerator.h"


#include "databaseData.h"
#include "jsonData.h"

#include "barGenerator.h"
#include "pieGenerator.h"

#include <memory>


#include <QtCharts>
#include <QChartView>
#include <QBarSet>
#include <QBarSeries>
#include <QPieSeries>

#include <QFileDialog>



class Printer
{
private:
    QList<IGraphData*> data;
    //GraphGenerator* view = nullptr;
    QAbstractSeries* currentSeries = nullptr;
public:
    QChartView* CreateGraph (int i, bool, QString);
    void CreatePdf(QChartView*);
    void ParseData (QFileInfo fileInfo);
};

#endif // PRINTER_H
