/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_menu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdelhomm <sdelhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 19:01:10 by sdelhomm          #+#    #+#             */
/*   Updated: 2018/03/20 13:58:33 by tgunzbur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

int		ft_show_menu(t_param *p)
{
	if (p->menustate == 1)
	{
		mlx_put_image_to_window(p->mlx, p->win, p->ptr_menu, 0, 0);
		if (p->cursorstate == 1)
			mlx_put_image_to_window(p->mlx, p->win, p->ptr_cursor, 450, 500);
		if (p->cursorstate == 2)
			mlx_put_image_to_window(p->mlx, p->win, p->ptr_cursor, 350, 625);
		if (p->cursorstate == 3)
			mlx_put_image_to_window(p->mlx, p->win, p->ptr_cursor, 450, 740);
	}
	if (p->menustate == 2)
		mlx_put_image_to_window(p->mlx, p->win, p->ptr_tuto, 0, 0);
	return (0);
}

int		ft_death(t_param *p)
{
	free_map(p->map);
	p->j.a = 1;
	p->tags = 0;
	get_map(p->arg1, map_len(p->arg1, &p->map), &p->j, p);
	ft_init(p);
	mlx_put_image_to_window(p->mlx, p->win, p->ptr_lose, 0, 0);
	FMOD_System_PlaySound(p->s.system, p->s.piano, NULL, 0, NULL);
	return (0);
}

int		ft_win(t_param *p)
{
	char	*score;

	score = ft_itoa(p->win_time);
	free_map(p->map);
	p->j.a = 1;
	p->tags = 0;
	get_map(p->arg1, map_len(p->arg1, &p->map), &p->j, p);
	ft_init(p);
	mlx_put_image_to_window(p->mlx, p->win, p->ptr_s_win, 0, 0);
	mlx_string_put(p->mlx, p->win, 840, 470, 0x00000000, score);
	FMOD_System_PlaySound(p->s.system, p->s.applause, NULL, 0, NULL);
	free(score);
	return (0);
}
