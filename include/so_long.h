/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschaft <cecile.schaft@orange.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 11:53:50 by jschaft           #+#    #+#             */
/*   Updated: 2024/01/11 11:45:40 by jschaft          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../minilibx-linux/mlx.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

# define KEY_ESCAPE 65307
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100

typedef struct s_img
{
	void	*floor;
	void	*wall;
	void	*exit;
	void	*cow;
	void	*collec;
}				t_img;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	char		**map;
	int			nb_move;
	int			height;
	int			width;
	int			posx;
	int			posy;
	int			nbr_collec;
	int			flood_data;
	int			good_map;
	t_img		img;
	int			have_exit;
	int			have_player;
}				t_data;

char	*get_next_line(int fd);
int		ft_strlen(char const *s);
void	ft_putnbr(int n);

t_data	*get_map(t_data *d, char *file);
t_data	*check_map(t_data *d);
t_data	*flood_fill(t_data *d);

void	print_img(t_data *d, void *img, int x, int y);
int		render_background(t_data *d);
void	put_move(t_data *d);
int		key_pressed(int keycode, t_data *d);
void	draw(t_data *d);

t_data	*move_right(t_data *d);
t_data	*move_left(t_data *d);
t_data	*move_down(t_data *d);
t_data	*move_up(t_data *d);

void	pre_end(t_data *d);
int		end(t_data *d);
void	win(t_data *d);

#endif