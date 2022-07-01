#include "printer.h"


QChartView* Printer::CreateGraph (int index, bool colorState, QString type)
{
    QChartView* view;
    if (type == "Диаграмма")
        view = BarGenerator::GetGraph(data[index]->GetRowData(), colorState);
    else if (type == "Круговая диаграмма")
        view = PieGenerator::GetGraph(data[index]->GetRowData(), colorState);
    return view;
}

void Printer::CreatePdf (QChartView* view)
{
    GraphGenerator::CreatePdf(view);
}

void Printer::ParseData (QFileInfo fileInfo)
{
    QString dataType = fileInfo.suffix();

    if(dataType == "sqlite")
        data.append(new DatabaseData(fileInfo));
//    else if (dataType == "json")
//        data.append(new JsonData(fileInfo));
}
