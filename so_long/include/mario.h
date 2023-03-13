/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mario.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenaiss <rbenaiss@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 17:47:37 by rbenaiss          #+#    #+#             */
/*   Updated: 2023/03/13 13:16:02 by rbenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MARIO_H
# define MARIO_H

# include <stdlib.h>
# include "../printf/includes/ft_printf.h"
# include "../libft/libft.h"
# include <fcntl.h>
# include <mlx.h>


typedef struct s_mario
{
        void    *id;
        void    *window;
        char    **map;
        char    *file;
        char    *orientation;
        int     player;
        int     map_area;
        int     map_x;
        int     map_y;
        int     x;
        int     y;
        int     player_x;
        int     player_y;
        int     pixel;
        int     moove;
        int     points;
        int     exit;
        int     point_way;
        int     exit_way;
        int     char_invalid;
}       t_game;

void    initialize(t_game *game);
void    check_arg(int argc, char **argv);
void    map(char **argv, t_game *game);
void    window(t_game *game);
char    *get_map(int fd);
int     check_line(char *line);
char    *ft_join(char *line, char c);
void    check_char(char *buf, t_game *game);
void    check_map(char *buf, t_game *game);
void    check_limits(t_game *game);
void    check_sides_limits(t_game *game);
void    check_upDown_limits(t_game *game);
char    *ft_join(char *line, char c);
void    check_way(t_game *game);
void    good_way(int y, int x, t_game *game);
void    split_plus(char *str, char **ptr, char c);
void    free_2D(char **ptr, int i);
void    window(t_game *game);
void    fill(t_game *game);
int     score_max(t_game *game);
void    fill_background(t_game *game);
void    put_image_to_window(t_game *game, char *path);
void    put_limits(t_game *game);
void    put_floor(t_game *game);
void    put_points(t_game *game);
void    put_player(t_game *game);
void    put_exit(t_game *game);
void    close_window(t_game *game);
int     keyboard(int keyhook, t_game *game);
void    haut(t_game *game);
void    bas(t_game *game);
void    gauche(t_game *game);
void    droite(t_game *game);

#endif 
