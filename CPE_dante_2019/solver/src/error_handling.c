/*
** EPITECH PROJECT, 2020
** solver
** File description:
** error_handling
*/

#include "solver.h"

static int check_splitted_map(map_t *m)
{
    m->x = my_strlen(m->map[0]);
    for (int i = 0; i != m->y; i++)
        if (my_strlen(m->map[i]) != m->x) {
            write_error(STR_ERROR_INV);
            return (ERROR);
        }
    return (SUCCESS);
}

static int check_buffer(char *buff)
{
    for (int i = 0; buff[i] != '\0'; i++)
        if (buff[i] != '*' && buff[i] != 'X' && buff[i] != '\n') {
            write_error(STR_ERROR_INV);
            return (ERROR);
        }
    return (SUCCESS);
}

static int is_maze_valid(char *arg, int fd, map_t *m)
{
    struct stat st;
    char *buffer;
    int rd;

    stat(arg, &st);
    buffer = malloc(sizeof(char) * st.st_size + 1);
    rd = read(fd, buffer, st.st_size);
    if (rd == -1 || rd == 0) {
        write_error(STR_ERROR_READ);
        return (ERROR);
    }
    if (check_buffer(buffer) == ERROR) {
        free(buffer);
        return (ERROR);
    }
    split_map(m, buffer);
    free(buffer);
    if (check_splitted_map(m) == ERROR)
        return (ERROR);
    return (SUCCESS);
}

int error_handling(char *arg, map_t *m)
{
    int fd = open(arg, O_RDONLY);

    if (fd == -1) {
        write_error(STR_ERROR_OPEN);
        return (ERROR);
    }
    if (is_maze_valid(arg, fd, m) == ERROR) {
        close(fd);
        return (ERROR);
    }
    close(fd);
    return (SUCCESS);
}
