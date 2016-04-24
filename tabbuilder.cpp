#include "tabbuilder.h"

TabBuilder::TabBuilder(QTableWidget* table): SaveBuilder(table){
    this->sep_type = '\t';
}

void TabBuilder::save(){ //handles TSV
    QFile file("TSV.txt");
    if (!file.open(QIODevice::WriteOnly)){
        qDebug("File Cannot Be Saved");
        //return;
    }
    QTextStream str(&file);
    QString alg_str = this->saveAlg();
    str << alg_str;
    file.close();
}
