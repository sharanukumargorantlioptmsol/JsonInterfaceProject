#ifndef IJSONPARSER_H
#define IJSONPARSER_H
#include <QJsonObject>

class IJsonParser
{
public:
        IJsonParser();
        virtual ~IJsonParser() = default;
        virtual QJsonObject getElectricalData() const = 0;
        virtual QJsonObject getSystemData() const = 0;

};

#endif // IJSONPARSER_H
