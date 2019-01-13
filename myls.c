/*
** EPITECH PROJECT, 2019
** ls
** File description:
** a
*/

#include "my.h"

int myls(char *str, char *f_word)
{
    if (str[0] == '-') {
        for (int i = 1; str[i] != '\0'; i++) {
            switch (str[i]) {
                case 'l':
                    my_l( f_word);
                    break;
                case 'd':
                    my_d(str, f_word);
                    break;
                case 'r':
                    my_r(str, f_word);
                    break;
                case 't':
                    my_tt(str);
                    break;
                default:
                    exit (84);
            }
        }
    }
}

void ls(int ac, char *av) {
    DIR *dir;
    struct dirent *dp;
    char * file_name;
    struct stat st;
    stat(av, &st);

    if (S_ISDIR(st.st_mode)){
        dir = opendir(av);
        if (opendir(av) == NULL)
            exit(84);
    } else
        dir = opendir(".");
    if (ac == 1 || S_ISDIR(st.st_mode)) {
        term_disp( dp, file_name, dir);
    } else {
        my_putstr(av);
        my_putstr("\n");
    }
    closedir(dir);
}

int term_disp(struct dirent *dp, char * file_name, DIR *dir)
{
    while ((dp = readdir(dir)) != NULL) {
        file_name = dp->d_name;
        if (file_name[0] != '.') {
            my_putstr(file_name);
            my_putstr("\n");
        }
    }
}

int my_l(char *f_word)
{
    struct stat st;
    DIR *dir;
    struct dirent *dp;
    char * file_name;

    stat(f_word, &st);
    if (S_ISDIR(st.st_mode))
        dir = opendir(f_word);
    else
        dir = opendir(".");
    if (f_word[0] != '-' && S_ISREG(st.st_mode)) {
        displayl(st, f_word);
    } else {
        displayf(file_name, f_word, dir, st);
    }
        closedir(dir);
}

int displayf(char *file_name, char *f_word, DIR *dir, struct stat st)
{
    struct dirent *dp;

    my_putstr("total ");
    my_put_nbr(blocks(file_name, f_word, dir));
    my_putstr("\n");
    while ((dp = readdir(dir)) != NULL) {
        file_name = dp->d_name;
        if (file_name[0] != '.')
            displaylt(file_name, f_word);
    }
}
