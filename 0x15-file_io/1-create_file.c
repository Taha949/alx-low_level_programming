#include "main.h"

/**
 * create_file - entry point
 * @filename: A pointer
 * @text_content: A pointer
 *
 * Return: int
 */

int create_file(const char *filename, char *text_content)
{
    int fd;
    ssize_t len, w;

    if (!filename)
        return (-1);

    fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, S_IRUSR | S_IWUSR);
    if (fd == -1)
        return (-1);

    if (text_content)
    {
        for (len = 0; text_content[len]; len++)
            ;
        w = write(fd, text_content, len);
        if (w == -1)
        {
            close(fd);
            return (-1);
        }
    }

    close(fd);
    return (1);
}
