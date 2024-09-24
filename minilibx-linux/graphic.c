/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenquin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 16:00:06 by drenquin          #+#    #+#             */
/*   Updated: 2024/06/06 16:00:10 by drenquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx-linux/mlx.h"
#include "minilibx-linux/mlx_int.h"
#include <stdlib.h>

#define MALLOC_ERROR 1
#define WIDTH   400
#define HEIGHT  400

int main()
{
    void *mlx_connection;
    void *mlx_window;
    char *title;

    title = "fract-ol";
    //initialisation avant d' utiliser la minilibx qui contient un malloc.
    mlx_connection = mlx_init();
    if (NULL == mlx_connection)
        return(MALLOC_ERROR);
    
    /*intitialisation de la fenetre a besoin de mlx connection et
    efectue aussi un malloc*/
    mlx_window = mlx_new_window(mlx_connection, HEIGHT, WIDTH, title);
    if (NULL == mlx_window)
    {
        mlx_destroy_display(mlx_connection); //clean up mlx connection
        free(mlx_connection);
        return (MALLOC_ERROR);
    }

    //boucle qui maintien la fenetre ouverte
    mlx_loop(mlx_connection); 
}
