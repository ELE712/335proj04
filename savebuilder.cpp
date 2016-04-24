#include "savebuilder.h"
#include <QString>

SaveBuilder::SaveBuilder(){
    this->sep_type = '?'; //shouldn't ever be used
}

SaveBuilder::SaveBuilder(QTableWidget* table){
    this->m_table = table;
}

QString SaveBuilder::saveAlg(){
    QTableWidget* table = this->m_table; //easier reading
    int row_count = table->rowCount();
    char s = this->sep_type;
    //this is actually the easiest way to set the headers
    QString str = QString("FirstName%1LastName%2Salary%3HiringYear\n").arg(s).arg(s).arg(s);
    for (int i=0; i<row_count; i++){ //each row
        for (int j=0; j<4; j++){ //each column in row
            str.append(table->item(i,j)->text());
            if (j<3) //add separation type between all, none at end
                str.append(this->sep_type);
        }
        str.append("\n");
    }
    return str;
}
