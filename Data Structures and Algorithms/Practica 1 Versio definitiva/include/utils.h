#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_WORD_LENGTH 50
#define MAX_DEFINITION_LENGTH 100
#define MAX_LENGTH MAX_WORD_LENGTH+MAX_DEFINITION_LENGTH+5
#define MAX_PATH_LENGHT 100
#define MAX_CATEGORY_LENGTH 1

/*
 * Convert characters from upper case to lower case.
 * Modify the given string mapping all characters in [A-Z] to [a-z].
*/
void str_to_lowercase(char* s);

/*
 *  Function strsep is not standard in Windows, we implement our own
*/
char* mystrsep(char** str_ptr, char* delim);

/*
 * Read one line from console
*/
bool scan_line(char* message, char* format, void* buffer);

/*
 * Check file exists
 */
bool exists(char *filepath);

/*
 * Join two paths together and store it in filepath
 */
void join_path(char *filepath, char *path1, char *path2);

#endif /* UTILS_H */

