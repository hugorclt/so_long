/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 20:12:46 by hrecolet          #+#    #+#             */
/*   Updated: 2022/01/21 12:37:55 by hrecolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	longeur(char *str)
{
	int		fd;
	char	*line;
	int		len;

	fd = open(str, 0);
	if (fd == -1)
		exit(127);
	line = get_next_line(fd);
	len = ft_strlen(line);
	free(line);
	close(fd);
	len = len - 1;
	return (len);
}

int	la(char *str)
{
	char	*line;
	int		i;
	int		fd;

	i = 0;
	fd = open(str, 0);
	line = get_next_line(fd);
	if (!line)
		return (0);
	while (line)
	{
		free(line);
		i++;
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	return (i);
}

int	lo(char *str)
{
	int		fd;
	char	*line;
	int		len;

	fd = open(str, 0);
	if (fd == -1)
		exit(127);
	line = get_next_line(fd);
	len = ft_strlen(line);
	free(line);
	close(fd);
	len--;
	return (len * 64);
}

int	find_l(char *str)
{
	int		fd;
	char	*line;
	int		i;

	i = 1;
	fd = open(str, 0);
	if (fd == -1)
		exit(127);
	line = get_next_line(fd);
	while (line)
	{
		line = get_next_line(fd);
		i++;
	}
	free(line);
	close(fd);
	return (i * 64);
}
