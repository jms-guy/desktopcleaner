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

int main() 
{
    const char *desktop_path = "/mnt/c/Users/Guy/Desktop";  //Desktop path
    const char *dirs[] = {"Images", "Documents", "Media", "Programs", "Others"}; //Directories to redirect files to
    int num_dirs = sizeof(dirs) / sizeof(dirs[0]);  //Number of directories in array

    //Create directories
    create_directories(desktop_path, dirs, num_dirs);
    //Process files in desktop directory
    process_files(desktop_path, dirs);

    return 0;
}

void process_files(const char *base_path, const char*dirs[]) {
    DIR *dir;
    struct dirent *file;
    dir = opendir(base_path); //Open desktop directory

    if (dir == NULL) {
        printf("Could not open directory: %s\n", base_path);
        return;
    }

    while ( (file=readdir(dir))) {
        if (strcmp(file->d_name, ".") == 0 || strcmp(file->d_name, "..") == 0) {    //Skip "." and ".." files
            continue;
        }
        char *filename = file->d_name;  //Get file name
        char *filepath = malloc(strlen(base_path) + strlen(filename) + 2);
        sprintf(filepath, "%s/%s", base_path, filename);    //Create full path to file

        char *file_ext = get_extension(filename);   //Get extension of current file
        if (file_ext == NULL) {
            continue;
        }

        FileType ext_type = get_extension_type(file_ext);   //Get extension type of current file
        char *dest_path = decide_dest(base_path, ext_type);

        if (dest_path == NULL) {
            printf("Skipping file due to memory error\n");
            continue;
        }

        free(dest_path);
        free(filepath);
    }

    closedir(dir);
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



