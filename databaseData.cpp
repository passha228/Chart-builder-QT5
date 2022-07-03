#include "databaseData.h"

// создаем БД данные
DatabaseData::DatabaseData(QFileInfo fileInfo)
{
    // открываем базу данных
    QSqlDatabase dbase = QSqlDatabase::addDatabase("QSQLITE");
    dbase.setDatabaseName(fileInfo.absolutePath() + "/" + fileInfo.fileName());
    // проверяем что база успешно открылась
    if (!dbase.open()) {
            qDebug() << "База" << fileInfo.fileName() << "не была собрана";
            qDebug() << fileInfo.absolutePath();
            data.insert("0", 0);
            return;
        }
    qDebug() << "База" << fileInfo.fileName() << "собрана";
    QSqlQuery a_query(dbase); // создаем переменную для БД

    // определение имени таблицы
    // имя определяется как имя самого файла
    QString tableName = "";
    for (int j = 0; fileInfo.fileName()[j] != "."; j++) tableName+=fileInfo.fileName()[j];
        if (!a_query.exec("SELECT * FROM " + tableName))
        {
            qDebug() << "Выборка не произведена";
            qDebug() << "SELECT * FROM " + tableName;
            return;
        }
    qDebug() << "Выборка произведена " << tableName;

    // заполняем базу до тех пор пока не кончатся и не более 10 штук
    int i = 0;
    while(a_query.next() && i < seriesCount)
    {
        data.insert(a_query.value(0).toString(), a_query.value(1).toFloat());
        i++;
    }
    qDebug() << "Данные собраны";
}



//void DatabaseData::GetData (QFileInfo fileInfo)
//{

//    QSqlDatabase dbase = QSqlDatabase::addDatabase("QSQLITE");
//    dbase.setDatabaseName(fileInfo.absolutePath() + "/" + fileInfo.fileName());
//    if (!dbase.open()) {
//            qDebug() << "Что-то пошло не так!";
//            qDebug() << fileInfo.absolutePath();
//            return;
//        }
//    QSqlQuery a_query(dbase);


//    QSqlTableModel *model = new QSqlTableModel();
//    model->setTable("HUMIDITY_MOSCOW");


//    QString tableName = "";
//    for (int j = 0; fileInfo.fileName()[j] != "."; j++) tableName+=fileInfo.fileName()[j];
//    if (!a_query.exec("SELECT * FROM " + tableName)) {
//                qDebug() << "Даже селект не получается, я пас.";
//                qDebug() << "SELECT * FROM " + tableName;
//                return;
//            }

//    QMap<QString, int> map;
//    while(a_query.next())
//    {
//            map.insert(a_query.value(0).toString(), a_query.value(1).toInt());
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
//        categories.append(elem.key());
//        *bar << elem.value();
//        barSeries->append(bar);
//    }

//    qDebug() << "String list created and fulled";
//}
