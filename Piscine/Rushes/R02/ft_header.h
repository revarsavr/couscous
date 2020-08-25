/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_header.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daarriba <daarriba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 11:17:34 by daarriba          #+#    #+#             */
/*   Updated: 2020/02/23 20:25:33 by daarriba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HEADER_H
# define FT_HEADER_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct	s_chunk
{
	char	*t;
	int		u;
}				t_chunk;

t_chunk			*ft_chunks(char *s);
int				ft_put_prefix(char *s, char *d);
void			ft_powstr(int i, char *d);
void			ft_write_two(char *s, char *d);
void			ft_put_chunk(char *s, char *d);
void			ft_check_open(int fd);
char			*ft_load(char *path);
int				ft_search(char *s, char *path);
int				ft_strlen(char *s);
int				ft_strncmp(char *s1, char *s2, unsigned int n);
char			*ft_strstr(char *str, char *to_find);
void			ft_write_nbr(char *s, char *d);
int				ft_is_zero(char *s);
int				ft_check(char *s);
int				ft_str_is_printable(char *str);

#endif
