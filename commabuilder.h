#ifndef COMMABUILDER_H
#define COMMABUILDER_H
#include "savebuilder.h"

class CommaBuilder : public SaveBuilder
{
public:
    CommaBuilder();
    CommaBuilder(QTableWidget*);
    virtual void save();
};

#endif // COMMABUILDER_H
