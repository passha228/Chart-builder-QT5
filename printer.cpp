#include "printer.h"

//--------------------------------------------------------------------------------
//--------------------------------------------------------------------------------
//--------------------------------------------------------------------------------
//создание графика
QChartView* Printer::CreateGraph (int index, bool colorState, QString type)
{
    // проверка на правильность файла
    if (data[index] == nullptr)
        return nullptr;

    if (view != nullptr)
    {
        delete view;
    }
    // проверяем тип графика
    if (type == "Диаграмма")
        // вызываем метод для обычной диаграммы
        view = BarGenerator::GetGraph(data[index]->GetRowData(), colorState);
    else if (type == "Круговая диаграмма")
        // вызываем метод для круговой диаграммы
        view = PieGenerator::GetGraph(data[index]->GetRowData(), colorState);
    return view;
}


//--------------------------------------------------------------------------------
//создание пдф
void Printer::CreatePdf (QChartView* view = nullptr)
{
    // если у нас есть нарисованный график, то рисуем его в пдф
    if (view != nullptr)
        GraphGenerator::CreatePdf(view);
}


//--------------------------------------------------------------------------------
// сбор данных
void Printer::ParseData (QFileInfo fileInfo)
{
    // определяем тип файла
    QString dataType = fileInfo.suffix();

    if(dataType == "sqlite")
        data.append(new DatabaseData(fileInfo)); // БД
    else if (dataType == "json")
        data.append(new JsonData(fileInfo));     // JSON
    else
        data.append(nullptr);                    // неправильный тип файла
}
