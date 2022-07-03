#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QFileDialog>
#include <QDir>


#include <QtCharts>
#include <QChartView>
#include <QBarSet>
#include <QBarSeries>


#include <QPainter>
#include <QPdfWriter>
#include <QtPrintSupport/QPrintDialog>
#include <QtPrintSupport/QPrinter>


#include "printer.h"

#include "jsonData.h"
#include "databaseData.h"


#include "barGenerator.h"
#include "pieGenerator.h"



QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    // заполнение таблицы файлами, ничего не принимает и не возвращаеи
    void on_ButtonFindFolder_clicked();
    // создание заголовков для таблицы, ничего не принимает и не возвращаеи
    void FullTable();
    // создание пдф графика, ничего не принимает и не возвращаеи
    void on_ButtonCreateGraph_clicked();
    // отрисовка диаграммы, ничего не возвращает, но принимает номер строки и столбйв таблицы
    void on_tableWidget_cellClicked(int row, int column);
    void ShowDiagram(int row, int column);
private:
    Ui::MainWindow *ui;
    // управление данными и отрисовкой
    Printer controller;
    // указатель на построенную диаграмму
    QChartView* chartView = nullptr;
};
#endif // MAINWINDOW_H
