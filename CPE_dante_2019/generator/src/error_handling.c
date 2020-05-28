/*
** EPITECH PROJECT, 2020
** dante
** File description:
** error_handling generator
*/

#include "generator.h"

int error_handling_xy(int ac, char **av)
{
    int x = atoi(av[1]);
    int y = atoi(av[2]);

    for (int i = 1; i != ac; i++)
        for (int j = 0; av[i][j] != '\0'; j++)
            if (av[i][j] < '0' || av[i][j] > '9') {
                write_error(STR_ERROR_DIM);
                return (TRUE);
            }
    if (y == 0 || x == 0) {
        write_error(STR_ERROR_NBR);
        return (TRUE);
    }
    return (FALSE);
}

int error_handling_perfect(int ac, char **av)
{
    int x = atoi(av[1]);
    int y = atoi(av[2]);

    for (int i = 1; i != ac - 1; i++)
        for (int j = 0; av[i][j] != '\0'; j++)
            if (av[i][j] < '0' || av[i][j] > '9') {
                write_error(STR_ERROR_DIM);
                return (TRUE);
            }
    if (y == 0 || x == 0) {
        write_error(STR_ERROR_NBR);
        return (TRUE);
    }
    if (my_strcmp(av[3], "perfect") == FALSE) {
        write_error(STR_ERROR_INVARG);
        return (TRUE);
    }
    return (FALSE);
}

int error_handling(int ac, char **av)
{
    if (ac == 3)
        return (error_handling_xy(ac, av));
    else
        return (error_handling_perfect(ac, av));
}
