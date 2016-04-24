#ifndef TABBUILDER_H
#define TABBUILDER_H
#include "savebuilder.h"

class TabBuilder : public SaveBuilder
{
public:
    TabBuilder();
    TabBuilder(QTableWidget*);
    virtual void save();
};

#endif // TABBUILDER_H
