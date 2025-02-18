# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000000
# endif

static char    *read_to_buffer(int fd, char *buffer)
{
    char *temp;
    int bytes_read;

    temp = malloc(sizeof(char) * (BUFFER_SIZE + 1));
    if (!temp)
        return (NULL);
    bytes_read = 1;
    while (!ft_strchr(buffer, '\n') && bytes_read > 0)
    {
        bytes_read = read(fd, temp, BUFFER_SIZE);
        if (bytes_read == -1)
        {
            free(temp);
            free(buffer);
            return (NULL);
        }
        temp[bytes_read] = '\0';
        buffer = ft_strjoin(buffer, temp);
        if (!buffer)
            return (NULL);
    }
    free(temp);
    return (buffer);
}

static char    *extract_line(char *buffer)
{
    char *line;
    int i;

    if (!buffer[i])
        return (NULL);
    while (buffer[i] && buffer[i] != '\n')
        i++;
    line = malloc(sizeof(char) * (i + 2));
    if (!line)
        return (NULL);
    i = 0;
    while (buffer[i] && buffer[i] != '\n')
    {
        line[i] = buffer[i];
        i++;
    }
    if (buffer[i] == '\n')
        line[i++] = '\n';
    line[i] = '\0';
    return (line);
}

static char *update_buffer(char *buffer)
{
    
}

static char	*get_next_line(int fd)
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