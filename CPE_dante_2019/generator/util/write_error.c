/*
** EPITECH PROJECT, 2020
** navy
** File description:
** write on the error output
*/

#include <unistd.h>
#include <string.h>

void write_error(char *str)
{
    write(2, str, strlen(str));
}
