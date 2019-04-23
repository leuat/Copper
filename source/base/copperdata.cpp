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

void CopperData::getText(QString& text, QPoint focus, QPoint cur )
{
    if (m_data.count()!=0) {
        QString r;
        r+="<td>&nbsp;</td>";
        for (int i=0;i<m_data.count();i++) {
            bool hasFocus= (cur.y()==focus.y() && (cur.x()+i==focus.x()));

            if (hasFocus) r+="<td bgcolor=\"#303080\"><font color=\"#000000\">"; else r+="<td>";
            r+=QString::number((unsigned char)m_data[i],16).rightJustified(2, '0') + " ";
            if (hasFocus) r+="</font></td>"; else
            r+="</td>";
        }
        r+="<td>&nbsp;</td>";
        text+=r;
    }
    if (m_copperData.count()!=0) {
        QStringList ttxts;
        for (int y=0;y<m_height;y++) {
            for (int x=0;x<m_width;x++) {
                QString t;
                //            qDebug() << "WOOT" << x << "," <<y;
                m_copperData[x+y*m_width]->getText(t, focus, cur + QPoint(x*getTotalWidth()/m_width,y*getTotalHeight()/m_height));
//                m_copperData[x+y*m_width]->getText(t, focus, cur);
//                          qDebug() << t;
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
            text+="<tr>";
            for (int x=0;x<std::max(m_width,m_height);x++) {
                text += dlist[x][y] + "  ";
            }
            text += "</tr>";
        }


    }


}

int CopperData::getTotalWidth()
{
    if (m_copperData.count()==0)
        return m_data.count();

    return m_width*m_copperData[0]->getTotalWidth();
}

int CopperData::getTotalHeight()
{
    if (m_copperData.count()==0)
        return 1;

    return m_height*m_copperData[0]->getTotalHeight();

}

