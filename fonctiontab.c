/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonctiontab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasalced <lasalced@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/26 22:58:23 by lasalced          #+#    #+#             */
/*   Updated: 2016/01/26 13:40:19 by lasalced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include "libft/libft.h"
#include <stdlib.h>
#include <unistd.h>

int		check(char *str, char *term)
{
	int	i;

	i = 0;
	while (term[i] && str[i])
	{
		if (str[i] != term[i])
			return (0);
		i++;
	}
	if (term[i])
		return (0);
	else
		return (1);
}

char	getplayer(char *line)
{
	if (line[10] == '1')
		return ('O');
	else
		return ('X');
}

t_token	*get_map(char **line)
{
	t_token	*smap;
	int		i;
	int		cut;

	i = 0;
	smap = init_map(get_token_lines(*line), get_token_cols(*line));
	get_next_line(0, line);
	while (i < smap->y)
	{
		cut = 0;
		get_next_line(0, line);
		while ((*line)[cut] != ' ')
			cut++;
		cut++;
		smap->token[i] = ft_strdup(ft_strsub(*line, cut, \
			ft_strlen(*line) - cut));
		i++;
	}
	smap->token[i] = NULL;
	return (smap);
}

t_token	*new_token(int y, int x)
{
	t_token *t;
	int		i;

	t = (t_token *)malloc(sizeof(t_token));
	t->y = y;
	t->x = x;
	t->cx = 0;
	t->cy = 0;
	t->token = (char **)malloc(sizeof(char *) * (y + 1));
	i = 0;
	while (i < y)
	{
		t->token[i] = ft_strnew(x);
		i++;
	}
	t->token[i] = NULL;
	return (t);
}

t_token	*get_token(char **line)
{
	t_token *token;
	int		i;

	token = new_token(get_token_lines(*line), get_token_cols(*line));
	i = 0;
	while (i < token->y)
	{
		get_next_line(0, line);
		token->token[i] = ft_strdup(*line);
		i++;
	}
	token->token[i] = NULL;
	return (token);
}
