/*
** EPITECH PROJECT, 2018
** BSQ
** File description:
** a
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

void load_2d_arr_from_file()
{
    int fd = open(filepath, O_RDONLY);
    if (fd == -1)
        return (84);
    struct stat size;
    stat(filepath, &size);
    char *buffer;
    buffer = malloc(sizeof(char) * (size.st_size));
    read(fd, buffer, size.st_size);

    char **str = malloc(sizeof(char *) * (nb_rows));
    int i = 0;

    while (i <= nb_rows) {
        str[i] = malloc(sizeof(char) * (nb_cols));
        i = i + 1;
    }
    disp(buffer, str, nb_rows, nb_cols);
}

void disp(char * buffer, char ** str, int nb_rows, int nb_cols)
{
    int i = 0;
    int j = 0;
    int k = 0;

    while (i < nb_rows) {
        while (j <= nb_cols) {
            str[i][j] = buffer[k];
            j = j + 1;
            k = k + 1;
        }
        j = 0;
        i = i + 1;
    }
    for (int h = 0; h < nb_rows; h++) {
        for (int z = 0; z < nb_cols; z++)
            my_putchar(str[h][z]);
    }
    return (str);
}

int main(int ac, char ** av)
{
    load_2d_arr_from_file(av[1], 200, 200);
    return (0);
}