#include "databaseform.h"
#include "ui_databaseform.h"
#include "addrecordform.h"
#include <QTableView>
#include <QFile>
#include <QString>

DatabaseForm::DatabaseForm(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::DatabaseForm)
{
    ui->setupUi(this);
    ui->tableWidget->setRowCount(0);
    ui->tableWidget->setColumnCount(4);
    QHeaderView* m_header = ui->tableWidget->horizontalHeader(); //headers
    connect(m_header, SIGNAL(sectionClicked(int)), this, SLOT(on_header_clicked(int))); //header connection
    //
}

DatabaseForm::~DatabaseForm()
{
    delete ui;
}

void DatabaseForm::on_addRecordButton_clicked()
{
    AddRecordForm* form = new AddRecordForm();
    form->show();
    connect(form, SIGNAL(formSent(std::vector<QString>)), this, SLOT(addData(std::vector<QString>)));
}

void DatabaseForm::addData(std::vector<QString> str_vec){
    int t_row = ui->tableWidget->rowCount();
    ui->tableWidget->setRowCount(t_row+1); //add one row, t_row in correct index
    ui->tableWidget->setItem(t_row, 0, new QTableWidgetItem(str_vec[0])); //first and last name
    ui->tableWidget->setItem(t_row, 1, new QTableWidgetItem(str_vec[1]));

    QTableWidgetItem* sal_item = new QTableWidgetItem; //item for salary
    int sal_int = str_vec[2].toInt(); //get integer value
    sal_item->setData(Qt::EditRole, sal_int); //save int in data

    QTableWidgetItem* year_item = new QTableWidgetItem; //same for year
    int year_int = str_vec[3].toInt();
    year_item->setData(Qt::EditRole, year_int);

    ui->tableWidget->setItem(t_row, 2, sal_item); //salary and year
    ui->tableWidget->setItem(t_row, 3, year_item);
}

void DatabaseForm::on_okButton_clicked()
{
    this->close();
}

void DatabaseForm::on_header_clicked(int index){
    qDebug("Index clicked: %d", index);
    ui->tableWidget->sortByColumn(index);


}



void DatabaseForm::on_actionSave_triggered()
{
    QFile file("CSV.txt");
    //QFile t_file("TSV.txt");
    int row_count = ui->tableWidget->rowCount();

    if (!file.open(QIODevice::WriteOnly)){
        qDebug("Uh oh");
        return;
    }

    QTextStream c_str(&file);
    for (int i=0; i<row_count; i++){ //each row
        for (int j=0; j<4; j++){ //each column in row
            c_str << ui->tableWidget->item(i,j)->text() << ",";
            //QString test = ui->tableWidget->item(i,j)->text();
        }
        c_str << "\n";
    }
    qDebug("Got here");
    file.close();

/*
    if (t_file.open(QIODevice::WriteOnly | QIODevice::Text)){
        qDebug("Uh Oh v2");
        return;
    }
    QTextStream t_str(&t_file);
    for (int i=0; i<row_count; i++){ //each row
        for (int j=0; j<4; j++){ //each column in row
            t_str << ui->tableWidget->item(i,j)->text() << ",";
        }
        t_str << "\n";
    }
    */


    /*
    CommaBuilder cb;
    TabBuilder tb;
    int row_count = ui->tableWidget->rowCount();
    for (int i=0; i<row_count; i++){ //each row
        for (int j=0; j<4; j++){ //each column in row
            cb.addItem(ui->tableWidget->item(i,j)->text());
            tb.addItem(ui->tableWidget->item(i,j)->text());
        }
    }
    //cb.saveFile();
    //tb.saveFile();
    */
}
