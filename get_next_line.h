/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: nphilipp <nphilipp@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/07 15:03:16 by nphilipp       #+#    #+#                */
/*   Updated: 2019/12/05 18:36:46 by nphilipp      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

int		get_next_line(int fd, char **line);
int		makebuf(char **buf, int fd);
int		free_string(char *str1, char *buf);
int		free_string_null(char *str1);
int		ret_value(int bytesread);
char	*ft_calloc_s(int len);
int		join_strings(char **dest, char *src, int k, int bytesread);
int		len_l(char *buf, int start);

#endif
