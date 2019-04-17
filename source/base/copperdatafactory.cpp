#include "copperdatafactory.h"
#include <QDebug>

CopperDataFactory::CopperDataFactory()
{

}

CopperData *CopperDataFactory::CreatePattern(int voices, int rows, int dataLength)
{
    CopperData* pattern = new CopperData();
    pattern->Initialize(voices,1,0,"Pattern");
    for (int i=0;i<voices;i++) {
        CopperData* d = new CopperData();
        pattern->m_copperData[i]=d;
        d->Initialize(1,rows,0,"Voice "+QString::number(i));
        for (int j=0;j<rows;j++) {
            d->m_copperData[j] = new CopperData(0,0,dataLength,"Row " +QString::number(j));
        }

    }
    return pattern;
}
