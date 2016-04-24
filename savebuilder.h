#ifndef SAVEBUILDER_H
#define SAVEBUILDER_H

#include <QTextStream>
#include <QTableWidget>
#include <QString>
#include <QFile>

class SaveBuilder
{
protected:

    char sep_type; //separate value type not used in base class
    QTableWidget* m_table;
public:
    virtual QString saveAlg();
    SaveBuilder();
    SaveBuilder(QTableWidget*);
    virtual void save()=0;
};

#endif // SAVEBUILDER_H
