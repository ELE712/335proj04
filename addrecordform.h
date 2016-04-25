/******************************************************
 ** FILE: addrecordform.h
 **
 ** ABSTRACT:
 ** Create class to add records to form, uses buttons
 **
 **
 ** AUTHOR: Ezekiel Zandbergen, Cynthia Obia
 **
 ** CREATION DATE: 4-24-16
 **
 *******************************************************/
 
 #ifndef ADDRECORDFORM_H
#define ADDRECORDFORM_H

#include <QDialog>

namespace Ui {
class AddRecordForm;
}

class AddRecordForm : public QDialog
{
    Q_OBJECT

public:
    explicit AddRecordForm(QWidget *parent = 0);
    ~AddRecordForm();
signals:
    void formSent(std::vector<QString>);
private slots:
    void on_buttonBox_accepted();

private:
    Ui::AddRecordForm *ui;
};

#endif // ADDRECORDFORM_H
