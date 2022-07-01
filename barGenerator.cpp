#include "barGenerator.h"


QChartView* BarGenerator::GetGraph(QMap<QString, float> map, bool colorState)
{
    QChart* chart = new QChart();
    QBarSeries* barSeries = new QBarSeries();
    QStringList categories;

    int count = 0;
    for(auto elem = map.begin(); elem != map.end(); elem++)
    {
        count++;
        if (count > 10)
            break;
        QBarSet* bar = new QBarSet(elem.key());
        categories.append(elem.key());
        *bar << elem.value();
        barSeries->append(bar);
    }

    qDebug() << "Серия баров создана";

    //смена цвета
    // чб
    if (colorState)
    {
        int i = 0;
        for(auto set : barSeries->barSets())
        {
            set->setColor(QColor(i, i, i));
                i += 256 / map.size();
        }
    }
    // цветной
    else
    {
        for(auto set : barSeries->barSets())
        {
            set->setColor(QColor(qrand()%256, qrand()%256, qrand()%256));
        }
    }

    chart->addSeries(barSeries);
    chart->setTitle("Some title");
    chart->setAnimationOptions(QChart::SeriesAnimations);
    QChartView *view = new QChartView(chart);
    return view;
}

