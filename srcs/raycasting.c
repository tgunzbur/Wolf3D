/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdelhomm <sdelhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 17:52:38 by sdelhomm          #+#    #+#             */
/*   Updated: 2018/03/20 14:01:43 by tgunzbur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"
#include <stdio.h>

void	aff_nb(t_param *p, int x, int y)
{
	char	*str_time;
	char	*str_fps;
	char	*str_cl_tag;
	char	*str_tags;
	char	*str_score;

	str_time = ft_itoa(p->time);
	str_fps = ft_itoa(p->fps);
	str_cl_tag = ft_itoa(p->clean_tag);
	str_tags = ft_itoa(p->tags);
	str_score = ft_strjoin(str_cl_tag, " / ");
	free(str_cl_tag);
	str_cl_tag = ft_strjoin(str_score, str_tags);
	free(str_score);
	free(str_tags);
	mlx_string_put(p->mlx, p->win, x / 2 - 10, y * 0.01, 0xFFFFFF, str_time);
	mlx_string_put(p->mlx, p->win, x * 0.975, y * 0.01, 0xFFFFFF, str_fps);
	mlx_string_put(p->mlx, p->win, x * 0.025, y * 0.01, 0xFFFFFF, str_cl_tag);
	free(str_cl_tag);
	free(str_time);
	free(str_fps);
}

int		set_direction(double x, double y, t_player j, t_param *p)
{
	int dir;
	int	px;
	int	py;

	dir = 0;
	dir = (x == 0 || x == p->map.x || y == 0 || y == p->map.y ? W : dir);
	dir = (x == nearbyint(x) && x < j.x ? WEST : dir);
	dir = (x == nearbyint(x) && x > j.x ? EAST : dir);
	dir = (y == nearbyint(y) && y < j.y ? NORTH : dir);
	dir = (y == nearbyint(y) && y > j.y ? SOUTH : dir);
	py = (int)floor(p->ry);
	px = (int)floor(p->rx);
	if (px >= 0 && py >= 0 && x < p->map.x && y < p->map.y)
	{
		dir = (p->map.map[py][px] == 2 ? HAMMER_WALL : dir);
		dir = (p->map.map[py][px] == 3 ? TAG : dir);
		dir = (p->map.map[py][px] == 4 ? SERPI : dir);
		dir = (p->map.map[py][px] == 5 ? WALL : dir);
		dir = (p->map.map[py][px] == 8 ? END : dir);
		dir = (p->map.map[py][px] == 6 ? SPIKE : dir);
	}
	return (dir);
}

double	raycast(double coefx, double coefy, t_player j, t_param *p)
{
	double	x;
	double	y;

	x = j.x;
	y = j.y;
	while (x >= 0 && y >= 0 && x < p->map.x && y < p->map.y &&
			(p->map.map[(int)floor(y)][(int)floor(x)] < 1 ||
			p->map.map[(int)floor(y)][(int)floor(x)] > 6) &&
			p->map.map[(int)floor(y)][(int)floor(x)] != 8)
	{
		x += coefx / 500;
		y += coefy / 500;
	}
	if ((p->rx = x) && nearbyint(x) + 0.01 >= x && nearbyint(x) - 0.01 <= x)
	{
		x = nearbyint(x);
		p->pos = y - floor(y);
	}
	if ((p->ry = y) && nearbyint(y) + 0.01 >= y && nearbyint(y) - 0.01 <= y)
	{
		p->pos = x - floor(x);
		y = nearbyint(y);
	}
	p->dir = set_direction(x, y, j, p);
	return (sqrt(pow(x - j.x, 2) + pow(y - j.y, 2)));
}

void	add_image_to_sceen(t_param *p, int x, int x2, int y)
{
	if (p->j.a_item == 1)
	{
		mlx_put_image_to_window(p->mlx, p->win, p->ptr_slot, x, y);
		mlx_put_image_to_window(p->mlx, p->win, p->ptr_slot2, x2, y);
	}
	else
	{
		mlx_put_image_to_window(p->mlx, p->win, p->ptr_slot2, x, y);
		mlx_put_image_to_window(p->mlx, p->win, p->ptr_slot, x2, y);
	}
	if (p->j.item == 1 || p->j.item == 3)
		mlx_put_image_to_window(p->mlx, p->win, p->ptr_slot_hammer, x, y);
	if (p->j.item == 2 || p->j.item == 3)
		mlx_put_image_to_window(p->mlx, p->win, p->ptr_slot_serpi, x2, y);
	if ((p->j.item == 1 || p->j.item == 3) && p->j.a_item == 2)
		mlx_put_image_to_window(p->mlx, p->win, p->ptr_weap, p->wx, p->wy);
	if ((p->j.item == 2 || p->j.item == 3) && p->j.a_item == 1)
		mlx_put_image_to_window(p->mlx, p->win, p->ptr_weap2, p->wx, p->wy);
	x = SCREEN_X * 0.05;
	y = SCREEN_Y * 0.05;
	if (p->exitkey == 1)
		mlx_put_image_to_window(p->mlx, p->win, p->ptr_key, x, y);
}

int		wolf3d(t_param *p)
{
	double	a;
	double	d;
	int		x;

	a = p->j.a - 30;
	x = 0;
	while (x < SCREEN_X)
	{
		if (a > 360 || a < -360)
			a = copysign(fabsl(a) - 360, a);
		d = raycast(cos(a * M_PI / 180), sin(a * M_PI / 180), p->j, p);
		d *= cos((a - p->j.a) * M_PI / 180);
		draw_column(d, p, x++);
		a += ((double)60 / (double)SCREEN_X);
	}
	mlx_put_image_to_window(p->mlx, p->win, p->ptr_img, 0, 0);
	add_image_to_sceen(p, SCREEN_X * 0.4, SCREEN_X * 0.5, SCREEN_Y * 0.85);
	aff_nb(p, SCREEN_X, SCREEN_Y);
	return (0);
}
