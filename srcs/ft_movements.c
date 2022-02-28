/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_movements.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 04:08:07 by hrecolet          #+#    #+#             */
/*   Updated: 2022/01/24 15:14:27 by hrecolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	index_player(int *x, int *y, char **str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] == 'P')
			{
				(*x) = j;
				(*y) = i;
			}
			j++;
		}
		i++;
	}
}

int	ft_up(t_vars *var)
{
	int	x;
	int	y;
	int	i;

	i = 0;
	index_player(&x, &y, var->map);
	if (var->map[y - 1][x] != '1' && var->map[y - 1][x] != 'C'
		&& var->map[y - 1][x] != 'E')
		moves_up(var, y, x);
	if (var->map[y - 1][x] == 'C')
	{
		var->map[y][x] = '0';
		var->map[y - 1][x] = 'P';
		var->moves_count++;
		read_map((*var));
		return (1);
	}
	if (var->map[y - 1][x] == 'E' && var->collec == var->collectibles_max)
		close_all(var);
	return (0);
}

int	ft_down(t_vars *var)
{
	int	x;
	int	y;
	int	i;

	i = 0;
	index_player(&x, &y, var->map);
	if (var->map[y + 1][x] != '1' && var->map[y + 1][x] != 'C'
		&& var->map[y + 1][x] != 'E')
		moves_down(var, y, x);
	if (var->map[y + 1][x] == 'C')
	{
		var->map[y][x] = '0';
		var->map[y + 1][x] = 'P';
		var->moves_count++;
		read_map((*var));
		return (1);
	}
	if (var->map[y + 1][x] == 'E')
		close_all(var);
	return (0);
}

int	ft_left(t_vars *var)
{
	int	x;
	int	y;
	int	i;

	i = 0;
	index_player(&x, &y, var->map);
	if (var->map[y][x - 1] != '1' && var->map[y][x - 1] != 'C'
		&& var->map[y][x - 1] != 'E')
		moves_left(var, y, x);
	if (var->map[y][x - 1] == 'C')
	{
		var->map[y][x] = '0';
		var->map[y][x - 1] = 'P';
		var->moves_count++;
		read_map((*var));
		return (1);
	}
	if (var->map[y][x - 1] == 'E' && var->collec == var->collectibles_max)
		close_all(var);
	return (0);
}

int	ft_right(t_vars *var)
{
	int	x;
	int	y;
	int	i;

	i = 0;
	index_player(&x, &y, var->map);
	if (var->map[y][x + 1] != '1' && var->map[y][x + 1] != 'C'
		&& var->map[y][x + 1] != 'E')
		moves_right (var, y, x);
	if (var->map[y][x + 1] == 'C')
	{
		var->map[y][x] = '0';
		var->map[y][x + 1] = 'P';
		var->moves_count++;
		read_map((*var));
		return (1);
	}
	if (var->map[y][x + 1] == 'E' && var->collec == var->collectibles_max)
		close_all(var);
	return (0);
}
