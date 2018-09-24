/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_fcts.c.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdelhomm <sdelhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 16:28:43 by sdelhomm          #+#    #+#             */
/*   Updated: 2018/03/20 11:26:36 by tgunzbur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

int		check_spike(t_param *p, t_map map)
{
	int	x;
	int	y;

	x = floor(p->j.x);
	y = floor(p->j.y);
	if ((x >= 1 && map.map[y][x - 1] == 6) ||
		(y >= 1 && map.map[y - 1][x] == 6) ||
		(x < map.x - 1 && map.map[y][x + 1] == 6) ||
		(y < map.y - 1 && map.map[y + 1][x] == 6))
		return (0);
	return (1);
}

int		check_collision(int kc, t_param *p, t_map map)
{
	double	x;
	double	y;
	double	a;

	x = p->j.x;
	y = p->j.y;
	a = p->j.a * M_PI / 180;
	a += (kc == 0 ? -M_PI_2 : 0);
	a += (kc == 2 ? M_PI_2 : 0);
	a += (kc == 1 ? M_PI : 0);
	x = x + HB * cos(a);
	y = y + HB * sin(a);
	if (kc >= 0 && kc <= 13 && x >= 0 && y >= 0 && x < map.x && y < map.y &&
	((map.map[(int)floor(y - 0.2 * sin(a))][(int)floor(x - 0.2 * cos(a))] < 1
	&& map.map[(int)floor(y)][(int)floor(x)] < 1) ||
	(map.map[(int)floor(y - 0.2 * sin(a))][(int)floor(x - 0.2 * cos(a))] > 6
	&& map.map[(int)floor(y)][(int)floor(x)] > 6)) &&
	map.map[(int)floor(y - 0.2 * sin(a))][(int)floor(x - 0.2 * cos(a))] != 8
	&& map.map[(int)floor(y)][(int)floor(x)] != 8)
	{
		p->j.x = p->j.x + 0.1 * cos(a);
		p->j.y = p->j.y + 0.1 * sin(a);
		return (check_spike(p, map));
	}
	return (1);
}
