#ifndef COPPERDATA_H
#define COPPERDATA_H

#include <QStringList>
#include <QString>
#include <QVector>
#include <QByteArray>

class CopperData
{
public:
    CopperData();
    CopperData(int w, int h, int dataLength, QString name) {
        Initialize(w,h,dataLength,name);
    }
    int m_width, m_height;
    QVector<CopperData*> m_copperData;

    void Initialize(int w, int h, int dataLength, QString name);

    void getText(QString& text);

    QString m_name;
    QByteArray m_data;

};

#endif // COPPERDATA_H
