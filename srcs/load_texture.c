/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdelhomm <sdelhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 10:53:41 by sdelhomm          #+#    #+#             */
/*   Updated: 2018/03/20 14:04:20 by tgunzbur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	load_texture2(t_param *p)
{
	if (!(p->ptr_img = xpm_to_char(p->mlx, FILE_SERPI, &p->img_x, &p->img_y)))
		ft_error(-1, p);
	p->swall = mlx_get_data_addr(p->ptr_img, &p->sl, &p->end, &p->bpp);
	if (!(p->ptr_img = xpm_to_char(p->mlx, FILE_SERPI2, &p->img_x, &p->img_y)))
		ft_error(-1, p);
	p->swall2 = mlx_get_data_addr(p->ptr_img, &p->sl, &p->end, &p->bpp);
	if (!(p->ptr_img = xpm_to_char(p->mlx, FILE_WALL, &p->img_x, &p->img_y)))
		ft_error(-1, p);
	p->wall = mlx_get_data_addr(p->ptr_img, &p->sl, &p->end, &p->bpp);
	if (!(p->ptr_img = xpm_to_char(p->mlx, FILE_WEXIT, &p->img_x, &p->img_y)))
		ft_error(-1, p);
	p->wexit = mlx_get_data_addr(p->ptr_img, &p->sl, &p->end, &p->bpp);
	if (!(p->ptr_img = xpm_to_char(p->mlx, FILE_WEXIT2, &p->img_x, &p->img_y)))
		ft_error(-1, p);
	p->wexit2 = mlx_get_data_addr(p->ptr_img, &p->sl, &p->end, &p->bpp);
	if (!(p->ptr_img = xpm_to_char(p->mlx, FILE_SPIKES, &p->img_x, &p->img_y)))
		ft_error(-1, p);
	p->spike = mlx_get_data_addr(p->ptr_img, &p->sl, &p->end, &p->bpp);
}

void	load_texture(t_param *p)
{
	if (!(p->ptr_img = xpm_to_char(p->mlx, FILE_NORTH, &p->img_x, &p->img_y)))
		ft_error(-1, p);
	p->north = mlx_get_data_addr(p->ptr_img, &p->sl, &p->end, &p->bpp);
	if (!(p->ptr_img = xpm_to_char(p->mlx, FILE_SOUTH, &p->img_x, &p->img_y)))
		ft_error(-1, p);
	p->south = mlx_get_data_addr(p->ptr_img, &p->sl, &p->end, &p->bpp);
	if (!(p->ptr_img = xpm_to_char(p->mlx, FILE_WEST, &p->img_x, &p->img_y)))
		ft_error(-1, p);
	p->west = mlx_get_data_addr(p->ptr_img, &p->sl, &p->end, &p->bpp);
	if (!(p->ptr_img = xpm_to_char(p->mlx, FILE_EAST, &p->img_x, &p->img_y)))
		ft_error(-1, p);
	p->east = mlx_get_data_addr(p->ptr_img, &p->sl, &p->end, &p->bpp);
	if (!(p->ptr_img = xpm_to_char(p->mlx, FILE_TAG, &p->img_x, &p->img_y)))
		ft_error(-1, p);
	p->tag = mlx_get_data_addr(p->ptr_img, &p->sl, &p->end, &p->bpp);
	if (!(p->ptr_img = xpm_to_char(p->mlx, FILE_HWALL, &p->img_x, &p->img_y)))
		ft_error(-1, p);
	p->hwall = mlx_get_data_addr(p->ptr_img, &p->sl, &p->end, &p->bpp);
	if (!(p->ptr_img = xpm_to_char(p->mlx, FILE_HWALL2, &p->img_x, &p->img_y)))
		ft_error(-1, p);
	p->hwall2 = mlx_get_data_addr(p->ptr_img, &p->sl, &p->end, &p->bpp);
	if (!(p->ptr_img = xpm_to_char(p->mlx, FILE_HWALL3, &p->img_x, &p->img_y)))
		ft_error(-1, p);
	p->hwall3 = mlx_get_data_addr(p->ptr_img, &p->sl, &p->end, &p->bpp);
	load_texture2(p);
}
