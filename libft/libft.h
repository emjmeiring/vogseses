/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomeirin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/15 16:32:34 by jomeirin          #+#    #+#             */
/*   Updated: 2016/05/15 17:49:35 by jomeirin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <libc.h>
typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

void				*ft_memset(void *str, int c, size_t n);
void				*ft_bzero(void *str, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t n);
void				*ft_memchr(const void *str, int c, size_t);
int					ft_memcmp(void *str1, void *str2, size_t n);
size_t				ft_strlen(const char *str);
char				*ft_strdup(const char *str);
char				*ft_strcpy(char *dest, const char *src);
char				*ft_strncpy(char *dest, const char *src, int n);
char				*ft_strcat(char *dest, const char *src);
char				*ft_strncat(char *dest, const char *src,size_t n);
size_t				ft_strlcat(char *dest, char *src, size_t n);
char				*ft_strchr(char *str, int c);
char				*ft_strrchar(char *str, int c);
char				*ft_strstr(char *hay,const char *needle);
char				*ft_strnstr(char *hay, char *needle, size_t n);
int					ft_strcmp(char *str1, char *str2);
int					ft_strncmp(char *str1, char *str2, size_t n);
int 				ft_atoi(const char *str);
int 				ft_isalpha(char c);
int 				ft_isdigit(int c);
int 				ft_isalnum(int c);
int 				ft_isascii(char c);
int 				ft_isprint(int c);
char 				*ft_toupper(char *str);
char 				*ft_tolower(char *str);
void				*ft_memalloc(size_t s);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t s);
void				ft_strdel(char **as);
void				ft_strclr(char* s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(const char *s, void (*f)(char));
int					ft_strequ(char const *s1, char const *s2);

#endif
