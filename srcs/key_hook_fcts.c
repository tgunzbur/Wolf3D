/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook_fcts.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdelhomm <sdelhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 16:28:43 by sdelhomm          #+#    #+#             */
/*   Updated: 2018/03/20 14:00:16 by tgunzbur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void		key_hook_hammer(t_param *p)
{
	if (p->hwallstate == 0)
	{
		p->hwallstate = 1;
		p->hwall = p->hwall2;
		FMOD_System_PlaySound(p->s.system, p->s.glass_break, NULL, 0, NULL);
	}
	else if (p->hwallstate == 1)
	{
		p->j.item += 1;
		p->j.a_item = 2;
		p->hwall = p->hwall3;
		p->hwallstate = 2;
		FMOD_System_PlaySound(p->s.system, p->s.grab, NULL, 0, NULL);
	}
}

void		key_hook_exit(t_param *p)
{
	if (p->exitkey != 1)
		FMOD_System_PlaySound(p->s.system, p->s.wrong, NULL, 0, NULL);
	else if (p->wexitstate == 0)
	{
		p->wexit = p->wexit2;
		p->wexitstate = 1;
		FMOD_System_PlaySound(p->s.system, p->s.door_open, NULL, 0, NULL);
	}
	else if (p->wexitstate == 1)
	{
		p->menustate = 4;
		p->cursorstate = 1;
		p->win_time = time(NULL) - p->tm;
		ft_win(p);
	}
}

void		key_hook_walls(int keycode, t_param *p)
{
	int	x;
	int	y;

	if (keycode == 14)
	{
		x = (int)floor(p->j.x + 0.5 * cos(p->j.a * M_PI / 180));
		y = (int)floor(p->j.y + 0.5 * sin(p->j.a * M_PI / 180));
		if (p->map.map[y][x] == 2 && p->j.item % 2 != 1)
			key_hook_hammer(p);
		else if (p->map.map[y][x] == 4 && p->j.item <= 1)
		{
			p->j.item += 2;
			p->j.a_item = 1;
			p->swall = p->swall2;
			FMOD_System_PlaySound(p->s.system, p->s.grab, NULL, 0, NULL);
		}
		else if (p->map.map[y][x] == 8)
			key_hook_exit(p);
	}
}

void		key_hook_starting_menu(t_param *p)
{
	if (p->menustate == 1)
	{
		if (p->cursorstate == 1)
		{
			p->tm = time(NULL);
			p->menustate = 0;
			p->cursorstate = 0;
		}
		else if (p->cursorstate == 2)
		{
			p->menustate = 2;
			p->cursorstate = 0;
		}
		else if (p->cursorstate == 3)
			ft_exit(p);
	}
	else if (p->menustate == 2 || p->menustate == 3 || p->menustate == 4)
	{
		if (p->menustate == 2)
			p->cursorstate = 2;
		else
			p->cursorstate = 1;
		p->menustate = 1;
	}
}

void		key_hook_menu(int keycode, t_param *p)
{
	if (keycode == 36)
		key_hook_starting_menu(p);
	if (!check_collision(keycode, p, p->map))
	{
		FMOD_System_PlaySound(p->s.system, p->s.spikes_sound, NULL, 0, NULL);
		p->menustate = 3;
		ft_death(p);
	}
	if (keycode == 19)
		p->j.a_item = 1;
	if (keycode == 18)
		p->j.a_item = 2;
}
