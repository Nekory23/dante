/*
** EPITECH PROJECT, 2020
** dante
** File description:
** main solver
*/

#include "solver.h"

int main(int ac, char **av)
{
    map_t *m = malloc(sizeof(map_t));

    if (ac != 2) {
        write_error(STR_ERROR_ARG);
        return (ERROR);
    }
    fill_struct(m);
    if (error_handling(av[1], m) == ERROR) {
        free(m);
        return (ERROR);
    }
    if (solve_this(m))
        free(m);
    return (SUCCESS);
}
