#include "mainwindow.h"
#include "ui_mainwindow.h"

//--------------------------------------------------------------------------------
//--------------------------------------------------------------------------------
//--------------------------------------------------------------------------------
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    FullTable();
    //on_ButtonFindFolder_clicked();
    //connect(ui->ButtonCreateGraph, SIGNAL(clicked()),this,SLOT(createGraph()));
}


//--------------------------------------------------------------------------------
// входных и выходных параметров нет
// только лишь заполняет таблицу первоначальными значениями
void MainWindow::FullTable()
{
    ui->tableWidget->setColumnCount(4);
    QStringList name_table;
    name_table  << "Name" << "Size" << "Type" << "Date Modifed";
    ui->tableWidget->setHorizontalHeaderLabels(name_table);
}




//--------------------------------------------------------------------------------
// строит пдф
//void MainWindow::createGraph()
//{
//    qDebug() << "on_ButtonCreateGraph_clicked";
//    if (chartView != nullptr)
//        controller.CreatePdf(chartView);
//}
/*
void foo()
{
    QString str = QFileDialog::getOpenFileName();
    QSqlDatabase dbase = QSqlDatabase::addDatabase("QSQLITE");
    dbase.setDatabaseName(str);
    if (!dbase.open()) {
            qDebug() << "Что-то пошло не так!";
            return;
        }
    QSqlQuery a_query(dbase);


    QSqlTableModel *model = new QSqlTableModel(this);
    model->setTable("HUMIDITY_MOSCOW");



    if (!a_query.exec("SELECT * FROM HUMIDITY_MOSCOW")) {
                qDebug() << "Даже селект не получается, я пас.";
                return;
            }

        QMap<QString, int> map;

        while(a_query.next())
        {
                map.insert(a_query.value(0).toString(), a_query.value(1).toInt());
        }

        qDebug() << "Data attached\n";
        QBarSeries *series = new QBarSeries();
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
            series->append(bar);
        }

        qDebug() << "String list created and fulled\n";

        QChart* chart = new QChart();
        chart->addSeries(series);
        chart->setTitle("Some title");
        chart->setAnimationOptions(QChart::SeriesAnimations);


        QBarCategoryAxis* axis = new QBarCategoryAxis();
        axis->append(categories);

        chart->createDefaultAxes();
        //chart->setAxisX(axis, series);
        QChart::ChartTheme
        QChartView *view = new QChartView(chart);
        view->setParent(ui->Charts);
        qDebug() << "QChartView created and fulled\n";

}

*/


//--------------------------------------------------------------------------------
// посмотреть что здесь убрать
// вариант, где внутри папки есть еще вложенные не рассматривается
void MainWindow::on_ButtonFindFolder_clicked()
{
    qDebug() << "on_ButtonFindFolder_clicked";
    QString folderName = QFileDialog::getExistingDirectory(this);
    QDir dir(folderName);
    dir.setFilter(QDir::Files);
    QFileInfoList files = dir.entryInfoList();
    for (int i = 0; i < files.size(); ++i)
    {
        QFileInfo fileInfo = files.at(i);
        ui->tableWidget->insertRow(ui->tableWidget->rowCount());
        ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, 0, new QTableWidgetItem(fileInfo.fileName()));

        float size = fileInfo.size();
        int divCount = 0;
        while(size > 1024){size/=1024; divCount++;}
        QString str;
        str = QString::number(size);
        switch(divCount)
        {
        case 0:
            str += " bytes";
            break;
        case 1:
            str += " KBytes";
            break;
        case 2:
            str += " MBytes";
            break;
        case 3:
            str += " GBytes";
            break;
        }
        ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, 1, new QTableWidgetItem(str));

        ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, 2, new QTableWidgetItem(fileInfo.suffix()));

        ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, 3, new QTableWidgetItem(fileInfo.lastModified().toString()));

//        if (fileInfo.suffix() == "sqlite")
//            controller
//        else if (fileInfo.suffix() == "json")
//            dataList.append(new JsonData());
        controller.ParseData(fileInfo);

    }
}


//--------------------------------------------------------------------------------
// слот на нажатие кнопки "Построить диаграмму"
// строит пдф график в папке
void MainWindow::on_ButtonCreateGraph_clicked()
{
    qDebug() << "on_ButtonCreateGraph_clicked";
    if (chartView != nullptr)
        controller.CreatePdf(chartView);
    else
    {
        qDebug() << "chartView is nullptr";
        QMessageBox messageBox;
        messageBox.warning(0,"Ошибка","Графика нет!");
        messageBox.setFixedSize(500,200);
        return;
    }
}


//--------------------------------------------------------------------------------
MainWindow::~MainWindow()
{
    delete ui;
}


//--------------------------------------------------------------------------------
// слот на нажатие ячейки в таблице
// принимает номер строки и столбца таблицы
// ничего не возвращает
// строит диаграмму соответствуюших данных
void MainWindow::on_tableWidget_cellClicked(int row, int column)
{
    ShowDiagram(row, column);
}

void MainWindow::ShowDiagram(int row, int column)
{
    int currentIndex = ui->BoxGraphType->currentIndex();
    QString currentType = ui->BoxGraphType->itemText(currentIndex);

    chartView = controller.CreateGraph(row, ui->BoxColorGraph->checkState(), currentType);
    if (chartView == nullptr)
    {
        QMessageBox messageBox;
        messageBox.warning(0,"Ошибка","Неверный формат файла, его нельзя прочитать!");
        messageBox.setFixedSize(500,200);
        return;
    }
    chartView->setParent(ui->Charts);
    chartView->show();
}
