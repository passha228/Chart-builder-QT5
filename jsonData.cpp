#include "jsonData.h"

// создаем json данные
JsonData::JsonData(QFileInfo fileInfo)
{
    // открываем файл по полученному пути
    QFile file(fileInfo.absoluteFilePath());
    // проверка на отсутсвие файла
    if (!file.exists())
    {
        qDebug() << "###ERROR###" << "JSON DATA File not found";
        except("Файл не найден");
        return;
    }

    // проверка на возможность открытия файла
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug() << "###ERROR###" << "JSON DATA can not open file";
        except("Файл не открылся");
        return;
    }

    // собираем весь сырой текст из файла
    QString jsonText = file.readAll();
    file.close();   // обязательно закрываем его

    // создаем необходимые для json переменные
    // ошибка, чтобы знать что пошло не так с json
    QJsonParseError err;
    QJsonDocument doc = QJsonDocument::fromJson(QByteArray(jsonText.toUtf8()), &err); // здесь уже парсим наши данные для преставления их в QJsonArray
    // массив был взять потому что данные хранятся в связке ключ значение
    QJsonArray arr = doc.array();   // здесь будут все наши данные в виде массива


    // проверка, что массив с данными не создался
    if(arr.empty())
    {
        qDebug() << "\n\n\n";
        qDebug() << "### ERROR ###\n" << "arr is empty";
        except("Проблемы с содержимым" + err.errorString());
        qDebug() << err.errorString();
        qDebug() << fileInfo.absoluteFilePath();
        qDebug() << "\n\n\n";
        return;
    }

    // заполнение словаря данными из json
    int i = 0;
    foreach(const QJsonValue& value, arr)
    {
        if(value.isObject() && i < 10)
        {
            QJsonObject obj = value.toObject();
            QString key = obj["Time"].toString();
            float val = obj["Value"].toDouble();
            data.insert(key, val);
        }
    }

}
