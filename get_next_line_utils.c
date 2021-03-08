/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: nphilipp <nphilipp@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/07 15:03:01 by nphilipp      #+#    #+#                 */
/*   Updated: 2021/03/08 19:32:01 by nphilipp      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	free_string(char *str1, char *buf)
{
	free(buf);
	free(str1);
	return (-1);
}

int	len_l(char *buf, int start)
{
	if (buf == NULL)
		return (0);
	while (buf[start] != '\n' && buf[start])
	{
		start++;
	}
	return (start);
}

int	join_strings(char **dest, char *src, int k, int br)
{
	int	i;

	i = 0;
	if (src == NULL)
		return (0);
	while (*dest != NULL && (*dest)[i] != '\0')
		i++;
	while (src[k] != '\0' && src[k] != '\n' && k < br)
	{
		(*dest)[i] = src[k];
		i++;
		k++;
	}
	if (src[k] == '\n')
	{
		(*dest)[i] = '\n';
		i++;
	}
	(*dest)[i] = '\0';
	return (k);
}

char	*ft_calloc_s(int len)
{
	char	*str;
	int		i;

	i = 0;
	str = malloc(sizeof(char) * len);
	if (str == 0)
		return (0);
	while (i < len)
	{
		str[i] = 0;
		i++;
	}
	return (str);
}

int	makebuf(char **buf, int fd)
{
	int	br;

	if (*buf == NULL)
		*buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (*buf == 0)
		return (-1);
	br = read(fd, *buf, BUFFER_SIZE);
	if (br <= 0)
	{
		free(*buf);
		*buf = NULL;
		return (br);
	}
	(*buf)[br] = 0;
	return (br);
}
