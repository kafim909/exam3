/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_paint.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtournay <mtournay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 16:47:55 by mtournay          #+#    #+#             */
/*   Updated: 2022/02/03 11:03:41 by mtournay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_PAINT_H
# define MINI_PAINT_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>


typedef struct s_full
{
    float   x;
    float   y;
    float   wdth;
    float   hgt;
    char    c;
}               t_full;

typedef struct s_empty
{
    float   x;
    float   y;
    float   wdth;
    float   hgt;
    char    c;
}               t_empty;

typedef struct s_map
{
    char    **map;
    int     wdth;
    int     hgt;
    char    c;
}               t_map;

typedef struct s_var
{
    t_map   m;
    t_full  f;
    t_empty e;
}          t_var;

#endif 