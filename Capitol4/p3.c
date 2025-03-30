#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char **argv)
{
  if (argc != 3)
  {
    printf("Argumente invalide\n");
    exit(1);
  }
  int input, output;
  if ((input = open(argv[1], O_RDONLY)) < 0)
  {
    printf("Eroare la deschiderea fisierului\n");
    exit(2);
  }
  if((output = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, S_IRWXU)) < 0)
  {
    printf("Eroare la crearea fisierului\n");
    exit(2);
  }
  int nr, sum = 0, count = 0, min = 999999999, max = -999999999;
  while(read(input, &nr, sizeof(int)) == sizeof(int))
  {
    sum = sum + nr;
    count++;
    if(nr < min)
    {
      min = nr;
    }
    if(nr > max)
    {
      max = nr;
    }
  }
  double medie = ((double)sum) / count;
  char buffer[100];
  sprintf(buffer, "maxim: %d\nminim: %d\nmedie:%f\n", max, min, medie);
  if(write(output, buffer, strlen(buffer)) < 0)
  {
    printf("Eroare la scrierea in fisier\n");
    exit(2);
  }
  close(input);
  close(output);
  return 0;
}
