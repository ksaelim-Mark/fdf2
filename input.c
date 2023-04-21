/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaelim <ksaelim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 12:11:32 by ksaelim           #+#    #+#             */
/*   Updated: 2023/04/20 12:25:49by ksaelim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


void    free_2d(char **str)
{
    int i;

    i = 0;
    while (str[i])
        free(str[i++]);
    free(str);
}

void    free_exit(t_data *data)
{
    if (data->node)
        free(data->node);
    free(data->tmp);
}

void    ft_get_height(char **av, t_data *data)
{
    data->fd = open(av[1], O_RDONLY);
    if (data->fd == -1)
            exit(-1);
    while (1)
    {
        data->line = get_next_line(data->fd);
        if (!data->line)
            break;
        data->map.height++;
        free(data->line);
    }
    close(data->fd);
}

void    ft_get_width(char **av, t_data *data)
{
    data->i = 0;
    data->fd = open(av[1], O_RDONLY);
    if (data->fd == -1)
            exit(-1);
    data->line = get_next_line(data->fd);
    if (!data->line)
        return ;
    data->tmp = ft_split(data->line, ' ');
    if (!data->tmp)
        free_exit(data);
    while (data->tmp[data->i++])
        data->map.width++;
    free(data->line);
    free_2d(data->tmp);
    close(data->fd);
}

void    point_xyz(int row, t_data *data)
{
    data->j = 0;
    while (data->tmp[data->j])
    {
        data->node[data->i].z = (float)ft_atoi(data->tmp[data->j]);
        data->node[data->i].x = data->j * data->map.scale;
        data->node[data->i].y = data->k * data->map.scale;
        data->j++;
        data->i++;
    }
}

void    ft_read_img(char **av, t_data *data)
{
    ft_get_height(av, data);
    ft_get_width(av, data);
    data->map.cell = data->map.width * data->map.height;
    data->node = malloc(sizeof(t_node) * data->map.cell);
    if (!data->node)
        exit(0);
    printf("width: %d , height: %d\n", data->map.width, data->map.height);
}

void    create_img(t_data *data)
{
    data->mlx = mlx_init();
    data->win = mlx_new_window(data->mlx, 1920, 1080, "fdf ja!");
    data->img.img = mlx_new_image(data->mlx, 1920, 1080);
    data->img.addr = mlx_get_data_addr(data->img.img, &data->img.bpp, &data->img.line, &data->img.endian);
}

void    sketch_img(char **av, t_data *data)
{
    data->fd = open(av[1], O_RDONLY);
    if(data->fd == -1)
        exit(0);
    data->i = 0;
    data->j = 0;
    data->k = 0;
    data->map.scale = 25;
    while (data->i < data->map.cell)
    {
        data->line = get_next_line(data->fd);
        if (!data->line)
            return ;
        data->tmp = ft_split(data->line, ' ');
        point_xyz(data->k++, data);
        free_2d(data->tmp);
        free(data->line);
    }
    close(data->fd);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->img.addr + (y * data->img.line + x * (data->img.bpp / 8));
	*(unsigned int*)dst = color;
}

void    input_map(int ac, char **av, t_data *data)
{
    if (ac != 2)
        exit(0);
    create_img(data);
    ft_read_img(av, data);
    sketch_img(av, data);
    data->i = 0;
    while (data->i < data->map.cell)
    {
        printf("=================\n");
        //printf("pos: %d = (%d, %d) 3D: %d\n", data->i , data->node[data->i].x, data->node[data->i].y, data->node[data->i].z);
        //my_mlx_pixel_put(data->mlx , data->node[data->i].x, data->node[data->i].y, 0x00FF0000);
        my_mlx_pixel_put(data->mlx , data->node[data->i].x, data->node[data->i].y, 0x00FF0000);
        data->i++;
    }
    printf("==============\n");
    mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
    mlx_loop(data->mlx);
}
