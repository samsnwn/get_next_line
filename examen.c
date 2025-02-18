# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000000
# endif

char    *read_to_buffer(int fd, char *buffer)
{
    char *temp;
    int bytes_read;

    temp = malloc(sizeof(char) * (BUFFER_SIZE + 1));
    if (!temp)
        return (NULL);
    bytes_read = 1;
    while (!ft_strchr(buffer, '\n') && bytes_read > 0)
    {
        bytes_read = read(fd, buffer, BUFFER_SIZE)
    }
    return (buffer);
}

char	*get_next_line(int fd)
{
    static char *buffer;
    char *line;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    buffer = read_to_buffer(fd, buffer);
    if (!buffer)
        return (NULL);
    line = extract_line(buffer);
    buffer = update_buffer(buffer);
    return  (line);
}