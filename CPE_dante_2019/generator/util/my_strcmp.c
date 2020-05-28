/*
** EPITECH PROJECT, 2019
** pool
** File description:
** my_strcmp
*/

#include "generator.h"

int my_strcmp(char const *str1, char const *str2)
{
    if (strlen(str1) != strlen(str2))
        return (0);
    for (int i = 0; str1[i] != '\0'; i++) {
        if (str1[i] != str2[i])
            return (0);
    }
    return (1);
}
