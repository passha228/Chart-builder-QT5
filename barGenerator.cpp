#include "barGenerator.h"

// создание обычной диаграммы
QChartView* BarGenerator::GetGraph(QMap<QString, float> map, bool colorState)
{
    // создаем необходимые переменный для диаграммы
    QChart* chart = new QChart();
    QBarSeries* barSeries = new QBarSeries();
    QStringList categories;

    // заполняем нашу диаграмму сырыми данными
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
    if (colorState) // чб
    {
        int i = 0;
        for(auto set : barSeries->barSets())
        {
            set->setColor(QColor(i, i, i));
                i += 256 / map.size();
        }
    }
    else     // цветной
    {
        for(auto set : barSeries->barSets())
        {
            set->setColor(QColor(qrand()%256, qrand()%256, qrand()%256));
        }
    }

    // записываем готовые серии в чарт и устанавливаем заголовок и анимацию
    chart->addSeries(barSeries);
    chart->setTitle("Some title");
    chart->setAnimationOptions(QChart::SeriesAnimations);

    // создаем готовую диаграмму
    QChartView *view = new QChartView(chart);
    return view;
}

