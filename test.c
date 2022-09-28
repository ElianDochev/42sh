#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

extern char **environ;

int main(int ac, char **av)
{
    int file = open("test", O_RDWR | O_CREAT | O_TRUNC, 0644);
    int file_2 = open("test_2", O_RDWR | O_CREAT| O_TRUNC, 0644);
    char **env = environ;
    for (int i = 0; env[i]; ++i)
        dprintf(file, "%s\n", env[i]);
    // printf("\n\n\n");
    if (setenv("TEST", "TET_VALUE", 1) == -1)
        printf("DOESNT work\n");
    for (int i = 0; env[i]; ++i)
        dprintf(file_2,"%s\n", env[i]);
    close(file);
    close(file_2);
    return 0;
}
