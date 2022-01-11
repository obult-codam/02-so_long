/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   set_hooks.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: oswin <oswin@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/22 21:37:23 by oswin         #+#    #+#                 */
/*   Updated: 2022/01/10 22:35:37 by oswin         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "so_long.h"
#include <stdlib.h>
#include "libft.h"
#include <unistd.h>

void	sl_do_special(t_data *data)
{
	push_img_to_coords(*data, data->jump0, data->x, data->y);
	sleep(1);
	push_img_to_coords(*data, data->jump1, data->x, data->y);
	sleep(1);
	push_img_to_coords(*data, data->jump2, data->x, data->y);

	push_img_to_coords(*data, data->jump3, data->x, data->y);

	push_img_to_coords(*data, data->jump4, data->x, data->y);

	/* push_img_to_coords(*data, data->sprite, data->x, data->y); */
}

int	key_hook(int keycode, t_data *data)
{
	if (keycode == 65307 || keycode == 'q')
	{
		mlx_destroy_window(data->mlx, data->win);
		exit(0);
	}
	else if (keycode == 65362 || keycode == 119)
		sl_walk_up(data);
	else if (keycode == 65361 || keycode == 97)
		sl_walk_left(data);
	else if (keycode == 65364 || keycode == 115)
		sl_walk_down(data);
	else if (keycode == 65363 || keycode == 100)
		sl_walk_right(data);
	else if (keycode == 32)
		sl_do_special(data);
	return (0);
}

int	set_hooks(t_data *data)
{
	mlx_key_hook(data->win, key_hook, data);
	return (0);
}
