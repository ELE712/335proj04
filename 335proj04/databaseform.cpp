#include "databaseform.h"
#include "ui_databaseform.h"
#include "addrecordform.h"

DatabaseForm::DatabaseForm(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::DatabaseForm)
{
    ui->setupUi(this);
    ui->tableWidget->setRowCount(0);
    ui->tableWidget->setColumnCount(4);
    ui->tableWidget->
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
    ui->tableWidget->setItem(t_row, 0, new QTableWidgetItem(str_vec[0]));
    ui->tableWidget->setItem(t_row, 1, new QTableWidgetItem(str_vec[1]));
    ui->tableWidget->setItem(t_row, 2, new QTableWidgetItem(str_vec[2]));
    ui->tableWidget->setItem(t_row, 3, new QTableWidgetItem(str_vec[3]));
}

void DatabaseForm::on_okButton_clicked()
{
    this->close();
}


