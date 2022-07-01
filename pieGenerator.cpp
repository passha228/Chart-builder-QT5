#include "pieGenerator.h"

QChartView* PieGenerator::GetGraph(QMap<QString, float> map, bool colorState)
{
    QChart* chart = new QChart();
    QPieSeries* pieSeries = new QPieSeries();
    QStringList categories;

    int count = 0;
    for(auto elem = map.begin(); elem != map.end(); elem++)
    {
        count++;
        if (count > 10)
            break;
        categories.append(elem.key());
        pieSeries->append(elem.key(), elem.value());
    }

    qDebug() << "Серия баров создана";

    //смена цвета
    // чб
    if (colorState)
    {
        int i = 0;
        for(auto set : pieSeries->slices())
        {
            set->setColor(QColor(i, i, i));
                i+=25;
        }
    }
    // цветной
    else
    {
        for(auto set : pieSeries->slices())
        {
            set->setColor(QColor(qrand()%256, qrand()%256, qrand()%256));
        }
    }

    chart->addSeries(pieSeries);
    chart->setTitle("Some title");
    chart->setAnimationOptions(QChart::SeriesAnimations);
    QChartView *view = new QChartView(chart);
    return view;
}

//void PieGenerator::CreatePdf(QChartView* chartView)
//{
//    QPrinter printer;
//    qDebug() << "CreatePDF";
//    printer.setOutputFormat(QPrinter::PdfFormat);
//    printer.setOutputFileName("D:/TSU/PDFresult.pdf");
//    QPainter painterG;

//    if (!painterG.begin(&printer))
//    {
//        qDebug() << "###ERROR file not create";
//        return;
//    }

//    chartView->render(&painterG);

//    painterG.end();
//    qDebug() << "CreatePDF end";
//}
