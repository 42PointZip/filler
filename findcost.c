/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findcost.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasalced <lasalced@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/12 17:18:50 by lasalced          #+#    #+#             */
/*   Updated: 2016/01/26 13:43:19 by lasalced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "filler.h"

int		ft_abs(int num)
{
	if (num < 0)
		return (num * -1);
	return (num);
}

int		dist_vector(int y, int x, t_play *play)
{
	int	dist;
	int	i;
	int	j;

	i = -1;
	j = -1;
	dist = 999999;
	while (++j < play->y)
	{
		while (++i < play->x)
		{
			if (play->map_cost[j][i] == -1)
			{
				if ((ft_abs(y - j) + ft_abs(x - i)) < dist)
					dist = ft_abs(y - j) + ft_abs(x - i);
			}
		}
		i = -1;
	}
	return (dist);
}

int		pcost(t_play *r, t_token *map, t_token *token)
{
	char	mf;
	char	tf;
	int		find;

	find = 0;
	while (token->token[token->cy])
	{
		while (token->token[token->cy][token->cx])
		{
			mf = map->token[map->cy + token->cy][map->cx + token->cx];
			tf = token->token[token->cy][token->cx];
			if ((mf == r->player || mf == r->player + 48) && tf == '*')
				find = 1;
			else if (mf == '.' && tf == '*')
				r->cost += 1;
			else if ((mf == r->ia || mf == r->ia + 48) && tf == '*')
				return (-1);
			token->cx++;
		}
		token->cx = 0;
		token->cy++;
	}
	if (find == 0)
		return (0);
	return (r->cost);
}

t_play	*placement_cost(t_token *map, t_token *token, char player)
{
	t_play	*play_map;

	play_map = init_resolve(map->x, map->y, token->x * token->y, player);
	while (map->token[map->cy])
	{
		while (map->token[map->cy][map->cx])
		{
			token->cy = 0;
			token->cx = 0;
			play_map->cost = 0;
			if (!out_limit(map, token))
				play_map->cost = pcost(play_map, map, token);
			play_map->map_cost[map->cy][map->cx] = play_map->cost;
			map->cx++;
		}
		map->cx = 0;
		map->cy++;
	}
	return (play_map);
}
