#include "copperdata.h"
#include <QDebug>
#include <math.h>

CopperData::CopperData()
{

}

void CopperData::Initialize(int w, int h, int dataLength, QString n)
{
    m_width = w;
    m_height = h;
    if (w*h!=0)
        m_copperData.resize(w*h);

    m_name = n;
    if (dataLength!=0) {
        m_data.resize(dataLength);
        for (int i=0;i<dataLength;i++)
            m_data[i] = (char)rand()%255;
    }
}

void CopperData::getText(QString& text)
{
    if (m_data.count()!=0) {
        QString r;
        r = "[ ";
        for (int i=0;i<m_data.count();i++)
            r+=QString::number((unsigned char)m_data[i],16).rightJustified(2, '0') + " ";
            //r+=QString("%1").arg((unsigned char)m_data[i], 5, 16, QChar('0'));
        r+="] ";
        text+=r;
    }
    if (m_copperData.count()!=0) {
        QStringList ttxts;
        for (int y=0;y<m_height;y++) {
            for (int x=0;x<m_width;x++) {
                QString t;
                //            qDebug() << "WOOT" << x << "," <<y;
                m_copperData[x+y*m_width]->getText(t);
                //          qDebug() << t;
                ttxts << t;
            }
  //          ttxts << "\n";

        }
  //      qDebug() << ttxts;
        if (m_width==1) {
            for (QString s: ttxts) text+=s+"\n";
            return;
        }
        QVector<QStringList> dlist;
        for (int i=0;i<ttxts.count();i++)
            dlist.append(ttxts[i].split("\n"));


        for (int y=0;y<dlist[0].count();y++) {
            for (int x=0;x<std::max(m_width,m_height);x++) {
                text += dlist[x][y] + "  ";
            }
            text += "\n";
        }


    }


}
