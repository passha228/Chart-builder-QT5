#include "databaseData.h"

DatabaseData::DatabaseData()
{

}


void DatabaseData::GetData (QMap<QString, int> map)
{
    barSeries = new QBarSeries();
    pieSeries = new QPieSeries();
    QStringList categories;

    int count = 0;
    for(auto elem = map.begin(); elem != map.end(); elem++)
    {
        count++;
        if (count > 10)
            break;
        QBarSet* bar = new QBarSet(elem.key());
        pieSeries->append(elem.key(), elem.value());

        categories.append(elem.key());
        *bar << elem.value();
        barSeries->append(bar);
    }

    qDebug() << "String list created and fulled";
    //std::shared_ptr<QAbstractSeries*> popa(&a);

    //return series;
}
