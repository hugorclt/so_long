/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 15:23:05 by hrecolet          #+#    #+#             */
/*   Updated: 2022/01/24 15:12:59 by hrecolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	aff_player(t_vars var, int x, int y)
{
	t_data	img;
	int		w;
	int		h;

	img.img = mlx_xpm_file_to_image(var.mlx, "./assets/spaceship.XPM", &w, &h);
	if (!img.img)
	{
		ft_free_tab(var.map);
		exit(127);
	}
	mlx_put_image_to_window(var.mlx, var.win, img.img, x * 64, y * 64);
}

void	aff_background(t_vars var, int x, int y)
{
	t_data	img;
	int		w;
	int		h;

	img.img = mlx_xpm_file_to_image(var.mlx, "./assets/background.XPM", &w, &h);
	if (!img.img)
	{
		ft_free_tab(var.map);
		exit(127);
	}
	mlx_put_image_to_window(var.mlx, var.win, img.img, x * 64, y * 64);
}

void	aff_wall(t_vars var, int x, int y)
{
	t_data	img;
	int		w;
	int		h;

	img.img = mlx_xpm_file_to_image(var.mlx, "./assets/asteroids.XPM", &w, &h);
	if (!img.img)
	{
		ft_free_tab(var.map);
		exit(127);
	}
	mlx_put_image_to_window(var.mlx, var.win, img.img, x * 64, y * 64);
}

void	aff_collect(t_vars var, int x, int y)
{
	t_data	img;
	int		w;
	int		h;

	img.img = mlx_xpm_file_to_image(var.mlx, "./assets/collect.XPM", &w, &h);
	if (!img.img)
	{
		ft_free_tab(var.map);
		exit(127);
	}
	mlx_put_image_to_window(var.mlx, var.win, img.img, x * 64, y * 64);
}

void	aff_exit(t_vars var, int x, int y)
{
	t_data	img;
	int		w;
	int		h;

	img.img = mlx_xpm_file_to_image(var.mlx, "./assets/Black_hole.XPM", &w, &h);
	if (!img.img)
	{
		ft_free_tab(var.map);
		exit(127);
	}
	mlx_put_image_to_window(var.mlx, var.win, img.img, x * 64, y * 64);
}
