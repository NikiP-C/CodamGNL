/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: nphilipp <nphilipp@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/16 10:24:11 by nphilipp       #+#    #+#                */
/*   Updated: 2019/12/13 16:41:41 by nphilipp      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void		make_line(char *line, char **str1)
{
	int i;

	i = 0;
	if (str1 == NULL || *str1 == NULL)
	{
		line[i] = 0;
		if (str1 != NULL)
			free(*str1);
		str1 = NULL;
		return ;
	}
	while ((*str1)[i] != 0 && (*str1)[i] != '\n')
	{
		line[i] = (*str1)[i];
		i++;
	}
	line[i] = 0;
	free(*str1);
	*str1 = NULL;
	return ;
}

static int	check_n(char *str)
{
	int i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i] != 0)
	{
		if (str[i] == '\n')
		{
			return (1);
		}
		i++;
	}
	return (0);
}

static char	*ft_make_str(char *buf, int *start, int br, char *str)
{
	char	*str1;
	int		k;
	int		len;

	k = *start;
	if (br == 0 || check_n(str))
		return (str);
	len = ((len_l(buf, k) - k) + len_l(str, 0) + 2);
	str1 = ft_calloc_s(len);
	if (str1 == 0)
	{
		free_string(str, buf);
		return (0);
	}
	join_strings(&str1, str, 0, len_l(str, 0));
	free(str);
	k = join_strings(&str1, buf, k, br);
	*start = (k + 1);
	return (str1);
}

static int	check_fd(int fd, int *start)
{
	static int old_fd = 0;

	if (old_fd != fd)
	{
		old_fd = fd;
		*start = 0;
		return (1);
	}
	return (0);
}

int			get_next_line(int fd, char **line)
{
	static char *buf = NULL;
	static int	br;
	static int	start = 0;
	static char	*str1 = NULL;

	if (line != NULL && (check_fd(fd, &start) || start == 0))
		br = makebuf(&buf, fd);
	if (line == NULL || br < 0)
		return (-1);
	str1 = ft_make_str(buf, &start, br, str1);
	if (str1 == 0 && br != 0)
		return (-1);
	if (br != 0 && (str1[len_l(str1, 0)] != '\n' || start > br))
	{
		start = 0;
		return (get_next_line(fd, line));
	}
	*line = (char *)malloc(sizeof(char) * len_l(str1, 0) + 1);
	if (*line == 0)
		return (free_string(str1, buf));
	make_line(*line, &str1);
	if (br == 0)
		return (0);
	return (1);
}
