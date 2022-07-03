#include "pieGenerator.h"

// создание кругового графика
QChartView* PieGenerator::GetGraph(QMap<QString, float> map, bool colorState)
{
    // определение необходимых переменных
    QChart* chart = new QChart();
    QPieSeries* pieSeries = new QPieSeries();
    QStringList categories;

    // сбор сырых данных из словаря
    // проходимся по всему словарю и преобразовываем сырые данные к круговой диаграмме
    int count = 0;
    for(auto elem = map.begin(); elem != map.end(); elem++)
    {
        count++;
        if (count > 10)
            break;
        categories.append(elem.key());
        pieSeries->append(elem.key(), elem.value());
    }

    // просто дебаг для отлавливания каких-нибудь ошибок в консоли
    qDebug() << "Серия баров создана";

    //смена цвета
    if (colorState) // чб
    {
        // выставляем цвет для каждого куосчка диаграммы нулевой и увеличиваем его каждый шаг, чтобы получался планый переход
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
        // делаем то же самое что и в прошлый раз, только выставляем рандомный цвет
        for(auto set : pieSeries->slices())
        {
            set->setColor(QColor(qrand()%256, qrand()%256, qrand()%256));
        }
    }

    // записываем готовые серии в чарт и устанавливаем заголовок и анимацию
    chart->addSeries(pieSeries);
    chart->setTitle("Pie");
    chart->setAnimationOptions(QChart::SeriesAnimations);
    // создаем готовую диаграмму
    QChartView *view = new QChartView(chart);
    return view;
}
