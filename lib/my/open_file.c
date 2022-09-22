/*
** EPITECH PROJECT, 2022
** open_file
** File description:
** gives the file contest as a string
*/

#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include "utilities.h"

char *open_file(char const *filepath)
{
    int fd = open(filepath, O_RDONLY);
    struct stat buffer;
    int check = stat(filepath, &buffer);
    char *res = malloc(buffer.st_size + 1);

    if (fd < 0 || check < 0) {
        error("Cant open file, check path\n");
        return NULL;
    }
    if (res == NULL) {
        error("malloc failed for res in open_file\n");
        return NULL;
    }
    check = read(fd, res, buffer.st_size);
    if (check == -1) {
        return NULL;
    }
    res[buffer.st_size] = '\0';
    close(fd);
    return res;
}

void print_help(char *path)
{
    char *buf = open_file(path);

    my_printf("%s", buf);
    free(buf);
}

void print_bad_args(int ac , char *binary_name, int req_args)
{
    my_printf("./%s: bad arguments:"
    "%d given but %d is required\nretry with -h\n", binary_name, ac, req_args);
}
