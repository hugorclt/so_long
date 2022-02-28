/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 13:29:27 by hrecolet          #+#    #+#             */
/*   Updated: 2022/01/24 15:09:05 by hrecolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include "get_next_line/get_next_line.h"
# include "printf/ft_printf.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_vars {
	void	*mlx;
	void	*win;
	char	**map;
	int		collectibles_max;
	int		collec;
	int		moves_count;
}				t_vars;

void	read_map(t_vars var);
int		ft_strlen(char *str);
int		find_l(char *str);
int		lo(char *str);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	aff_player(t_vars var, int x, int y);
void	aff_background(t_vars var, int x, int y);
void	aff_wall(t_vars var, int x, int y);
void	aff_collect(t_vars var, int x, int y);
void	aff_exit(t_vars var, int x, int y);
int		ft_up(t_vars *var);
int		ft_down(t_vars *var);
int		ft_left(t_vars *var);
int		ft_right(t_vars *var);
int		max_collectible(char **str);
void	moves_up(t_vars *var, int y, int x);
void	moves_down(t_vars *var, int y, int x);
void	moves_left(t_vars *var, int y, int x);
void	moves_right(t_vars *var, int y, int x);
int		check_map(char **str, char *map);
void	ft_free_tab(char **tab);
int		check_wall(char **str, char *map);
int		la(char *str);
int		longeur(char *str);
int		check_size(char **str);
int		check_player(char **str);
int		check_exit(char **str);
int		close_all(t_vars *vars);
int		check_wrong_map_char(char **str);

#endif
