/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilitaire.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasalced <lasalced@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/26 22:59:24 by lasalced          #+#    #+#             */
/*   Updated: 2015/12/12 17:43:29 by lasalced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include "libft/libft.h"
#include <stdlib.h>

int		out_limit(t_token *map, t_token *token)
{
	if (map->cx + token->x > map->x \
		|| map->cy + token->y > map->y)
		return (1);
	return (0);
}

int		*ft_strfillint(int num, int lenght)
{
	int		*str;
	int		i;

	i = 0;
	str = (int *)malloc(sizeof(int) * lenght);
	while (i < lenght)
	{
		str[i] = num;
		i++;
	}
	return (str);
}

t_play	*init_resolve(int x, int y, int max_cost, char player)
{
	t_play	*play_map;
	int		i;

	play_map = (t_play*)malloc(sizeof(t_play));
	play_map->max_cost = max_cost;
	play_map->cost = 0;
	play_map->map_cost = (int **)malloc(sizeof(int *) * y);
	play_map->x = x;
	play_map->y = y;
	play_map->max_select = -1;
	play_map->far_ia = 999999;
	i = -1;
	if (player == 'X')
	{
		play_map->player = 'X';
		play_map->ia = 'O';
	}
	else
	{
		play_map->player = 'O';
		play_map->ia = 'X';
	}
	while (++i < y)
		play_map->map_cost[i] = ft_strfillint(0, x);
	return (play_map);
}
