#ifndef LPM_WL_LIB_H
#define LPM_WL_LIB_H

#endif // LPM_WL_LIB_H

#include "stdio.h"
#include <iostream>
#include <dirent.h>



#ifdef __unix__

#include <sys/stat.h>

#elif defined(_WIN32) || defined(WIN32)

#include <windows.h>

#endif


inline  int LPM_folder_list(std::string folder_list_path,std::string list_of_folders[]); //get folder path and array to store listed folders returns number of files
inline bool LPM_file_exist(std::string file_path); //get file path return True if found or prints error and false if not found
inline bool LPM_folder_exist(std::string file_path);//get folder path return True if found or prints error and false if not found
inline bool LPM_folder_create(std::string folder_path); //create folder return true if created or false and prints error if not created;




inline bool LPM_file_exist(std::string file_path){


#ifdef __unix__

    inline bool exists_test1 (const std::string& name) {
        if (FILE *file = fopen(name.c_str(), "r")) {
            fclose(file);
            perror("Looking for file: ");
            return true;
        } else {
            return false;
        }
    }

#elif defined(_WIN32) || defined(WIN32)

    if ((GetFileAttributesA(file_path.c_str())) == INVALID_FILE_ATTRIBUTES){
        perror("Looking for file: ");
        return false;
    }

    else return true;

#endif


}


inline bool LPM_folder_exist(std::string file_path){


#ifdef __unix__

    struct stat st;
    if(stat("/tmp",&st) == 0){
        return true;
        else{
            perror("Looking for folder: ");
            return false;
        }
    }



#elif defined(_WIN32) || defined(WIN32)

    if ((GetFileAttributesA(file_path.c_str())) == INVALID_FILE_ATTRIBUTES){
        perror("Looking for file: ");
        return false;
    }

    else return true;

#endif


}


inline bool LPM_folder_create(std::string folder_path){

#ifdef __unix__

    if(!LPM_folder_exist(folder_path)){
        const int dir_err = mkdir("foo", S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
        if (-1 == dir_err)
        {
            printf("Error creating directory!n");
            return false;
        }
        return true;
    }

#elif defined(_WIN32) || defined(WIN32)

    if(!LPM_folder_exist(folder_path)){
        if(!CreateDirectoryA(folder_path.c_str(), 0)){
            perror("Creating folder: ");
        }
    }
    if(!LPM_folder_exist(folder_path)){
        return false;
    }
    return true;

#endif

}




inline  int LPM_folder_list(std::string folder_list_path,std::string list_of_folders[]) {

    int counter = 0;
    DIR *dir;
    struct dirent *ent;
    std::string tmp;
    std::string tmp_2;
    if ((dir = opendir(folder_list_path.c_str())) != NULL) {


        for(int i=0;(ent = readdir(dir)) != NULL;i++){
            if(i>=2){
                list_of_folders[counter] = ent->d_name;
                counter++;
            }
        }

        closedir(dir);
        return counter;

    } else {
        perror("Listing folders: ");
        return EXIT_FAILURE;
    }
}
