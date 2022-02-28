/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 17:33:30 by hrecolet          #+#    #+#             */
/*   Updated: 2022/01/21 12:05:09 by hrecolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_size(char **str)
{
	int	len;
	int	i;

	i = 0;
	len = ft_strlen(str[0]);
	while (str[i])
	{
		if (len != ft_strlen(str[i]))
			return (1);
		i++;
	}
	return (0);
}

int	check_wall(char **str, char *map)
{
	int	i;
	int	j;
	int	i_max;
	int	y_max;

	i_max = la(map) - 1;
	y_max = longeur(map) - 1;
	i = 0;
	while (str[i])
	{
		j = 0;
		while (j < ft_strlen(str[i]) - 1)
		{
			if (str[0][j] != '1' || str[i_max][j] != '1')
				return (1);
			else if (str[i][y_max] != '1' || str[i][0] != '1')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_collec(char **str)
{
	int	i;
	int	y;
	int	collec;

	i = 0;
	collec = 0;
	while (str[i])
	{
		y = 0;
		while (str[i][y])
		{
			if (str[i][y] == 'C')
				collec++;
			y++;
		}
		i++;
	}
	if (collec <= 0)
		return (1);
	return (0);
}

int	check_player(char **str)
{
	int	i;
	int	y;
	int	player;

	i = 0;
	player = 0;
	while (str[i])
	{
		y = 0;
		while (str[i][y])
		{
			if (str[i][y] == 'P')
				player++;
			y++;
		}
		i++;
	}
	if (player != 1)
		return (1);
	return (0);
}

int	check_map(char **str, char *map)
{
	if (check_size(str) || check_wrong_map_char(str))
	{
		ft_printf("Error \nWrong map size or unknown character\n");
		ft_free_tab(str);
		exit(127);
	}
	if (check_wall(str, map))
	{
		ft_printf("Error \nWrong wall placements\n");
		ft_free_tab(str);
		exit(127);
	}
	if (check_collec(str))
	{
		ft_printf("Error \nWrong number of collectibles\n");
		ft_free_tab(str);
		exit(127);
	}
	if (check_exit(str) || check_player(str))
	{
		ft_printf("Error \nYou must have only one player and one exit \n");
		ft_free_tab(str);
		exit(127);
	}
	return (1);
}
