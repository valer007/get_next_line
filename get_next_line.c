#include "get_next_line.h"

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 42
#endif

static char *foo(char *str)
{
    char    *new_str;
    size_t  i = 0, j = 0;

    if (!str)
        return (NULL);
    while (str[i] && str[i] != '\n')
        i++;
    if (str[i] == 0)
    {
        free(str);
        return (NULL);
    }
    new_str = malloc(ft_strlen(str) - i);
    if (!new_str)
        return (NULL);
    i++;
    while (str[i])
        new_str[j++] = str[i++];
    new_str[j] = '\0';
    free(str);
    return (new_str);
}

static char *reading(char *buffer)
{
    char    *line;
    size_t  size = 0, num = 0;

    if (!buffer || !buffer[0])
        return (NULL);
    while (buffer[size] && buffer[size] != '\n')
        size++;
    if (buffer[size] == '\n')
        num = 1;
    line = ft_substr(buffer, 0, size + num);
    return (line);
}

char *get_next_line(int fd)
{
    static char *str;
    char buffer[BUFFER_SIZE + 1];
    char *line;
    int bytes_read;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    while ((bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0)
    {
        buffer[bytes_read] = '\0';
        str = ft_strjoin(str, buffer);
        if (!str)
            return (NULL);
        if (ft_strchr(str, '\n'))
            break;
    }
    if (bytes_read < 0 || (!str && bytes_read == 0))
        return (NULL);
    line = reading(str);
    str = foo(str);
    return (line);
}
