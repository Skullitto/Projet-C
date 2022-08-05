#define _SVID_SOURCE
/* Afficher le contenu du répertoire en ordre inverse */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <dirent.h>
int
main(void)
{
    struct dirent **namelist;
    int n;

    n = scandir(".", &namelist, 0, alphasort);
    if (n < 0)
        perror("scandir");
    else {
        while (n--) {
            printf("%s\n", namelist[n]->d_name);
            free (namelist [n]);
        }
        free (namelist);
    }
}
