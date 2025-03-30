#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <ctype.h>
#include <string.h>

int main(int argc, char **argv)
{
    if(argc != 4)
    {
        fprintf(stderr, "Argumente invalide\n");
        exit(1);
    }
    int input, output;
    if((input = open(argv[1], O_RDONLY)) < 0)
    {
        fprintf(stderr, "Eroare la deschiderea fisierului de intrare\n");
        exit(2);
    }
    if((output = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, S_IRWXU)) < 0)
    {
        fprintf(stderr, "Eroare la crearea fisierului de iesire\n");
        exit(2);
    }
    int litereMici = 0, litereMari = 0, cifre = 0, caracterCautat = 0;
    char caracter = argv[3][0], ch;
    while(read(input, &ch, sizeof(char)) == 1)
    {
        if(islower(ch))
        {
            litereMici++;
        }
        if(isupper(ch))
        {
            litereMari++;
        }
        if(isnumber(ch))
        {
            cifre++;
        }
        if(ch == caracter)
        {
            caracterCautat++;
        }
    }
    char buffer[100];
    sprintf(buffer, "numar litere mici: %d\n", litereMici);
    if(write(output, buffer, strlen(buffer)) < 0)
    {
        fprintf(stderr, "Eroare la scriere in fisier\n");
        exit(2);
    }

    sprintf(buffer, "numar litere mari: %d\n", litereMari);
    if(write(output, buffer, strlen(buffer)) < 0)
    {
        fprintf(stderr, "Eroare la scriere in fisier\n");
        exit(2);
    }

    sprintf(buffer, "numar cifre: %d\n", cifre);
    if(write(output, buffer, strlen(buffer)) < 0)
    {
        fprintf(stderr, "Eroare la scriere in fisier\n");
        exit(2);
    }

    sprintf(buffer, "numar aparitii caracter: %d\n", caracterCautat);
    if(write(output, buffer, strlen(buffer)) < 0)
    {
        fprintf(stderr, "Eroare la scriere in fisier\n");
        exit(2);
    }

    struct stat statistici;
    if(stat(argv[2], &statistici) < 0)
    {
        fprintf(stderr, "Eroare la citirea statisticilor\n");
        exit(2);
    }
    sprintf(buffer, "dimensiune fisier: %lld\n", statistici.st_size);
    if(write(output, buffer, strlen(buffer)) < 0)
    {
        fprintf(stderr, "Eroare la scriere in fisier\n");
        exit(2);
    }
    
    close(input);
    close(output);
    return 0;
}