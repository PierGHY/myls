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

int my_l(char *str, char *f_word);
int my_d(char *str, char *f_word);
int my_r(char *str, char *f_word);
int my_tt(char *str);
int displayl(struct stat st, struct passwd *pw, struct group *gp, char *f_word);
int tri(struct dirent *dp, char *file_name, DIR *dir);

#endif
