/*
** EPITECH PROJECT, 2019
** my
** File description:
** h
*/

#ifndef MY_H_

#define MY_H_

#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/sysmacros.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <pwd.h>
#include <grp.h>

void my_putstr(char const *str);
int displayf(char * file_name, char * f_word, DIR *dir, struct stat st);
int my_put_nbr(int nbr);
int blocks(char *file_name, char * f_word, DIR *dir);
int displaylt(char *file_name, char * f_word);
void my_putstrdate(char const *str);
int my_strlen(char const *str);
void ls(int ac, char * av);
int myls(char * str, char * f_word);
char *way(char * file_name, char * f_word);
int my_l(char *f_word);
int my_d(char *str, char *f_word);
int my_r(char *str, char *f_word);
int my_tt(char *str);
int displayl(struct stat st, char *f_word);
int tri(struct dirent *dp, char *file_name, DIR *dir);
int right(struct stat st, int i, struct passwd *pw, struct group *gp);
int term_disp(struct dirent *dp, char * file_name, DIR * dir);
#endif