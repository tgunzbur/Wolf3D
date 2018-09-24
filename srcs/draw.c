/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdelhomm <sdelhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 12:26:54 by tgunzbur          #+#    #+#             */
/*   Updated: 2018/03/20 13:35:37 by tgunzbur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

int		draw_pixel(int x, int y, t_param *p, int color)
{
	int		pos;

	if (x < 0 || y < 0 || x > SCREEN_X || y > SCREEN_Y)
		return (-1);
	pos = x * 4 + y * 4 * SCREEN_X;
	if (color == FLOOR)
	{
		p->img[pos] = (char)125;
		p->img[pos + 1] = (char)125;
		p->img[pos + 2] = (char)125;
	}
	if (color == CEIL)
	{
		p->img[pos] = (char)255;
		p->img[pos + 1] = (char)125;
		p->img[pos + 2] = (char)125;
	}
	return (0);
}

int		copy_pixel(int x, int y, int y_img, t_param *p)
{
	char	*img;
	int		pos;
	int		pos_img;

	if (x < 0 || y < 0 || x > SCREEN_X || y > SCREEN_Y || y_img < 0 ||
			(int)p->pos < 0 || (int)p->pos > p->img_x || y_img > p->img_y)
		return (-1);
	img = (p->dir == NORTH ? p->north : NULL);
	img = (p->dir == SOUTH ? p->south : img);
	img = (p->dir == EAST ? p->east : img);
	img = (p->dir == WEST ? p->west : img);
	img = (p->dir == HAMMER_WALL ? p->hwall : img);
	img = (p->dir == TAG ? p->tag : img);
	img = (p->dir == SERPI ? p->swall : img);
	img = (p->dir == WALL ? p->wall : img);
	img = (p->dir == END ? p->wexit : img);
	img = (p->dir == SPIKE ? p->spike : img);
	pos = x * 4 + y * 4 * SCREEN_X;
	pos_img = (int)p->pos * 4 + y_img * 4 * p->img_x;
	p->img[pos] = img[pos_img];
	p->img[pos + 1] = img[pos_img + 1];
	p->img[pos + 2] = img[pos_img + 2];
	p->img[pos + 3] = img[pos_img + 3];
	return (0);
}

void	draw_column(double d, t_param *p, int x)
{
	int		y;
	double	y_img;

	d = SCREEN_Y / d;
	y = (floor(p->vy - d / 2) < 0 ? floor(p->vy - d / 2) : 0);
	while (y < floor(p->vy - d / 2))
		draw_pixel(x, y++, p, CEIL);
	y_img = 0;
	p->pos = p->pos * (double)p->img_x;
	while (y < SCREEN_Y && y < floor(p->vy + d / 2))
	{
		copy_pixel(x, y++, (int)floor(y_img), p);
		y_img += (p->img_y / d);
	}
	while (y < SCREEN_Y)
		draw_pixel(x, y++, p, FLOOR);
}
