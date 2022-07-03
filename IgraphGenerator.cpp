#include "IgraphGenerator.h"

// создание пдф
void GraphGenerator::CreatePdf(QChartView* chartView)
{
    // куда сохраниться файл
    QString name = QFileDialog::getSaveFileName();
    // далее создаем принтер и выставляем ему необходимые параметры
    QPrinter printer;
    qDebug() << "CreatePDF";
    printer.setOutputFormat(QPrinter::PdfFormat); // вывод в пдф
    printer.setOutputFileName(name);              // путь и имя файла
    // создание рисовальщика, который умеет работать с изображениями
    QPainter painterG;

    // начинаем отрисовывать и попутно проверяем все ли отриосвалось, если нет, то это ошибка
    if (!painterG.begin(&printer))
    {
        QMessageBox messageBox;
        messageBox.warning(0,"Ошибка","Упс\nЧто-то пошло не так!");
        messageBox.setFixedSize(500,200);
        qDebug() << "###ERROR file not create";
        return;
    }

    // отрисовка графика
    chartView->render(&painterG);

    // обязательно закончить рисование
    painterG.end();
    qDebug() << "CreatePDF end";
}












//QChartView* GraphGenerator::GeneratePie(QPieSeries* series, bool colorState)
//{
//    QChart* chart = new QChart();

//    //смена цвета
//    // чб
//    if (colorState)
//    {
//        int i = 0;
//        for(auto set : series->slices())
//        {
//            set->setColor(QColor(i, i, i));
//                i+=25;
//        }
//    }
//    // цветной
//    else
//    {
//        for(auto set : series->slices())
//        {
//            set->setColor(QColor(qrand()%256, qrand()%256, qrand()%256));
//        }
//    }

//    chart->addSeries(series);
//    chart->setTitle("Some title");
//    chart->setAnimationOptions(QChart::SeriesAnimations);
//    QChartView *view = new QChartView(chart);
//    return view;
//}

//QChartView* GraphGenerator::GenerateBar(QBarSeries* series, bool colorState)
//{
//    QChart* chart = new QChart();

//    //смена цвета
//    // чб
//    if (colorState)
//    {
//        int i = 0;
//        for(auto set : series->barSets())
//        {
//            set->setColor(QColor(i, i, i));
//                i+=25;
//        }
//    }
//    // цветной
//    else
//    {
//        for(auto set : series->barSets())
//        {
//            set->setColor(QColor(qrand()%256, qrand()%256, qrand()%256));
//        }
//    }

//    chart->addSeries(series);
//    chart->setTitle("Some title");
//    chart->setAnimationOptions(QChart::SeriesAnimations);
//    QChartView *view = new QChartView(chart);
//    return view;
//}

//void GraphGenerator::CreatePdf(QChartView* chartView)
//{
//    QPrinter printerGrayColor;
//    qDebug() << "CreatePDF";
//    printerGrayColor.setOutputFormat(QPrinter::PdfFormat);
//    printerGrayColor.setOutputFileName("D:/TSU/PDFresult.pdf");
//    QPainter painterG;

//    if (!painterG.begin(&printerGrayColor))
//    {
//        qDebug() << "###ERROR file not create";
//        return;
//    }

//    chartView->render(&painterG);

//    painterG.end();
//    qDebug() << "CreatePDF end";
//}
