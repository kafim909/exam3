/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_paint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtournay <mtournay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 16:50:54 by mtournay          #+#    #+#             */
/*   Updated: 2022/02/03 11:25:56 by mtournay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_paint.h"

int	free_all(t_var *v, int info, int index)
{
	int	i;

	i = 0;
	if (info)
		v->m.hgt = index;
	while (i < v->m.hgt)
	{
		free(v->m.map[i]);
		i++;
	}
	free(v->m.map);
	return (0);
}

int	init_map(t_var *v)
{
	int	i;

	i = 0;
	v->m.map = malloc(sizeof(char *) * v->m.hgt + 1);
	if (!v->m.map)
		return (0);
	while (i < v->m.hgt)
	{
		v->m.map[i] = malloc(sizeof(char) * v->m.wdth + 1);
		if (!v->m.map[i])
			return (free_all(v, 1, i));
		memset(v->m.map[i], v->m.c, v->m.hgt);
		v->m.map[i][v->m.wdth] = '\0';
		i++;
	}
	return (1);
}

int	get_info(t_map *m, FILE *fd)
{
	int	scan_ret;

	scan_ret = fscanf(fd, "%d %d %c", &m->wdth, &m->hgt, &m->c);
	if (scan_ret != 3)
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	t_var	v;
	FILE	*fd;
	int		i;

	i = 0;
	fd = fopen(argv[1], "r");
	if (!get_info(&v.m, fd))
	{
		write(1, "Error: Operation file corrupted\n", 32);
		return (1);
	}
	if (!init_map(&v))
	{
		return (1);
	}
	while (v.m.map[i])
	{
		printf("%s\n", v.m.map[i]);
		i++;
	}


	fclose(fd);
	return (free_all(&v, 0, 0));
}
