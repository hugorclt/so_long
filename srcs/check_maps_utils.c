/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_maps_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 13:04:23 by hrecolet          #+#    #+#             */
/*   Updated: 2022/01/24 14:34:25 by hrecolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_exit(char **str)
{
	int	i;
	int	y;
	int	exit;

	i = 0;
	exit = 0;
	while (str[i])
	{
		y = 0;
		while (str[i][y])
		{
			if (str[i][y] == 'E')
				exit++;
			y++;
		}
		i++;
	}
	if (exit != 1)
		return (1);
	return (0);
}

int	check_wrong_map_char(char **str)
{
	int	i;
	int	j;
	int	size;

	size = ft_strlen(str[0]);
	i = 0;
	while (str[i])
	{
		j = 0;
		while (j < size - 1)
		{
			if (str[i][j] != '1' && str[i][j] != '0' && str[i][j] != 'E'
				&& str[i][j] != 'C' && str[i][j] != 'P')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
