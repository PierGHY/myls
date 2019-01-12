/*
** EPITECH PROJECT, 2019
** a
** File description:
** a
*/

#include "my.h"

int displayl(struct stat st,struct passwd *pw, struct group *gp, char * file_name ) 
{
    int i = 0;
    int a = 0;
    char * hours;
    right(st, i);
    if ((pw = getpwuid(st.st_uid)) != NULL)
        my_putstr(pw->pw_name);
    if ((gp = getgrgid(st.st_gid )) != NULL) {
        my_putstr(" ");
        my_putstr(gp->gr_name);
    }
    a = st.st_size;
    my_putstr(" ");
    my_put_nbr(a);
    hours = ctime(&st.st_mtime);
    my_putstrdate(hours);
    my_putstr(" ");
    my_putstr(file_name);
    my_putstr("\n");
}

char *way(char *file_name, char *f_word) 
{
    int i = 0;
    int j = 0;
    char * test = malloc(sizeof(char) * (my_strlen(file_name) + my_strlen(f_word) + 2));

    while (f_word[i] != '\0') {
        test[i] = f_word[i];
	    i = i + 1;
    }
    if (test[i] != '/') {
        test[i] = '/'; 
        i = i + 1;
    }
    while (file_name[j] != '\0') {
	    test[i] = file_name[j];
	    j = j + 1;
	    i = i + 1;
    }
    test[i] = '\0';
    return(test);
}

int displaylt(struct passwd *pw, struct group *gp, char *file_name, char *f_word ) 
{
    struct stat st;
    int i = 0;
    int a = 0;
    char * hours;
    char * ways = way(file_name ,f_word);

    if(f_word[0] != '-') {
        stat(ways, &st);
    }
    else
        stat(file_name, &st);
    right(st, i);
    if ((pw = getpwuid(st.st_uid)) != NULL)
        my_putstr(pw->pw_name);
    if ((gp = getgrgid(st.st_gid )) != NULL) {
        my_putstr(" ");
        my_putstr(gp->gr_name);
    }
    a = st.st_size;
    my_putstr(" ");
    my_put_nbr(a);
    hours = ctime(&st.st_mtime);
    my_putstrdate(hours);
    my_putstr(" ");
    my_putstr(file_name);
    my_putstr("\n");
}

int right(struct stat st, int i)
{
    (S_ISDIR(st.st_mode)) ? my_putstr(" d") : my_putstr(" -");
    (st.st_mode & S_IRUSR) ? my_putstr("r") : my_putstr("-");
    (st.st_mode & S_IWUSR) ? my_putstr("w") : my_putstr("-");
    (st.st_mode & S_IXUSR) ? my_putstr("x") : my_putstr("-");
    (st.st_mode & S_IRGRP) ? my_putstr("r") : my_putstr("-");
    (st.st_mode & S_IWGRP) ? my_putstr("w") : my_putstr("-");
    (st.st_mode & S_IXGRP) ? my_putstr("x") : my_putstr("-");
    (st.st_mode & S_IROTH) ? my_putstr("r") : my_putstr("-");
    (st.st_mode & S_IWOTH) ? my_putstr("w") : my_putstr("-");
    (st.st_mode & S_IXOTH) ? my_putstr("x ") : my_putstr("- ");
    i = st.st_nlink;
    my_put_nbr(i);
    my_putstr(" ");
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

    while ((dp=readdir(dir)) != NULL) {
        file_name = dp->d_name;
        
        stat(file_name, &st);
        hr = st.st_mtime;
        if (file_name[0] != '.') {
            my_putstr(file_name);
            my_putstr("\n");
        }
    }
}

int main(int ac, char **av)
{
    int i = 0;
    
    if(ac == 1 || av[1][0] != '-') {
        ls(ac, av[ac - 1]);
    }
    else {
        while (i != ac) {
            myls(av[i], av[ac - 1]);
            i = i + 1;
        }
    }
    return(0);
}