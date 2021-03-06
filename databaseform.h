#ifndef DATABASEFORM_H
#define DATABASEFORM_H

#include <QMainWindow>

namespace Ui {
class DatabaseForm;
}

class DatabaseForm : public QMainWindow
{
    Q_OBJECT

public:
    explicit DatabaseForm(QWidget *parent = 0);
    ~DatabaseForm();

private slots:
    void on_addRecordButton_clicked();
    void addData(std::vector<QString>);

    void on_okButton_clicked();
    void on_header_clicked(int);

    void on_actionSave_triggered();

private:
    Ui::DatabaseForm *ui;
};

#endif // DATABASEFORM_H
