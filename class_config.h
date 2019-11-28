#ifndef CLASS_CONFIG_H
#define CLASS_CONFIG_H

#include "utility.h"


class class_config_client{



};


class class_config_server{


public:

    std::string ip = "not_found";
    std::string port = "not_found";
    std::string path_config_server = "";

    class_config_server(){
        initialize_values();
        path_config_server = path_config;
        path_config_server += "\\Server.cfg";
        load_config();
    }


    inline bool load_config(){

        if(!LPM_file_exist(path_config_server)){
            std::cout<<"No Server config file found!"<<std::endl;
            return false;
        }

        FILE *fp;
        if(!(fp = fopen(path_config_server.c_str(),"r"))){
            perror("");
            return false;
        }
        std::string tmp_useless;

        fscanf(fp,"%s %s\n",tmp_useless.c_str(),ip.c_str());
        fscanf(fp,"%s %s\n",tmp_useless.c_str(),port.c_str());
        std::cout<<"Loading ip and port: "<<ip.c_str()<<" "<<port.c_str()<<std::endl;
        fclose(fp);

    }

    inline bool set_config(std::string input_ip,std::string input_port){

        FILE *fp = fopen(path_config_server.c_str(),"w");
        fprintf(fp,"Server_IP: %s\n",input_ip.c_str());
        fprintf(fp,"Server_Port: %s\n",input_port.c_str());
        fclose(fp);

        if(!LPM_file_exist(path_config_server)){
            std::cout<<"Error saving config! "<<std::endl;
            return false;
        }

        ip = input_ip;
        port = input_port;

        return true;

    }

    inline bool check_config(){
        load_config();
        if (ip == "not_found" || port == "not_found")return false;
        return true;
    }


};

inline class_config_server *config_server = new class_config_server;

#endif // CLASS_CONFIG_H
