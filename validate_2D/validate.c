/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sholiak <sholiak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 15:10:39 by sholiak           #+#    #+#             */
/*   Updated: 2019/07/05 15:48:38 by sholiak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <stdio.h>

char **fill(char *buff)
{
    int i = 0;
    int j = 0;
    int w = 0;
    char **dest;

    dest = (char **)malloc(sizeof(char *) * 5);
    if (!dest)
        return (0);
    w = 0;
    while (w != 4)
    {
        dest[w] = (char *)malloc(sizeof(char) * 6);
        if (!dest[w])
            return (0);
        while (j != 5)
        {
            dest[w][j] = buff[i];
            j++;
            i++;
        }
        dest[w][j] = '\0';
        w++;
        j = 0;
    }
    dest[4] = NULL;
    return (dest);
}

int validate(char **dest)
{
    int w = 0;
    int j = 0;
    int dot = 0;
    int hash = 0;

    while (w < 4)
    {
        if (dest[w][j] == '.')
        {
            dot++;
            j++;
        }
        else if (((dest[w][j] == '#' && w < 3) && (dest[w + 1][j] == '#' ||
            dest[w][j + 1] == '#' || dest[w + 1][j - 1] == '#' || dest[w + 1][j - 2] == '#')) ||
                 (j == 3 && dest[w][j] == '#' && hash == 3))
        {
            hash++;
            j++;
        }
        else if ((w > 0 && dest[w][j] == '#') && (dest[w - 1][j] == '#' || dest[w][j + 1] == '#' || dest[w][j - 1] == '#'))
        {
            if ((hash == 1 && dest[w][j] == '#' && w < 3 && dest[w + 1][j - 1] != '#') && (dest[w][j + 1] != '#'))
                return (-1);
            hash++;
            j++;
        }
        else if (dest[w][j] == '\n')
        {
            w++;
            j = 0;
        }
        else
            j++;
    }
    free(dest);
    if (hash == 4 && dot == 12)
        return (1);
    else
        return (-1);
}

#include <fcntl.h>
int main()
{
    int fd = 0;
    char *buff;
    int check;

    buff = (char *)malloc(sizeof(char) * 21);
    fd = open("test", O_RDONLY);
    while (read(fd, buff, 21))
    {
        check = validate(fill(buff));
        printf("%d\n", check);
        // free(buff);
    }
    return (0);
}