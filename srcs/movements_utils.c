/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 13:21:57 by hrecolet          #+#    #+#             */
/*   Updated: 2022/01/24 15:15:19 by hrecolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	moves_up(t_vars *var, int y, int x)
{
	var->map[y][x] = '0';
	var->map[y - 1][x] = 'P';
	var->moves_count++;
	read_map((*var));
}

void	moves_down(t_vars *var, int y, int x)
{
	var->map[y][x] = '0';
	var->map[y + 1][x] = 'P';
	var->moves_count++;
	read_map((*var));
}

void	moves_left(t_vars *var, int y, int x)
{
	var->map[y][x] = '0';
	var->map[y][x - 1] = 'P';
	var->moves_count++;
	read_map((*var));
}

void	moves_right(t_vars *var, int y, int x)
{
	var->map[y][x] = '0';
	var->map[y][x + 1] = 'P';
	var->moves_count++;
	read_map((*var));
}
