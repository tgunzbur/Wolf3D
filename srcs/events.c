/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdelhomm <sdelhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 16:28:43 by sdelhomm          #+#    #+#             */
/*   Updated: 2018/03/20 14:36:22 by tgunzbur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

int			events_mouse(int bc, int x, int y, t_param *p)
{
	if (bc == 1)
	{
		x = (int)floor(p->j.x + 0.5 * cos(p->j.a * M_PI / 180));
		y = (int)floor(p->j.y + 0.5 * sin(p->j.a * M_PI / 180));
		if (x >= 0 && y >= 0 && x < p->map.x && y < p->map.y &&
			(p->map.map[y][x] == 1 || p->map.map[y][x] == 5) &&
			(p->j.item == 1 || p->j.item == 3) && p->j.a_item == 2)
		{
			FMOD_System_PlaySound(p->s.system, p->s.wall_fall, NULL, 0, NULL);
			p->map.map[(int)floor(y)][(int)floor(x)] = 0;
			p->tm -= 5;
		}
		else if (x >= 0 && y >= 0 &&
			x < p->map.x && y < p->map.y && p->map.map[y][x] == 3 &&
			(p->j.item == 2 || p->j.item == 3) && p->j.a_item == 1)
		{
			FMOD_System_PlaySound(p->s.system, p->s.wash, NULL, 0, NULL);
			p->map.map[(int)floor(y)][(int)floor(x)] = 5;
			p->clean_tag++;
			if (p->clean_tag == p->tags)
				p->exitkey = 1;
		}
	}
	return (0);
}

int			mouse_hook(int x, int y, t_param *p)
{
	if (!p->pos_x)
	{
		p->pos_x = abs(x);
		p->pos_y = abs(y);
	}
	if (abs(x - p->lx) > 100 || abs(y - p->ly) > 100)
	{
		p->lx = x;
		p->ly = y;
		return (0);
	}
	if (x < p->lx)
		p->j.a -= 2.5;
	if (x > p->lx)
		p->j.a += 2.5;
	if (y < p->ly && p->vy < SCREEN_Y * 2)
		p->vy += 20;
	if (y > p->ly && p->vy > -SCREEN_Y)
		p->vy -= 20;
	if (x <= 5 || x >= SCREEN_X - 5 || y <= 5 || y >= SCREEN_Y - 5)
		CGWarpMouseCursorPosition(
		CGPointMake(SCREEN_X / 2 + p->pos_x, SCREEN_Y / 2 + p->pos_y));
	p->lx = x;
	p->ly = y;
	return (0);
}

int			key_hook(int keycode, t_param *p)
{
	if (keycode == 53)
		ft_exit(p);
	key_hook_walls(keycode, p);
	if (keycode == 126 && p->menustate == 1)
	{
		if (p->cursorstate - 1 != 0)
			p->cursorstate--;
		else
			p->cursorstate = 3;
		FMOD_System_PlaySound(p->s.system, p->s.tic, NULL, 0, NULL);
	}
	if (keycode == 125 && p->menustate == 1)
	{
		if (p->cursorstate + 1 != 4)
			p->cursorstate++;
		else
			p->cursorstate = 1;
		FMOD_System_PlaySound(p->s.system, p->s.tic, NULL, 0, NULL);
	}
	key_hook_menu(keycode, p);
	return (0);
}

int			hook(t_param *p)
{
	static int	state = 1;
	static int	cfps = 0;

	cfps++;
	if (p->time != time(NULL) - p->tm)
	{
		p->time = time(NULL) - p->tm;
		p->fps = cfps;
		cfps = 0;
	}
	if (p->wy > SCREEN_Y * 0.535 && state == 1)
		state = -1;
	if (p->wy < SCREEN_Y * 0.465 && state == -1)
		state = 1;
	if (p->menustate == 0)
	{
		p->wy += state;
		p->wx += (double)state / 2;
		wolf3d(p);
	}
	ft_show_menu(p);
	return (0);
}
