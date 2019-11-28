#include "edit_config.h"
#include "ui_edit_config.h"
#include "utility.h"
#include "class_config.h"

Edit_Config::Edit_Config(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Edit_Config)
{
    ui->setupUi(this);


    if(!(config_server->check_config())){
        ui->lineEdit->setText("not_found");
        ui->lineEdit_2->setText("not_found");
    }
    else{
        ui->lineEdit->setText(config_server->ip.c_str());
        ui->lineEdit_2->setText(config_server->port.c_str());
    }
    ui->lineEdit->setText(config_server->ip.c_str());
    ui->lineEdit_2->setText(config_server->port.c_str());

    //ui->lineEdit->update();
    //ui->lineEdit_2->update();
    update();

    std::cout<<"found: "<<config_server->ip.c_str()<<" "<<config_server->port.c_str()<<std::endl;
}

Edit_Config::~Edit_Config()
{
    delete ui;
}

void Edit_Config::on_pushButton_clicked()
{
    if(ui->lineEdit->text().toStdString() == "not_found"){
        QMessageBox::critical(this,"Error","No changes were made. Please input a working ip address");
        return;
    }
    if(ui->lineEdit_2->text().toStdString() == "not_found"){
        QMessageBox::critical(this,"Error","No changes were made. Please input a working port");
        return;
    }

    if(config_server->set_config(ui->lineEdit->text().toStdString(),ui->lineEdit_2->text().toStdString())){
        QMessageBox::information(this,"Succes","Succes! New data saved!");
        Edit_Config::close();
    }
    else {
        QMessageBox::critical(this,"Error","Error! No changes were made.");
    }

}

void Edit_Config::on_pushButton_2_clicked() //what is my ip
{
    system("start https://www.whatismyip.com");
}
