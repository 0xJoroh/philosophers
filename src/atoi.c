#include "../philo.h"

static int whitespace(char c)
{
    if (c == '\n' || c == '\v' || c == '\f' || c == '\t' || c == '\r')
        return (1);
    if (c == ' ')
        return (1);
    return (0);
}

int ft_atoi(const char *str)
{
    int i;
    unsigned long result;

    result = 0;
    i = 0;
    while (whitespace(str[i]))
        i++;
    if (str[i] == '-')
        return (-1);
    if (str[i] == '+')
        i++;
    while (str[i] >= 48 && str[i] <= 57)
    {
        result = result * 10 + (str[i] - 48);
        i++;
    }
    if (str[i] != '\0')
        return (-1);
    if (result > 2147483647)
        return (-1);
    return (result);
}