#ifndef GRAPHGENERATOR_H
#define GRAPHGENERATOR_H

#include <QtCharts>
#include <QChartView>
#include <QBarSet>
#include <QBarSeries>
#include <QPieSeries>

#include <QFileDialog>


#include <QPainter>
#include <QPdfWriter>
#include <QtPrintSupport/QPrintDialog>
#include <QtPrintSupport/QPrinter>

// класс для создания пдф файлов с графиками
class GraphGenerator
{
public:
    /*
     принимает готовый график, ничего не возвращает
     только отрисовывает готовый график
     если возникли исключительыне ситуации, то открывает диалоговое окно, которое сообщает об ошибке
    */
    static void CreatePdf(QChartView* chartView);
};

#endif // GRAPHGENERATOR_H
