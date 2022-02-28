/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 03:51:28 by hrecolet          #+#    #+#             */
/*   Updated: 2022/01/24 15:08:44 by hrecolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	read_map(t_vars var)
{
	int	i;
	int	j;

	i = 0;
	while (var.map[i])
	{
		j = 0;
		while (var.map[i][j])
		{
			if (var.map[i][j] == '1')
				aff_wall(var, j, i);
			else if (var.map[i][j] == '0')
				aff_background(var, j, i);
			else if (var.map[i][j] == 'P')
				aff_player(var, j, i);
			else if (var.map[i][j] == 'C')
				aff_collect(var, j, i);
			else if (var.map[i][j] == 'E')
				aff_exit(var, j, i);
			j++;
		}
		i++;
	}
}
