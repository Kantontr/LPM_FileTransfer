#ifndef UTILITY_H
#define UTILITY_H



#ifdef __unix__



#elif defined(_WIN32) || defined(WIN32)

    #include <windef.h>
    #include <windows.h>
    #include <Windows.h>
    #include <ShellAPI.h>
    #include <ShlObj.h>

#endif

#include <iostream>
#include <afxres.h>
#include <stdio.h>
#include <string>
#include <direct.h>
#include <dirent.h>
#include <fstream>
#include <sstream>
#include <string>
#include<cmath>
#include <QMessageBox>
#include <sys/types.h>
#include <sys/stat.h>
#include <iomanip>
#include <ctime>
#include <stdexcept>
#include "lpm_wl_lib.h"


inline std::string path_appdata_instal;
inline std::string path_main_folder;
inline std::string path_bin;
inline std::string path_users;
inline std::string path_config;



inline bool initialize_values(){




#ifdef __unix__

    const char *homedir;

    if ((homedir = getenv("HOME")) == NULL) {
        path_appdata_instal = getpwuid(getuid())->pw_dir;
    }


#elif defined(_WIN32) || defined(WIN32)

     path_appdata_instal = getenv("AppData");

#endif




    //perror("Initializing values");

    path_appdata_instal += "\\KantonLPM";
    path_main_folder = path_appdata_instal;
    path_main_folder += "\\File_Transfer";
    path_bin = path_main_folder;
    path_bin += "\\bin";
    path_users = path_main_folder;
    path_users += "\\users";
    path_config = path_main_folder;
    path_config += "\\config";

    std::cout<<"Values initialized!"<<std::endl;
}

inline bool initialize_values_2(){
}




inline std::string get_user_from_list(std::string input){
    std::string username="";
    int i=0;
    for (i; input[i] != ' ' && input[i+1] != ' ' && input[2] != '|' && input[i+3] != '|';i++){
        username+=input[i];
    }
    username+=input[i];
    return  username;

}

inline std::string get_ip_from_list(std::string input){
    int i=1;
    std::string ip="";

    for (i;input[i] != ' ' && input[i+1] != ' ' && input[i+2] != '|' && input[i+3] != '|';i++);
    i+=7;

    for (i;input[i] != ' ';i++){
        ip+=input[i];
    }

    std::cout<<std::endl;
    return ip;
}

inline std::string get_port_from_list(std::string input){
    int i=input.length()-1;
    while (input[i] != ' ' && input[i-1] != ' ' && input[i-2] != '|' && input[i-3] != '||'){
        i--;
    }


    std::string port="";
    for (i;i < input.length() ;i++){
        port+=input[i];
    }
    return port;
}



#endif // UTILITY_H
