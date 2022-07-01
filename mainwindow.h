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
    void on_ButtonFindFolder_clicked();
    void FullTable();
    void on_ButtonCreateGraph_clicked();
    //void createGraph();
    void showDiagram(int row, int col);
    void on_tableWidget_cellClicked(int row, int column);

private:
    Ui::MainWindow *ui;
    Printer controller;
    QChartView* chartView = nullptr;
};
#endif // MAINWINDOW_H
