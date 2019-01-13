/*
** EPITECH PROJECT, 2019
** ls
** File description:
** a
*/

#include "my.h"

int my_r(char *str, char *f_word){
    DIR *dir;
    struct dirent *dp;
    char * file_name;
    int count;
    int nb;

    dir = opendir(".");

    while ((dp = readdir(dir)) != NULL) {
        file_name = dp->d_name;
        if (file_name[0] != '.') {
            my_putstr(file_name);
            my_putstr("\n");
            count = count + my_strlen(file_name);
            nb = nb + 1;
        }
    }
    closedir(dir);
}

int my_tt(char *str)
{
    DIR *dir;
    struct dirent *dp;
    char * file_name;

    dir = opendir(".");

    tri(dp, file_name, dir);
    closedir(dir);
}

int tri(struct dirent *dp, char * file_name, DIR *dir) {
    struct stat st;
    int hr = 0;
    char * str;

    while ((dp = readdir(dir)) != NULL) {
        file_name = dp->d_name;
        stat(file_name, &st);
        hr = st.st_mtime;
        if (file_name[0] != '.') {
            my_putstr(file_name);
            my_putstr("\n");
        }
    }
}

int blocks(char *file_name, char * f_word, DIR *dir)
{
    int blocks = 0;
    struct dirent *dp2;
    struct stat st;

    stat(f_word, &st);
    if (S_ISDIR(st.st_mode))
        dir = opendir(f_word);
    else
        dir = opendir(".");
    while ((dp2 = readdir(dir)) != NULL) {
            file_name = dp2->d_name;
            if (f_word[0] != '-')
                stat(way(file_name, f_word), &st);
            else
                stat(file_name, &st);
            if (file_name[0] != '.')
                blocks = blocks + st.st_blocks;
    }
    closedir(dir);
    return (blocks / 2);
}

int my_d(char *str, char *f_word) {
    if (f_word[0] == '-') {
        my_putstr(".");
        my_putstr("\n");
    }
    else {
        my_putstr(f_word);
        my_putstr("\n");
    }
}
