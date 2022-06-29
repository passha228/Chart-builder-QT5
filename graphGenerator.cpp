#include "graphGenerator.h"

GraphGenerator::GraphGenerator()
{

}


QChartView* GraphGenerator::GeneratePie(QPieSeries* series, bool colorState)
{
    QChart* chart = new QChart();
    //QBarSeries * series = dataList[row]->Series();

    //смена цвета
    // чб
    if (colorState)
    {
        int i = 0;
        for(auto set : series->slices())
        {
            set->setColor(QColor(i, i, i));
                i+=25;
        }
    }
    // цветной
    else
    {
        for(auto set : series->slices())
        {
            set->setColor(QColor(qrand()%256, qrand()%256, qrand()%256));
        }
    }

    chart->addSeries(series);
    chart->setTitle("Some title");
    chart->setAnimationOptions(QChart::SeriesAnimations);
    QChartView *view = new QChartView(chart);
    return view;
}

QChartView* GraphGenerator::GenerateBar(QBarSeries* series, bool colorState)
{
    QChart* chart = new QChart();
    //QBarSeries * series = dataList[row]->Series();

    //смена цвета
    // чб
    if (colorState)
    {
        int i = 0;
        for(auto set : series->barSets())
        {
            set->setColor(QColor(i, i, i));
                i+=25;
        }
    }
    // цветной
    else
    {
        for(auto set : series->barSets())
        {
            set->setColor(QColor(qrand()%256, qrand()%256, qrand()%256));
        }
    }

    chart->addSeries(series);
    chart->setTitle("Some title");
    chart->setAnimationOptions(QChart::SeriesAnimations);
    QChartView *view = new QChartView(chart);
    return view;
}

void GraphGenerator::CreatePdf(QChartView* chartView)
{
    QPrinter printerGrayColor;
    printerGrayColor.setColorMode(QPrinter::GrayScale);// установка ч/б цвета
    //Определение параметров необходимых принтеру.
    //С помощью QPainter выделение области для формирования pdf
    printerGrayColor.setOutputFormat(QPrinter::PdfFormat);
    printerGrayColor.setOutputFileName("D:/PDFresult.pdf");

    QPainter painterG(&printerGrayColor);
    chartView->render(&painterG);

    painterG.end();
}
