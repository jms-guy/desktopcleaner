#include <stdio.h>     //Standard input/output
#include <dirent.h>    //Directory operations
#include <sys/stat.h>  //File info/stats
#include <sys/types.h> //mkdir
#include <string.h>    //String handling
#include <stdlib.h>    //Memory allocation
#include <errno.h>     //Error handling
#include "file_utils.h"

char *decide_dest(const char *base_path, FileType ext_type) {   //Deciding destination directory for file
    char *destination;
    char *dest_path;

    switch (ext_type) {
    case TYPE_DOCUMENTS:
        destination = "Documents";
        break;
    case TYPE_IMAGES:
        destination = "Images";
        break;
    case TYPE_MEDIA:
        destination = "Media";
        break;
    case TYPE_PROGRAMS:
        destination = "Programs";
        break;
    default:
        destination = "Others";
        break;
    }
    dest_path = malloc(strlen(base_path) + strlen(destination) + 2);

    if (dest_path == NULL) {
        fprintf(stderr, "Memory allocation failed: %s\n", strerror(errno));
        return NULL;
    }

    sprintf(dest_path, "%s/%s", base_path, destination);
    return dest_path;
}

char *get_extension(const char *filename) { //Get extension from file
    const char ch = '.';
    char *ext = strrchr(filename, ch);
    if (!ext) {
        return NULL;
    }
    return strdup(ext + 1);
}

FileType get_extension_type(const char *ext) {
    if(strcasecmp(ext, "txt") == 0)
        return TYPE_DOCUMENTS;
    if (strcasecmp(ext, "doc") == 0)
        return TYPE_DOCUMENTS;
    if (strcasecmp(ext, "pdf") == 0)
        return TYPE_DOCUMENTS;
    if (strcasecmp(ext, "wpd") == 0)
        return TYPE_DOCUMENTS;
    if (strcasecmp(ext, "jpeg") == 0)
        return TYPE_IMAGES;
    if (strcasecmp(ext, "png") == 0)
        return TYPE_IMAGES;
    if (strcasecmp(ext, "gif") == 0)
        return TYPE_IMAGES;
    if (strcasecmp(ext, "mp4") == 0)
        return TYPE_MEDIA;
    if (strcasecmp(ext, "mp3") == 0)
        return TYPE_MEDIA;
    if (strcasecmp(ext, "wav") == 0)
        return TYPE_MEDIA;
    if (strcasecmp(ext, "amv") == 0)
        return TYPE_MEDIA;
    if (strcasecmp(ext, "mpeg") == 0)
        return TYPE_MEDIA;
    if (strcasecmp(ext, "avi") == 0)
        return TYPE_MEDIA;
    if (strcasecmp(ext, "c") == 0)
        return TYPE_PROGRAMS;
    if (strcasecmp(ext, "py") == 0)
        return TYPE_PROGRAMS;
    if (strcasecmp(ext, "java") == 0)
        return TYPE_PROGRAMS;
    if (strcasecmp(ext, "js") == 0)
        return TYPE_PROGRAMS;
    if (strcasecmp(ext, "exe") == 0)
        return TYPE_PROGRAMS;
    return TYPE_OTHERS;
}