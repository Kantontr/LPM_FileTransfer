#include "utility.h"

#ifndef CLASS_USER_H
#define CLASS_USER_H



class Class_Users{

    public:

    int number_of_users=0;

    Class_Users(){
        load_users();
    }

    struct user_struct{
        std::string user_name = "";
        std::string ip = "";
        std::string port = "";
    };
    user_struct *user;

    inline bool add_user(std::string user_name,std::string ip,std::string port){

        std::string new_user = path_users;
        new_user+="\\";
        new_user+=user_name;
        new_user += ".cfg";


        FILE *fp_create_cfg;
        if ((fp_create_cfg = fopen(new_user.c_str(), "w")) != NULL) {
            fprintf(fp_create_cfg, "IP: %s\n", ip.c_str());
            fprintf(fp_create_cfg, "PORT: %s\n", port.c_str());
            fclose(fp_create_cfg);
        }
        else return false;
        printf("File created! \n");
        return true;
    }

    inline bool load_users(){

        initialize_values();
        if(!LPM_folder_exist(path_users)){
            return false;
        }
        std::cout<<"Starting Loading users!"<<std::endl;
        std::string list_of_folders[100];
        number_of_users = LPM_folder_list(path_users,list_of_folders);
        std::cout<<"Loading users - nb of users = "<<number_of_users<<std::endl;

        if(number_of_users>0){


            user = new user_struct[number_of_users];

            FILE *fp;
            std::string path_temp;

            for(int i=0;i<number_of_users;i++){

                path_temp = path_users;
                path_temp += "\\";
                path_temp += list_of_folders[i];

                std::string user_name_tmp = list_of_folders[i];

                //std::cout<<"User loaded: "<<user_name_tmp<<std::endl;

                user_name_tmp.erase(user_name_tmp.length()-4,4);
                user[i].user_name = user_name_tmp;

                if ((fp = fopen(path_temp.c_str(), "r")) != NULL){
                    fscanf(fp, "%s",user[i].ip.c_str());
                    fscanf(fp, "%s",user[i].ip.c_str());
                    fscanf(fp, "%s",user[i].port.c_str());
                    fscanf(fp, "%s",user[i].port.c_str());
                }
                fclose(fp);
            }
        }

        std::cout<<"All Users loaded!"<<std::endl;
        return true;
    }

    inline int get_number(std::string username){
        for (int i = 0; i<number_of_users;i++){
            if(user->user_name == username)return i;
        }
        return -1;
    }


};

inline Class_Users *Users = new Class_Users;



#endif // CLASS_USER_H
