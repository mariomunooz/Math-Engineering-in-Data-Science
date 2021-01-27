#include "utils.h"

/**
 * TODO: OK Convert upper case to lower case
 * Modify the given string mapping all characters in [A-Z] to [a-z].
*/
void str_to_lowercase(char *s) {
    //For all the characters in the string, if they are upper case ads 32 to their ascii code which is for every upper case character
    //its lower case equivalent
    while (*s != '\0'){
        if (*s >= 65 && *s <= 90) *s += 32;
        s++;
    }

}

/**
 *  Function strsep is not standard in Windows, we implement our own
*/
char *mystrsep(char **str_ptr, char *delim) {
    if (*str_ptr == NULL) return NULL;
    char *start = *str_ptr;
    *str_ptr = strpbrk(start, delim);
    if (*str_ptr != NULL) {
        **str_ptr = '\0';
        *str_ptr = *str_ptr + 1;
    }
    return start;
}

/**
 * Read one line from console
*/
bool scan_line(char *message, char *format, void *buffer) {
    printf("%s", message);
    fflush(stdout);
    char line[1000]; // this should be a sufficiently long buffer
    char *res = fgets(line, sizeof(line), stdin);
    if (res == NULL) return false; // reading from stdin failed
    line[strcspn(line, "\n")] = '\0'; // remove '\n'
    if (format == NULL || strcmp(format, "%s") == 0) strcpy(buffer, line);
    else sscanf(line, format, buffer); // we asume here that format is a single specifier (e.g. only %d)
    return true;
}

/**
 * Check file exists
 */
bool exists(char *filepath) {
    FILE *file = fopen(filepath, "r");
    if (file != NULL) {
        fclose(file);
        return true;
    } else {
        return false;
    }
}

/**
 * Join two paths together and store it in filepath
 */
void join_path(char *filepath, char *path1, char *path2) {
    int len1 = strlen(path1);
    int len2 = strlen(path2);
    char path[MAX_PATH_LENGHT];
    int char_count = 0;
    for (int i = 0; i < len1; i++) {
        path[char_count] = path1[i];
        char_count++;
    }
    path[char_count] = '/';
    char_count++;
    for (int i = 0; i < len2; i++) {
        path[char_count] = path2[i];
        char_count++;
    }
    path[char_count] = '\0'; // marks end of string

    strcpy(filepath, path);
}
