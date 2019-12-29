/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main_good.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: nphilipp <nphilipp@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/16 12:29:59 by nphilipp       #+#    #+#                */
/*   Updated: 2019/12/13 16:16:47 by nphilipp      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int	main(int ac, char **av)
{
	int		retval;
	int		i;
	int		fd;
	char	*str;

	retval = 1;
	i = 0;
	fd = 0;
	str = NULL;
	if (ac >= 2)
		fd = open(av[1], O_RDONLY);
	while (i < 22)
	{
		retval = get_next_line(fd, &str);
		printf("%d | %s\n", retval, str);
		if (str != NULL)
			free(str);
		str = NULL;
		i++;
	}
	return (0);
}
