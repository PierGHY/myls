/*
** EPITECH PROJECT, 2019
** ls
** File description:
** a
*/

#include "my.h"

int myls(char *str, char *f_word) 
{
    if(str[0] == '-') {
        for (int i = 1; str[i] != '\0'; i++) { 
            switch(str[i]) {
                case 'l':
                    my_l(str, f_word);
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
    }else
        dir = opendir(".");
    if (ac == 1 || S_ISDIR(st.st_mode)) {
        term_disp( dp, file_name, dir);
    }else {
        my_putstr(av);
        my_putstr("\n");
    }
    closedir(dir);
}

int term_disp(struct dirent *dp, char * file_name, DIR *dir)
{
    while ((dp=readdir(dir)) != NULL) {
        file_name = dp->d_name;
        if (file_name[0] != '.') {
            my_putstr(file_name);
            my_putstr("\n");
        }
    }
}
/*1
int my_bigr()

*/

int my_l(char *str, char *f_word) {
    struct stat st;
    struct stat st2;
    struct stat st3;
    DIR *dir;
    DIR *dir2;
    struct passwd *pw;
    struct group *gp;
    struct dirent *dp;
    struct dirent *dp2;
    char * file_name;
    char * file_name2;
    int blocks = 0;
    stat(f_word, &st);

    if(S_ISDIR(st.st_mode)) {
        dir = opendir(f_word);
        dir2 = opendir(f_word);
    }else {
        dir = opendir(".");
        dir2 = opendir(".");
    }
    
    while ((dp2=readdir(dir2)) != NULL) {
            file_name2 = dp2->d_name;
            if (f_word[0] != '-')
                stat(way(file_name2, f_word), &st2);
            else 
                stat(file_name2, &st2);
            if (file_name2[0] != '.')
                blocks = blocks + st2.st_blocks;
    }
    blocks = blocks / 2;
    closedir(dir2);
    if (f_word[0] != '-' && S_ISREG(st.st_mode)) {
        displayl(st, pw, gp, f_word);
    }
    else {
        my_putstr("total ");
        my_put_nbr(blocks);
        my_putstr("\n");
        while ((dp = readdir(dir)) != NULL) {
            file_name = dp->d_name;
            if (file_name[0] != '.')
                displaylt(pw, gp, file_name, f_word);
        }
        closedir(dir);
    }
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

int my_r(char *str, char *f_word){
    DIR *dir;
    struct dirent *dp;
    char * file_name;
    int count;
    int nb;

    dir = opendir(".");

    while ((dp=readdir(dir)) != NULL) {
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