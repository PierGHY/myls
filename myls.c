/*
** EPITECH PROJECT, 2019
** ls
** File description:
** a
*/

#include "my.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_put_nbr(int nb)
{
    int pow = 1;
    int nbcpy = nb;
    int lon = 0;

    while( nbcpy > 9) {
        pow = pow * 10;
        nbcpy = nbcpy / 10;
        lon = lon + 1;
        }
    while (lon > 0) {
        my_putchar((nb/pow) + 48);
        nb = nb % pow;
        pow = pow / 10;
        lon = lon - 1;
    }
    my_putchar(nb + '0');
}

void my_putstr(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        my_putchar(str[i]);
        i = i + 1;
    }
}

void my_putstrdate(char const *str)
{
    int i = 3;

    while (str[i + 9] != '\0') {
        my_putchar(str[i]);
        i = i + 1;
    }
}

int myls(char *str, char *f_word) 
{
    int i = 1;

    //printf("f_word => %s", f_word);
    if(str[0] == '-') {
        while (str[i] != '\0') { 
            switch(str[i]) {
                case 'R':
                    //my_bigr(str);
                    break;
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
                    return(84);
            }
            i = i + 1;
        }
    }
}

void ls(void) {
    DIR *dir;
    struct dirent *dp;
    char * file_name;

    dir = opendir(".");

    while ((dp=readdir(dir)) != NULL) {
        file_name = dp->d_name;
        if (file_name[0] != '.') {
            my_putstr(file_name);
            my_putstr("\n");
        }
    }
    closedir(dir);
}
/*1
int my_bigr()

*/

int my_l(char *str, char *f_word) {
    struct stat st;
    struct passwd *pw;
    struct group *gp;
    DIR *dir;
    DIR *dir2;
    struct dirent *dp;
    struct dirent *dp2;
    char * file_name;
    char * file_name2;
    int blocks = 0;

    dir = opendir(".");
    dir2 = opendir(".");
    
    while ((dp2=readdir(dir2)) != NULL) {
            file_name2 = dp2->d_name;
            stat(file_name2, &st);  
            if (file_name2[0] != '.')
                blocks = blocks + st.st_blocks;
    }
    blocks = blocks / 2;
    closedir(dir2);
    if (f_word[0] != '-') {
        displayl(st, pw, gp, f_word);
    }
    else {
        my_putstr("total ");
        my_put_nbr(blocks);
        my_putstr("\n");
        while ((dp=readdir(dir)) != NULL) {
            file_name = dp->d_name;
            if (file_name[0] != '.')
                displayl(st, pw, gp, file_name);
        }
        closedir(dir);
    }

}

int my_d(char *str, char *f_word) {
    if (f_word[0] == '-') {
        my_putstr(".");
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
    char * reverse;

    dir = opendir(".");

    while ((dp=readdir(dir)) != NULL) {
        file_name = dp->d_name;
        if (file_name[0] != '.') {
            my_putstr(file_name);
            my_putstr("\n");
        }
    }
    closedir(dir);
}

int displayl(struct stat st, struct passwd *pw, struct group *gp, char * f_word ) {
    int i = 0;
    int a = 0;
    char * hours;
    stat(f_word, &st);

    (S_ISDIR(st.st_mode)) ? my_putstr("d") : my_putstr("-");
    (st.st_mode & S_IRUSR) ? my_putstr("r") : my_putstr("-");
    (st.st_mode & S_IWUSR) ? my_putstr("w") : my_putstr("-");
    (st.st_mode & S_IXUSR) ? my_putstr("x") : my_putstr("-");
    (st.st_mode & S_IRGRP) ? my_putstr("r") : my_putstr("-");
    (st.st_mode & S_IWGRP) ? my_putstr("w") : my_putstr("-");
    (st.st_mode & S_IXGRP) ? my_putstr("x") : my_putstr("-");
    (st.st_mode & S_IROTH) ? my_putstr("r") : my_putstr("-");
    (st.st_mode & S_IWOTH) ? my_putstr("w") : my_putstr("-");
    (st.st_mode & S_IXOTH) ? my_putstr("x. ") : my_putstr("-. ");

    i = st.st_nlink;
    my_put_nbr(i);
    my_putstr(" ");

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
    
    my_putstr(f_word);
    my_putstr("\n");
}

int my_tt(char *str) {
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
    
    if(ac == 1) {
        ls();
    }
    else {
        while (i != ac) {
            myls(av[i], av[ac - 1]);
            i = i + 1;
        }
    }
    return(0);
}