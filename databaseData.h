#ifndef DATABASEDATA_H
#define DATABASEDATA_H

#include "printer.h"
#include <memory>

#include <QAbstractSeries>
#include <QBarSeries>
#include <QPieSeries>

class DatabaseData : public Printer
{
private:

public:
    DatabaseData();
    void GetData (QMap<QString, int>) override;
    //void PrintGraph() override;

};

#endif // DATABASEDATA_H
