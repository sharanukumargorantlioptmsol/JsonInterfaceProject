#include "jsonparser.h"
#include<QJsonObject>
#include<QDebug>

JsonParser::JsonParser(const QString &filePath) : m_filePath(filePath)
{

}

QJsonObject JsonParser::parseJson() const
{
    // QFile file(m_filePath);
    // if(!file.open(QIODevice::ReadOnly))
    // {
    //     qWarning()<<"couldn't open JSON File";
    //     return {};
    // }
    // QByteArray data = file.readAll();
    // QJsonDocument doc(QJsonDocument::fromJson(data));
    // return doc.object();

        QFile file(m_filePath);  // Ensure m_filePath points to the correct file
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            qWarning() << "Couldn't open JSON file:" << m_filePath;
            return {};  // Return an empty QJsonObject on failure
        }

        QByteArray jsonData = file.readAll();

        file.close();

        QJsonDocument doc(QJsonDocument::fromJson(jsonData));
        if (doc.isNull()) {
            qWarning() << "Failed to parse JSON.";
            return {};  // Return an empty QJsonObject if parsing fails
        }

        return doc.object();  // Return the root JSON object





}

QJsonObject JsonParser::getElectricalData() const
{
    QJsonObject jsonObject = parseJson();
    return jsonObject["Electrical"].toObject();

        // QJsonObject jsonObject = parseJson();
        // qDebug() << "Loaded JSON:" << QJsonDocument(jsonObject).toJson(QJsonDocument::Indented);


        // if (jsonObject.contains("Electrical") && jsonObject["Electrical"].isObject()) {
        //     return jsonObject["Electrical"].toObject();
        // } else {
        //     qWarning() << "Key 'Electrical' does not exist or is not an object.";
        //     return {};  // Return an empty QJsonObject if the key is missing or not an object
        // }





}

QJsonObject JsonParser::getSystemData() const
{
    QJsonObject jsonObject = parseJson();
    return jsonObject["System"].toObject();
}


