//#include "jsonData.h"

//JsonData::JsonData()
//{

//}

//void JsonData::GetData (QFileInfo fileInfo)
//{

//    QFile file(fileInfo.absoluteFilePath());
//    if (!file.exists())
//    {
//        qDebug() << "###ERROR###" << "JSON DATA File not found";
//        return;
//    }

//    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
//    {
//        qDebug() << "###ERROR###" << "JSON DATA can not open file";
//        return;
//    }

//    QString jsonText = file.readAll();

//    QJsonParseError err;
//    QJsonDocument doc = QJsonDocument::fromJson(QByteArray(file.readAll()), &err);
//    QJsonObject obj = doc.object();
//    QJsonArray arr = doc.array();

//    file.close();
////    if(arr.empty())
////    {
////        // сделать супер простой json и протестировать
////        // при попытке распарсить происходит проблема
////        qDebug() << "\n\n\n";
////        qDebug() << "### ERROR ###\n" << "arr is empty";
////        qDebug() << err.errorString();
////        qDebug() << fileInfo.absoluteFilePath();
////        qDebug() << "\n\n\n";
////        return;
////    }

//    if(obj.empty())
//    {
//        qDebug() << "\n\n\n";
//        qDebug() << "### ERROR ###\n" << "obj is empty";
//        qDebug() << err.errorString();
//        qDebug() << fileInfo.absoluteFilePath();
//        qDebug() << "\n\n\n";
//        return;
//    }


//    QMap<QString, int > map;
//    for(auto it = obj.begin(); it < obj.end(); it++)
//    {
//        map.insert(it.key(), it.value().toInt());
//        qDebug() << it.key() << " " << it.value();
//    }


//    barSeries = new QBarSeries();
//    pieSeries = new QPieSeries();
//    QStringList categories;

//    int count = 0;
//    for(auto elem = map.begin(); elem != map.end(); elem++)
//    {
//        count++;
//        if (count > 10)
//            break;
//        QBarSet* bar = new QBarSet(elem.key());
//        pieSeries->append(elem.key(), elem.value());
//        qDebug() << elem.key();
//        qDebug() << elem.value();
//        categories.append(elem.key());
//        *bar << elem.value();
//        barSeries->append(bar);
//    }

//    qDebug() << "String list created and fulled";
//}
