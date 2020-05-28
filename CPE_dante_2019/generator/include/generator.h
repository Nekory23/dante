/*
** EPITECH PROJECT, 2020
** dante
** File description:
** generator.h
*/

#ifndef __GENERATOR_H__
#define __GENERATOR_H__

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

typedef struct map_t
{
    char **map;
    int x;
    int y;
    int perfect;
} map_t;

int error_handling(int ac, char **av);
void fill_struct(map_t *m, int ac, char **av);

void generate(map_t *m);
void maze_perfect(map_t *m);

void write_error(char *str);
int my_strcmp(char const *str1, char const *str2);

#define ERROR 84
#define SUCCESS 0
#define TRUE 1
#define FALSE 0

#define STR_ERROR_ARG "this program must take 2 to 3 args (x y [perfect])\n"
#define STR_ERROR_DIM "the dimentions are incorect\n"
#define STR_ERROR_NBR "the dimensions must be different from 0\n"
#define STR_ERROR_INVARG "the third argument must be perfect\n"

#endif
