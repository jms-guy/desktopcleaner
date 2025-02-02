#ifndef FILE_UTILS_H
#define FILE_UTILS_H

#include <stdio.h>
#include <string.h>

// Filetype enum
typedef enum
{
    TYPE_DOCUMENTS,
    TYPE_IMAGES,
    TYPE_MEDIA,
    TYPE_OTHERS,
    TYPE_PROGRAMS,
} FileType;


FileType get_extension_type(const char *ext);
char *get_extension(const char *filename);
char *decide_dest(const char *base_path, FileType ext_type);
void move_file(const char *filepath, const char *dest_path);

#endif