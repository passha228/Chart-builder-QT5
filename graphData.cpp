#include "graphData.h"

void GraphData::except(QString str)
{
    QMessageBox messageBox;
    messageBox.warning(0,"Ошибка","Упс\n" + str);
    messageBox.setFixedSize(500,200);
    qDebug() << "###ERROR file not read";
    return;
}
