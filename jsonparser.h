#ifndef JSONPARSER_H
#define JSONPARSER_H

#include "ijsonparser.h"
#include<QFile>
#include<QJsonDocument>

class JsonParser : public IJsonParser
{
    public:
        explicit JsonParser(const QString &filePath);
        QJsonObject getElectricalData() const override;
        QJsonObject getSystemData() const override;
    private:
        QString m_filePath;
        QJsonObject parseJson() const;


};

#endif // JSONPARSER_H
