#include "commabuilder.h"

CommaBuilder::CommaBuilder(QTableWidget* table): SaveBuilder(table){
    this->sep_type = ',';
}

void CommaBuilder::save(){
    QFile file("CSV.txt");
    if (!file.open(QIODevice::WriteOnly)){
        qDebug("File Cannot Be Saved");
        //return;
    }

    QTextStream str(&file);
    QString alg_str = this->saveAlg();
    str << alg_str;
    file.close();
}
