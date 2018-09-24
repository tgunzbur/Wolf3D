/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdelhomm <sdelhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 10:53:41 by sdelhomm          #+#    #+#             */
/*   Updated: 2018/03/20 14:04:32 by tgunzbur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	init_value(t_param *p)
{
	p->j.a = 1;
	p->j.item = 0;
	p->hwallstate = 0;
	p->wexitstate = 0;
	p->exitkey = 0;
	p->tm = time(NULL);
	p->lx = SCREEN_X / 2;
	p->ly = SCREEN_Y / 2;
	p->vy = SCREEN_Y / 2;
	p->wx = SCREEN_X * 0.5;
	p->wy = SCREEN_Y * 0.5;
	p->cursorstate = 1;
	p->clean_tag = 0;
	p->time = 0;
	p->fps = 0;
}

void	*xpm_to_char(void *mlx, char *file, int *x, int *y)
{
	return (mlx_xpm_file_to_image(mlx, file, x, y));
}

void	load_sound(t_param *p)
{
	if (FMOD_System_CreateSound(p->s.system, FILE_WASH, FMOD_CREATESAMPLE,
		0, &p->s.wash) != FMOD_OK ||
		FMOD_System_CreateSound(p->s.system, FILE_APPLAUSE, FMOD_CREATESAMPLE,
		0, &p->s.applause) != FMOD_OK ||
		FMOD_System_CreateSound(p->s.system, FILE_DOOR, FMOD_CREATESAMPLE,
		0, &p->s.door_open) != FMOD_OK ||
		FMOD_System_CreateSound(p->s.system, FILE_GLASS, FMOD_CREATESAMPLE,
		0, &p->s.glass_break) != FMOD_OK ||
		FMOD_System_CreateSound(p->s.system, FILE_GRAB, FMOD_CREATESAMPLE,
		0, &p->s.grab) != FMOD_OK ||
		FMOD_System_CreateSound(p->s.system, FILE_PIANO, FMOD_CREATESAMPLE,
		0, &p->s.piano) != FMOD_OK ||
		FMOD_System_CreateSound(p->s.system, FILE_SPIKES_S, FMOD_CREATESAMPLE,
		0, &p->s.spikes_sound) != FMOD_OK ||
		FMOD_System_CreateSound(p->s.system, FILE_WALL_FALL, FMOD_CREATESAMPLE,
		0, &p->s.wall_fall) != FMOD_OK ||
		FMOD_System_CreateSound(p->s.system, FILE_TIC, FMOD_CREATESAMPLE,
		0, &p->s.tic) != FMOD_OK ||
		FMOD_System_CreateSound(p->s.system, FILE_WRONG, FMOD_CREATESAMPLE,
		0, &p->s.wrong) != FMOD_OK)
		ft_error(-3, p);
}

void	load_image(t_param *p)
{
	if (!(p->ptr_weap = xpm_to_char(p->mlx, FILE_HAMMER, &p->img_x2,
		&p->img_y2)) || !(p->ptr_weap2 = xpm_to_char(p->mlx, FILE_WSERPI,
		&p->img_x2, &p->img_y2)) || !(p->ptr_key = xpm_to_char(p->mlx,
		FILE_KEY, &p->img_x3, &p->img_y3)) || !(p->ptr_menu =
		xpm_to_char(p->mlx, FILE_MENU, &p->img_x3, &p->img_y3)) ||
		!(p->ptr_tuto = xpm_to_char(p->mlx, FILE_TUTO, &p->img_x3,
		&p->img_y3)) || !(p->ptr_cursor = xpm_to_char(p->mlx,
		FILE_CURSOR, &p->img_x3, &p->img_y3)) || !(p->ptr_s_win =
		xpm_to_char(p->mlx, FILE_WIN, &p->img_x3, &p->img_y3)) ||
		!(p->ptr_lose = xpm_to_char(p->mlx, FILE_LOSE, &p->img_x3,
		&p->img_y3)) || !(p->ptr_slot = xpm_to_char(p->mlx,
		FILE_SLOT, &p->img_x3, &p->img_y3)) || !(p->ptr_slot_hammer =
		xpm_to_char(p->mlx, FILE_SLOT_HAMMER, &p->img_x3,
		&p->img_y3)) || !(p->ptr_slot_serpi = xpm_to_char(p->mlx,
		FILE_SLOT_SERPI, &p->img_x3, &p->img_y3)) || !(p->ptr_slot2 =
		xpm_to_char(p->mlx, FILE_SLOT2, &p->img_x3, &p->img_y3)))
		ft_error(-2, p);
}

void	ft_init(t_param *p)
{
	init_value(p);
	load_texture(p);
	load_image(p);
	load_sound(p);
	if (!(p->ptr_img = mlx_new_image(p->mlx, SCREEN_X, SCREEN_Y)))
		ft_error(-5, p);
	p->img = mlx_get_data_addr(p->ptr_img, &p->sl, &p->end, &p->bpp);
}
