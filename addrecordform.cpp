/******************************************************
 ** FILE: addrecordform.cpp
 **
 ** ABSTRACT:
 ** Create class to add records
 **
 **
 ** AUTHOR: Ezekiel Zandbergen, Cynthia Obia
 **
 ** CREATION DATE: 4-24-16
 **
 *******************************************************/

#include "addrecordform.h"
#include "ui_addrecordform.h"
#include "databaseform.h"

AddRecordForm::AddRecordForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddRecordForm)
{
    ui->setupUi(this);
}

AddRecordForm::~AddRecordForm()
{
    delete ui;
}

void AddRecordForm::on_buttonBox_accepted()
{
    std::vector<QString> str_vec;
    str_vec.push_back(ui->FirstText->text());
    str_vec.push_back(ui->LastText->text());
    str_vec.push_back(ui->SalaryText->text());
    str_vec.push_back(ui->YearText->text());
    emit formSent(str_vec);
}
