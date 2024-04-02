/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ^@^ Foxan ^@^ <thibaut.unsinger@gmail.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 13:50:26 by ^@^ Foxan ^@^     #+#    #+#             */
/*   Updated: 2022/11/10 13:50:27 by ^@^ Foxan ^@^    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static t_store	store = {0, BUFFER_SIZE, BUFFER_SIZE, 0, 0, {}};
	char			*line;
	int				n;
	int				e;
	char			*ret;

	store.fd = fd;
	line = NULL;
	n = reset_buffer(&store);
	if (n == 0 || n == -1)
		return (NULL);
	store.start = store.pos;
	while (store.buff[store.pos] != '\n' && store.max)
	{
		store.pos++;
		ret = verify(&line, n, &e, &store);
		if (e == 1)
			return (ret);
	}
	store.end = store.pos;
	line = save_line(&store, line);
	store.pos += (line != NULL);
	return (line);
}

int	reset_buffer(t_store *store)
{
	if (store->pos >= store->max)
	{
		store->pos = 0;
		store->max = read(store->fd, &store->buff, BUFFER_SIZE);
		if (store->max == 0)
			return (0);
		if (store->max == -1)
			return (-1);
	}
	return (store->max);
}

char	*save_line(t_store *st, char *line)
{
	char	*tmp;
	int		len;

	if (line == NULL)
	{
		len = st->end - st->start + (st->pos < st->max);
		tmp = malloc((len + 1) * sizeof(char));
		if (tmp == NULL)
			return (NULL);
		ft_strlcpy(&(st->buff[st->start]), tmp, len);
	}
	else
	{
		len = ft_strlen(line) + st->end - st->start + (st->pos < st->max);
		tmp = malloc((len + 1) * sizeof(char));
		if (tmp == NULL)
		{
			free(line);
			return (NULL);
		}
		ft_strlcpy(line, tmp, ft_strlen(line));
		ft_strlcat(&(st->buff[st->start]), tmp, len + 1);
		free(line);
	}
	return (tmp);
}

char	*verify(char **line, int n, int *e, t_store *store)
{
	*e = 0;
	if (store->pos >= store->max)
	{
		store->end = store->pos;
		*line = save_line(store, *line);
		n = reset_buffer(store);
		if (*line == NULL)
		{
			*e = 1;
			return (NULL);
		}
		if (n == 0)
		{
			*e = 1;
			return (*line);
		}
		if (n == -1)
		{
			*e = 1;
			free(*line);
			return (NULL);
		}
		store->start = store->pos;
	}
	return (NULL);
}
