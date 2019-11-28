#include "w_add_user.h"
#include "ui_w_add_user.h"
#include <QDialog>
#include "class_user.h"

W_Add_User::W_Add_User(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::W_Add_User)
{
    ui->setupUi(this);
}

W_Add_User::~W_Add_User()
{
    delete ui;
}

void W_Add_User::on_pushButton_2_clicked() //add user
{
    std::string username,ip,port;
    username = ui->lineEdit->text().toStdString();
    ip = ui->lineEdit_2->text().toStdString();
    port = ui->lineEdit_3->text().toStdString();

    if(username == "" || port == "" || ip == ""){
        QMessageBox::critical(this,"Error!","Something went wrong! Cannot add user");
    }

    if(Users->add_user(username,ip,port)){
        QMessageBox::information(this,"Succes","User added!");
    }
    else{
        QMessageBox::critical(this,"Error!","Something went wrong! Cannot add user");
    }
    W_Add_User::close();
}

void W_Add_User::on_pushButton_clicked()
{
    QMessageBox::information(this,"Operation aborted","Operation aborted, no changes were made.");
    W_Add_User::close();
}
