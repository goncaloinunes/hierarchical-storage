#include "auxiliary.h"


Directory initialize_directory_name(Directory directory, char *name) {
    directory.name = malloc((strlen(name) + 1) * sizeof(char));
    check_memory(directory.name);
    strcpy(directory.name, name);

    return directory;
}


Directory initialize_directory_path(Directory directory, char *path) {
    directory.path = malloc((strlen(path) + 1) * sizeof(char));
    check_memory(directory.path);
    strcpy(directory.path, path);

    return directory;
}


Directory initialize_directory_value(Directory directory, char *value) {
    directory.value = malloc((strlen(value) + 1) * sizeof(char));
    check_memory(directory.value);
    strcpy(directory.value, value);

    return directory;
}


Directory initialize_directory(Directory directory, char *name, char *path, char *value) {
    directory = initialize_directory_name(directory, name);
    directory = initialize_directory_path(directory, path);
    directory = initialize_directory_value(directory, value);

    return directory;
}


Directory change_directory_value(Directory directory, char *value) {
    directory.value = safe_realloc(directory.value, (strlen(value) + 1) * sizeof(char));
    strcpy(directory.value, value);

    return directory;
}


void free_directory(Directory directory) {
    free(directory.name);
    free(directory.path);
    free(directory.value);
}