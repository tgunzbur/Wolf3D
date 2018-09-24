/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdelhomm <sdelhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 17:52:38 by sdelhomm          #+#    #+#             */
/*   Updated: 2018/03/20 14:04:34 by tgunzbur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# define SCREEN_X 1280
# define SCREEN_Y 900
# define CEIL 1
# define FLOOR 2
# define W 3
# define NORTH 4
# define SOUTH 5
# define WEST 6
# define EAST 7
# define END 10
# define HAMMER_WALL 12
# define SERPI 13
# define WALL 14
# define TAG 15
# define SPIKE 16
# define HB 0.3

# define FILE_NORTH "texture/Assembly.xpm"
# define FILE_SOUTH "texture/Evilmacs.xpm"
# define FILE_WEST "texture/Winanzi.xpm"
# define FILE_EAST "texture/niel_wall.xpm"
# define FILE_TAG "texture/Tag.xpm"
# define FILE_HAMMER "texture/fps_hammer.xpm"
# define FILE_HWALL "texture/hammer.xpm"
# define FILE_HWALL2 "texture/hammer2.xpm"
# define FILE_HWALL3 "texture/hammer3.xpm"
# define FILE_SERPI "texture/serpi_wall.xpm"
# define FILE_SERPI2 "texture/serpi_wall2.xpm"
# define FILE_WSERPI "texture/fps_serpi.xpm"
# define FILE_WALL "texture/Wall.xpm"
# define FILE_WEXIT "texture/end_door.xpm"
# define FILE_WEXIT2 "texture/o_end_door.xpm"
# define FILE_KEY "texture/key.xpm"
# define FILE_MENU "texture/menu.xpm"
# define FILE_TUTO "texture/tuto.xpm"
# define FILE_CURSOR "texture/cursor.xpm"
# define FILE_SPIKES "texture/spikes.xpm"
# define FILE_WIN "texture/win_screen.xpm"
# define FILE_LOSE "texture/die.xpm"
# define FILE_SLOT "texture/slot.xpm"
# define FILE_SLOT2 "texture/slot2.xpm"
# define FILE_SLOT_HAMMER "texture/slot_hammer.xpm"
# define FILE_SLOT_SERPI "texture/slot_serpi.xpm"

# define FILE_WASH "sounds/washing.wav"
# define FILE_APPLAUSE "sounds/applause.wav"
# define FILE_DOOR "sounds/door_open.wav"
# define FILE_GLASS "sounds/glass_break.wav"
# define FILE_GRAB "sounds/grab.wav"
# define FILE_PIANO "sounds/lose.wav"
# define FILE_SPIKES_S "sounds/spikes_sound.wav"
# define FILE_WALL_FALL "sounds/wall_fall.wav"
# define FILE_TIC "sounds/tic.wav"
# define FILE_WRONG "sounds/wrong.wav"

# include "../libft/includes/libft.h"
# include <mlx.h>
# include <math.h>
# include <ApplicationServices/ApplicationServices.h>
# include <time.h>
# include "fmod/fmod.h"

typedef struct	s_player
{
	double	x;
	double	y;
	double	a;
	int		item;
	int		a_item;
}				t_player;

typedef struct	s_map
{
	int		x;
	int		y;
	int		**map;
}				t_map;

typedef struct	s_son
{
	FMOD_SYSTEM	*system;
	FMOD_SOUND	*wash;
	FMOD_SOUND	*applause;
	FMOD_SOUND	*door_open;
	FMOD_SOUND	*glass_break;
	FMOD_SOUND	*grab;
	FMOD_SOUND	*piano;
	FMOD_SOUND	*spikes_sound;
	FMOD_SOUND	*wall_fall;
	FMOD_SOUND	*tic;
	FMOD_SOUND	*wrong;
}				t_son;

typedef struct	s_param
{
	void		*mlx;
	void		*win;
	void		*ptr_img;
	void		*ptr_weap;
	void		*ptr_weap2;
	void		*ptr_key;
	void		*ptr_menu;
	void		*ptr_tuto;
	void		*ptr_cursor;
	void		*ptr_s_win;
	void		*ptr_lose;
	void		*ptr_slot;
	void		*ptr_slot_hammer;
	void		*ptr_slot_serpi;
	void		*ptr_slot2;
	char		*img;
	int			bpp;
	int			sl;
	int			end;
	double		pos;
	int			dir;
	char		*north;
	char		*south;
	char		*west;
	char		*east;
	char		*tag;
	char		*wall;
	char		*hwall;
	char		*hwall2;
	char		*hwall3;
	char		*swall;
	char		*swall2;
	char		*wexit;
	char		*wexit2;
	char		*spike;
	int			cursorstate;
	int			menustate;
	int			wexitstate;
	int			hwallstate;
	int			exitkey;
	int			img_x;
	int			img_y;
	int			img_x2;
	int			img_y2;
	int			img_x3;
	int			img_y3;
	t_player	j;
	t_map		map;
	t_son		s;
	int			pos_x;
	int			pos_y;
	float		vy;
	int			lx;
	int			ly;
	double		wx;
	double		wy;
	double		ry;
	double		rx;
	int			tm;
	int			fps;
	int			time;
	char		*arg1;
	int			clean_tag;
	int			tags;
	int			win_time;
}				t_param;

int				get_map(char *file, t_map *map, t_player *j, t_param *p);
t_map			*map_len(char *file, t_map *map);
int				wolf3d(t_param *p);
int				key_hook(int keycode, t_param *p);
int				mouse_hook(int x, int y, t_param *p);
int				draw_pixel(int x, int y, t_param *p, int color);
int				copy_pixel(int x, int y, int y_img, t_param *p);
int				hook(t_param *p);
int				events_mouse(int bc, int x, int y, t_param *p);
int				ft_exit(t_param *p);
int				ft_show_menu(t_param *p);
int				ft_death(t_param *p);
int				ft_win(t_param *p);
int				free_map(t_map map);
t_param			init(t_param p);
void			ft_init(t_param *p);
void			ft_error(int n, t_param *p);
int				check_spike(t_param *p, t_map map);
int				check_collision(int kc, t_param *p, t_map map);
void			key_hook_walls(int keycode, t_param *p);
void			key_hook_menu(int keycode, t_param *p);
void			draw_column(double d, t_param *p, int x);
void			load_texture2(t_param *p);
void			load_texture(t_param *p);
void			*xpm_to_char(void *mlx, char *file, int *x, int *y);

#endif
