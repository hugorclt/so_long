/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 01:59:15 by hrecolet          #+#    #+#             */
/*   Updated: 2022/01/24 15:06:49 by hrecolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	**parse_map(char *str)
{
	char	**map;
	char	*ret;
	int		i;
	int		fd;
	int		size;

	size = la(str);
	i = 0;
	fd = open(str, 0);
	map = malloc(sizeof(char *) * (size + 1));
	if (!map)
		return (NULL);
	ret = get_next_line(fd);
	while (ret)
	{
		map[i] = ret;
		ret = get_next_line(fd);
		i++;
	}
	map[i] = NULL;
	free(ret);
	close(fd);
	return (map);
}

int	close_all(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	ft_free_tab(vars->map);
	exit(0);
}

int	ft_key_press(int keycode, t_vars *vars)
{
	static int	collec;

	vars->collec = collec;
	if (keycode == 53)
		close_all(vars);
	if (keycode == 13 || keycode == 0 || keycode == 1
		|| keycode == 2)
	{
		if (keycode == 13)
			collec += ft_up(vars);
		else if (keycode == 0)
			collec += ft_left(vars);
		else if (keycode == 1)
			collec += ft_down(vars);
		else if (keycode == 2)
			collec += ft_right(vars);
		ft_printf("moves_count : %d\n", vars->moves_count);
		ft_printf("%d / %d\n", collec, vars->collectibles_max);
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_vars	var;
	int		larg;

	larg = la(av[1]) * 64;
	if (ac != 2)
		return (0);
	else
	{
		var.moves_count = 0;
		var.mlx = mlx_init();
		var.map = parse_map(av[1]);
		check_map(var.map, av[1]);
		var.win = mlx_new_window(var.mlx, lo(av[1]), larg, "S");
		read_map(var);
		var.collectibles_max = max_collectible(var.map);
		mlx_hook(var.win, 17, 0L, close_all, &var);
		mlx_key_hook(var.win, ft_key_press, &var);
		mlx_loop(var.mlx);
	}
}
