#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char **argv)
{
    if(argc != 2)
    {
        printf("Argumente invalide\n");
        exit(1);
    }
    int input;
    if((input = open(argv[1], O_RDONLY)) < 0)
    {
        printf("Eroare la deschiderea fisierului\n");
        exit(2);
    }
    char name[100], size[12], uid[8], gid[8];

    if(read(input, name, 100) < 0)
    {
        printf("Eroare la citirea din fisier\n");
        exit(2);
    }

    lseek(input, 108, SEEK_SET);

    if(read(input, uid, 8) < 0)
    {
        printf("Eroare la citirea din fisier\n");
        exit(2);
    }

    if(read(input, gid, 8) < 0)
    {
        printf("Eroare la citirea din fisier\n");
        exit(2);
    }

    if(read(input, size, 12) < 0)
    {
        printf("Eroare la citirea din fisier\n");
        exit(2);
    }

    printf("File name : %s\n", name);
    printf("File size : %d\n", atoi(size));
    printf("Owner id : %d\n", atoi(uid));
    printf("Group id : %d\n", atoi(gid));
    close(input);
    return 0;
}