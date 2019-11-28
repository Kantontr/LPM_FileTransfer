#ifndef INSTALL_H
#define INSTALL_H

#include "utility.h"

bool install(){



#ifdef __unix__


#elif defined(_WIN32) || defined(WIN32)




#endif


    std::cout<<"Starting installer!"<<std::endl;
    initialize_values();
    if (!LPM_folder_exist(path_main_folder)) {

        if (LPM_folder_exist(path_appdata_instal)) {
            LPM_folder_create(path_appdata_instal);
            std::cout << "Folder KantonLPM zostal utworzony w " << path_appdata_instal << std::endl;
        }

        LPM_folder_create(path_main_folder);
        std::cout << "Folder File_Transfer zostal utworzony w " << path_main_folder << std::endl;

        LPM_folder_create(path_bin);
        std::cout << "Folder bin zostal utworzony w " << path_bin << std::endl;

        LPM_folder_create(path_users);
        std::cout << "Folder users zostal utworzony w " << path_users << std::endl;

        LPM_folder_create(path_config);
        std::cout << "Folder config zostal utworzony w " << path_config << std::endl;

    }
    return true;



}


#endif // INSTALL_H
