/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasalced <lasalced@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/26 22:57:07 by lasalced          #+#    #+#             */
/*   Updated: 2015/12/12 18:01:14 by lasalced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include "libft/libft.h"
#include <stdlib.h>

t_token	*init_map(int y, int x)
{
	t_token	*smap;
	int		i;

	i = 0;
	smap = (t_token *)malloc(sizeof(t_token));
	smap->y = y;
	smap->x = x;
	smap->cx = 0;
	smap->cy = 0;
	smap->token = (char **)malloc(sizeof(char *) * (y + 1));
	while (i < y)
	{
		smap->token[i] = ft_strnew(x);
		i++;
	}
	smap->token[i] = NULL;
	return (smap);
}

int		get_number(char *str)
{
	int	result;

	result = 0;
	while (*str > 47 && *str < 58)
	{
		result = result * 10;
		result = result + (*str - '0');
		str++;
	}
	return (result);
}

int		get_token_lines(char *str)
{
	while (*str != ' ')
		str++;
	str++;
	return (get_number(str));
}

int		get_token_cols(char *str)
{
	while (*str != ' ')
		str++;
	str++;
	while (*str != ' ')
		str++;
	str++;
	return (get_number(str));
}

char	*get_map_line(char *str)
{
	while (*str != ' ')
		str++;
	str++;
	return (str);
}
