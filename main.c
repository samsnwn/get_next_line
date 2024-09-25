#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

void test_basic_functionality(void)
{
    int fd = open("test.txt", O_RDONLY);
    char *line;
    int lines;
    
    lines = 1;
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%d -> %s\n", lines++, line);
        free(line);
    }
    close(fd);
}

void test_empty_file(void)
{
    int fd = open("empty_file.txt", O_RDONLY);
    char *line = get_next_line(fd);
    
    if (line == NULL)
        printf("Empty file test passed\n");
    else
        printf("Empty file test failed\n");
    close(fd);
}

void test_invalid_fd(void)
{
    char *line = get_next_line(-1);
    
    if (line == NULL)
        printf("Invalid fd test passed\n");
    else
        printf("Invalid fd test failed\n");
}

int main(void)
{
    test_basic_functionality();
    test_empty_file();
    test_invalid_fd();
    return 0;
}