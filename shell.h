#ifndef HEADER_FILE
#define HEADER_FILE

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
void prompt(char **av, char **env);
int add (int num1,int num2);
int main(int ac, char **av, char **env);
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
char *_strcat(char *des, char *src);
char **_strtok(char *str);

#endif
