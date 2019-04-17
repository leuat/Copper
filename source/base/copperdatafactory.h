#ifndef COPPERDATAFACTORY_H
#define COPPERDATAFACTORY_H

#include <source/base/copperdata.h>

class CopperDataFactory
{
public:
    CopperDataFactory();

    static CopperData* CreatePattern(int voices, int rows, int dataLength);

};

#endif // COPPERDATAFACTORY_H
