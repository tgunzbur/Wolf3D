/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdelhomm <sdelhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 13:30:44 by sdelhomm          #+#    #+#             */
/*   Updated: 2018/03/20 14:01:55 by tgunzbur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	initiation(t_param *p)
{
	p->tags = 0;
	p->menustate = 1;
	p->pos_x = 0;
	p->mlx = mlx_init();
	p->win = mlx_new_window(p->mlx, SCREEN_X, SCREEN_Y, "Wolf3D");
	CGWarpMouseCursorPosition(CGPointMake(0, 0));
	CGDisplayHideCursor((CGDirectDisplayID)NULL);
	FMOD_System_Create(&p->s.system);
	FMOD_System_Init(p->s.system, 10, FMOD_INIT_NORMAL, NULL);
	ft_init(p);
}

void	ft_error(int n, t_param *p)
{
	if (n == -1)
	{
		ft_putstr_fd("Texture error.\n", 2);
		ft_exit(p);
	}
	if (n == -2)
	{
		ft_putstr_fd("Image error.\n", 2);
		ft_exit(p);
	}
	if (n == -3)
	{
		ft_putstr_fd("Sound error.\n", 2);
		ft_exit(p);
	}
	if (n == -4)
	{
		ft_putstr_fd("Map error.\n", 2);
		ft_exit(p);
	}
	if (n == -5)
	{
		ft_putstr_fd("Memory allocation error.\n", 2);
		ft_exit(p);
	}
}

int		ft_exit(t_param *p)
{
	mlx_clear_window(p->mlx, p->win);
	free_map(p->map);
	FMOD_Sound_Release(p->s.wash);
	FMOD_System_Close(p->s.system);
	FMOD_System_Release(p->s.system);
	exit(0);
	return (-1);
}

int		main(int argc, char **argv)
{
	t_param	p;

	if (argc != 2)
	{
		ft_putstr_fd("usage: ./wolf3d [map]\n", 2);
		return (-1);
	}
	p.arg1 = argv[1];
	initiation(&p);
	if (get_map(p.arg1, map_len(p.arg1, &p.map), &p.j, &p) < 0 || p.j.a != 0)
		ft_error(-4, &p);
	wolf3d(&p);
	mlx_loop_hook(p.mlx, hook, &p);
	mlx_hook(p.win, 6, 1L << 6, mouse_hook, &p);
	mlx_hook(p.win, 2, 3, key_hook, &p);
	mlx_mouse_hook(p.win, events_mouse, &p);
	mlx_hook(p.win, 17, 0, ft_exit, &p);
	mlx_loop(p.mlx);
	return (0);
}
