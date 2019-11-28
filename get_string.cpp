#include "get_string.h"
#include "ui_get_string.h"

Get_String::Get_String(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Get_String)
{
    ui->setupUi(this);
}

Get_String::~Get_String()
{
    delete ui;
}

void Get_String::on_pushButton_clicked()
{
    get_message_value = ui->lineEdit->text().toStdString();
    Get_String::close();

}

void Get_String::on_pushButton_2_clicked()
{
    if(get_message_value == "")
        Get_String::close();
}
