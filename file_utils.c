#include "file_utils.h"


char *get_extension(const char *filename) {

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
    return TYPE_OTHER;
}