#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "w_add_user.h"
#include "class_user.h"
#include "class_config.h"
#include "QFileDialog"
#include "get_string.h"
#include "edit_config.h"




MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //this->setStyleSheet("color: white; background-color: #232323;");


    QWidget::setWindowTitle("LPM TCP file transfer v1.1");

    Users->load_users();
    std::string tmp;

    for(int i=0;i < Users->number_of_users;i++){
        tmp = Users->user[i].user_name.c_str();
        tmp += "  ||  ";
        tmp +=  Users->user[i].ip.c_str();
        tmp += "  ||  ";
        tmp +=  Users->user[i].port.c_str();


        ui->listWidget->addItem(tmp.c_str());
        ui->listWidget_2->addItem("Status: OFF");
    }




}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    W_Add_User add_user_inst;
    add_user_inst.setModal(true);
    add_user_inst.exec();


    // Refresh list BEG
    ui->listWidget->clear();

    Users->load_users();
    std::string tmp;

    for(int i=0;i < Users->number_of_users;i++){
        tmp = Users->user[i].user_name.c_str();
        tmp += "  ||  ";
        tmp +=  Users->user[i].ip.c_str();
        tmp += "  ||  ";
        tmp +=  Users->user[i].port.c_str();


        ui->listWidget->addItem(tmp.c_str());
    }

    ui->listWidget->update();

    // Refresh list END
}

void MainWindow::on_tableView_activated(const QModelIndex &index)
{

}

void MainWindow::on_pushButton_5_clicked() //send file
{

    if(this->ui->listWidget->selectedItems().size() == 0){
        QMessageBox::critical(this,"Error!","Error! No destination selected!");
        return;

    }

    //esle wybierz plik
    else{


        #ifdef __unix__

        std::string starting_loc = "~/Desktop"

        #elif defined(_WIN32) || defined(WIN32)

        std::string starting_loc = "C:/Users/<USER>/Desktop";
        #endif


        QString file_path="";
        QFileDialog explorer;
        file_path = explorer.getOpenFileName(this,"Select a file",starting_loc.c_str());
        if(file_path.isNull()){
            QMessageBox::critical(this,"Error!","Error! No files selected!");
            return;
        }
        std::string file_name = file_path.toStdString();



        //Set sending values BEG

        std::string username = get_user_from_list(ui->listWidget->currentItem()->text().toStdString());

        int user_id = Users->get_number(username);

        std::cout<<"2) ip: "<<Users->user[user_id].ip.c_str()<<" port id: "<<Users->user[user_id].port.c_str()<<std::endl;

        //Set sending values END
        std::string p_argument;


        //FIND sending mode BEG

        std::string send_mode;

        FILE* fp = fopen(file_name.c_str(),"w");
                if (fp){                      // if file_name == FILE
                    send_mode="file";
                    p_argument = "python C:\\Users\\kanton\\AppData\\Roaming\\KantonLPM\\File_Transfer\\bin\\Client.py -file \"";
                    p_argument += file_name;
                    p_argument+="\" ";
                    p_argument+=Users->user[user_id].ip.c_str();
                    p_argument+=" ";
                    p_argument+=Users->user[user_id].port.c_str();


                    std::cout<<p_argument<<std::endl;
                    system(p_argument.c_str());
                }
                else{                          //if file_name == FOLDER
                    send_mode="folder";
                    p_argument = "python C:\\Users\\kanton\\AppData\\Roaming\\KantonLPM\\File_Transfer\\bin\\Client.py ";
                    p_argument += send_mode;
                    p_argument += " \"";
                    p_argument += file_name;
                    p_argument+="\" ";
                    p_argument+=Users->user[user_id].ip.c_str();
                    p_argument+=" ";
                    p_argument+=Users->user[user_id].port.c_str();

                    std::cout<<p_argument<<std::endl;
                    system(p_argument.c_str());



                    std::string list_of_folders[100];
                    int count_files = LPM_folder_list(file_name,list_of_folders);




                }


        //FIND sending mode END



    }
}

void MainWindow::on_pushButton_2_clicked() //remove user
{
    if(this->ui->listWidget->selectedItems().size() == 0){
        QMessageBox::critical(this,"Error!","Error! No user selected!");
        return;
    }

    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Remove user?", "Are you sure you want to remove that user?", QMessageBox::Yes|QMessageBox::No);
    if (reply == QMessageBox::No) {
        QMessageBox::information(this,"Aborted","Operation aborted!");
        return;
    }

    std::string raw_string = ui->listWidget->currentItem()->text().toStdString();
    std::string user_to_remove="";

    user_to_remove = get_user_from_list(raw_string);

    std::string path_to_remove = path_users;
    path_to_remove += "\\";
    path_to_remove += user_to_remove;
    path_to_remove+=".cfg";

    std::cout<<"user to remove "<<user_to_remove<<std::endl;


    if( remove( path_to_remove.c_str() ) != 0 ){
        perror("");
        QMessageBox::critical(this,"Error","Error deleting user!");
    }
    else
      QMessageBox::information(this,"Succes","User Deleted!");
      Users->load_users();
      qDeleteAll(ui->listWidget->selectedItems());
      ui->listWidget->update();
}

void MainWindow::on_pushButton_6_clicked() //send message
{

    if(this->ui->listWidget->selectedItems().size() == 0){
        QMessageBox::critical(this,"Error!","Error! No destination selected!");
        return;

    }


    Get_String get_string;
    get_string.setModal(true);
    get_string.exec();

    if(get_message_value == ""){
        QMessageBox::information(this,"Aborted","Operation aborted!");
    }


    std::string username = get_user_from_list(ui->listWidget->currentItem()->text().toStdString());
    int user_id = Users->get_number(username);

    std::string p_argument = "python C:\\Users\\kanton\\AppData\\Roaming\\KantonLPM\\File_Transfer\\bin\\Client.py -message \"";
    p_argument += get_message_value;
    p_argument+="\" ";
    p_argument+=Users->user[user_id].ip.c_str();
    p_argument+=" ";
    p_argument+=Users->user[user_id].port.c_str();


    std::cout<<p_argument<<std::endl;
    system(p_argument.c_str());

    get_message_value = "";
    QMessageBox::information(this,"Succes","Message sent!");


}

void MainWindow::on_pushButton_4_clicked() //settings
{


    Edit_Config edit_config;
    edit_config.setModal(true);
    edit_config.exec();



}

void MainWindow::on_pushButton_7_clicked() //refresh list
{

    // Refresh list BEG
    ui->listWidget->clear();

    Users->load_users();
    std::string tmp;

    for(int i=0;i < Users->number_of_users;i++){
        tmp = Users->user[i].user_name.c_str();
        tmp += "  ||  ";
        tmp +=  Users->user[i].ip.c_str();
        tmp += "  ||  ";
        tmp +=  Users->user[i].port.c_str();


        ui->listWidget->addItem(tmp.c_str());
    }

    ui->listWidget->update();

    // Refresh list END

}
