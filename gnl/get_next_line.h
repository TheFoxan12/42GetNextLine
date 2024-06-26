/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ^@^ Foxan ^@^ <thibaut.unsinger@gmail.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 11:33:15 by ^@^ Foxan ^@^     #+#    #+#             */
/*   Updated: 2022/11/10 11:33:17 by ^@^ Foxan ^@^    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
# include <unistd.h>
# include <stdlib.h>

typedef struct s_store {
	int		fd;
	int		pos;
	int		max;
	int		start;
	int		end;
	char	buff[BUFFER_SIZE];
}	t_store;

char			*get_next_line(int fd);
int				reset_buffer(t_store *store);
int				ft_strlen(const char *str);
char			*ft_strlcpy(const char *src, char *dst, int n);
unsigned int	ft_strlcat(const char *src, char *dst, unsigned int dstsize);
char			*save_line(t_store *st, char *line);
char			*verify(char **line, int n, int *e, t_store *store);

#endif //GET_NEXT_LINE_H
