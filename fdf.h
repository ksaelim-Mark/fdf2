/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaelim <ksaelim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 13:03:39 by ksaelim           #+#    #+#             */
/*   Updated: 2023/04/20 18:25:39 by ksaelim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include "mlx_linux/mlx.h"
#include "libft/libft.h"
#include "get_next_line/get_next_line.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

typedef struct	s_node
{
	int x;
	int y;
	int z;
}   t_node;

typedef struct	s_img
{
	void	*img;
	char	*addr;
	int	bpp;
	int	line;
	int	endian;
}	t_img;

typedef struct	s_map
{
	int	width;
	int	height;
	int	cell;
	int	set_x;
	int	set_y;
	int	scale;
}	t_map;

typedef struct	s_data
{
	void	*mlx;
	void	*win;
	t_node	*node;
	t_img	img;
	t_map	map;
	int	i;
	int	j;
	int	k;
	int	fd;
	char	**tmp;
	char	*line;
}	t_data;


void    input_map(int ac, char **av, t_data *data);
void    create_img(t_data *data);
void	ft_read_img(char **av, t_data *data);
void    ft_get_width(char **av, t_data *data);
void    ft_get_height(char **av, t_data *data);
void    free_exit(t_data *data);

#endif
