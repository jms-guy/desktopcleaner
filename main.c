#include <stdio.h>  //Standard input/output
#include <dirent.h> //Directory operations
#include <sys/stat.h> //File info/stats
#include <sys/types.h> //mkdir
#include <string.h> //String handling
#include <stdlib.h> //Memory allocation
#include <errno.h>  //Error handling
#include "file_utils.h" //File utilities

void create_directories(const char *base_path, const char *dirs[], int num_dirs);
void process_files(const char *desktop_path, const char *dirs[]);
char *get_extension(const char *filename);
//void move_file(const char *source, const char *dest);

int main() 
{
    const char *desktop_path = "/mnt/c/Users/Guy/Desktop";  //Desktop path
    const char *dirs[] = {"Images", "Documents", "Media", "Programs", "Others"}; //Directories to redirect files to
    int num_dirs = sizeof(dirs) / sizeof(dirs[0]);  //Number of directories in array

    //Create directories
    create_directories(desktop_path, dirs, num_dirs);
    //Process files in desktop directory
    //process_files(desktop_path, dirs);

    return 0;
}

void process_files(const char *base_path, const char*dirs[]) {

}

void create_directories(const char *base_path, const char *dirs[], int num_dirs) {
    struct stat st = {0};

    //Loop for new directories
    for (int i = 0; i < num_dirs; i++){

        int check;  //Variable for mkdir success check
        const char *dir = dirs[i];   //Current directory in loop
        char *full_path = malloc(strlen(base_path) + strlen(dir) + 2);  //Full path name memory allocation
        sprintf(full_path, "%s/%s", base_path, dir);    //Full path creation for new directory

        if (stat(full_path, &st) == -1) {   //If directory doesn't exist yet
            check = mkdir(full_path, 0755); //mkdir creates the folder

            if (check == 0) {   //Checks mkdir success
                printf("Created folder: %s\n", dir);
            } else {
                printf("Unable to create folder %s: %s\n", dir, strerror(errno));
                free(full_path);
                exit(1);
            }
        }
        free(full_path);
    }
}



