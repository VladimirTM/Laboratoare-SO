#include <fcntl.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char **argv) {
  if (argc != 3) {
    printf("Argumente invalide\n");
    exit(1);
  }
  int input, output;
  if ((input = open(argv[1], O_RDONLY)) < 0) {
    printf("Eroare la deshiderea fisierului\n");
    exit(2);
  }
  if ((output = open(argv[2], O_CREAT | O_TRUNC | O_WRONLY)) < 0) {
    printf("Eroare la crearea fisierului\n");
    exit(2);
  }
  uint8_t start, dataLength, data1;
  uint16_t data2;
  uint32_t data3;
  uint32_t min = 999999999, max = 0, sum = 0, count1 = 0, count2 = 0,
           count3 = 0;
  while (read(input, &start, sizeof(uint8_t)) == sizeof(uint8_t)) {
    if (start == 0x01) {
      read(input, &dataLength, sizeof(uint8_t));
      switch (dataLength) {
      case 0x01: {
        read(input, &data1, sizeof(uint8_t));
        sum = sum + data1;
        count1++;
        if (data1 < min) {
          min = data1;
        }
        if (data1 > max) {
          max = data1;
        }
        break;
      }
      case 0x02: {
        read(input, &data2, sizeof(uint16_t));
        sum = sum + data2;
        count2++;
        if (data2 < min) {
          min = data1;
        }
        if (data2 > max) {
          max = data1;
        }
        break;
      }
      case 0x04: {
        read(input, &data3, sizeof(uint32_t));
        sum = sum + data3;
        count3++;
        if (data3 < min) {
          min = data1;
        }
        if (data3 > max) {
          max = data1;
        }
        break;
      }
      }
    }
  }
  float medie = ((double)sum) / (count1 + count2 + count3);
  char buffer[100];
  sprintf(buffer, "Minimum integer: %u\n", min);
  if (write(output, buffer, strlen(buffer)) < 0) {
    fprintf(stderr, "Eroare la scriere in fisier\n");
    exit(2);
  }
  sprintf(buffer, "Maximum integer: %u\n", max);
  if (write(output, buffer, strlen(buffer)) < 0) {
    fprintf(stderr, "Eroare la scriere in fisier\n");
    exit(2);
  }
  sprintf(buffer, "Average integer: %f\n", medie);
  if (write(output, buffer, strlen(buffer)) < 0) {
    fprintf(stderr, "Eroare la scriere in fisier\n");
    exit(2);
  }
  sprintf(buffer, "Number of 1 byte integer: %d\n", count1);
  if (write(output, buffer, strlen(buffer)) < 0) {
    fprintf(stderr, "Eroare la scriere in fisier\n");
    exit(2);
  }
  sprintf(buffer, "Number of 2 byte integer: %d\n", count2);
  if (write(output, buffer, strlen(buffer)) < 0) {
    fprintf(stderr, "Eroare la scriere in fisier\n");
    exit(2);
  }
  sprintf(buffer, "Number of 4 byte integer: %d\n", count3);
  if (write(output, buffer, strlen(buffer)) < 0) {
    fprintf(stderr, "Eroare la scriere in fisier\n");
    exit(2);
  }
  close(input);
  close(output);
  return 0;
}
