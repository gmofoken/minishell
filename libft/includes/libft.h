/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmofoken <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/01 12:12:07 by gmofoken          #+#    #+#             */
/*   Updated: 2016/08/12 20:43:09 by gmofoken         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>

void		ft_putnbr_fd(int n, int fd);
void		ft_putchar(char c);
void		ft_putnbr(int n);
void		ft_putstr(char *s);
void		ft_putstr_fd(char *s, int fd);
void		ft_putchar_fd(char c, int fd);
size_t		ft_strlen(const char *s);
void		ft_putendl(char const *s);
void		ft_putendl_fd(char const *s, int fd);
void		ft_strclr(char *s);
void		*ft_memset(void *s, int c, size_t len);
void		ft_bzero(void *s, size_t n);
void		*ft_memalloc(size_t size);
char		ft_toupper(char c);
char		ft_tolower(char c);
int			ft_isalpha(char c);
int			ft_isdigit(char c);
int			ft_isalnum(char c);
int			ft_isprint(char c);
int			ft_isascii(char c);
int			ft_strequ(char const *s1, char const *s2);
int			ft_strnequ(char const *s1, char const *s2, size_t n);
char		*ft_strsub(char const *s, unsigned int start, size_t len);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strnew(size_t size);
char		*ft_strtrim(char const *s);
char		*ft_strrev(char *s);
char		*ft_itoa(int n);
void		ft_striter(char	*s, void (*f)(char *));
void		ft_strdel(char **as);
char		*ft_strcpy(char *dest, const char *src);
char		*ft_strncpy(char *dest, const char *src, size_t n);
char		*ft_strchr(const char *s, int c);
char		*ft_strrchr(const char *s, int c);
char		*ft_strstr(const char *haystack, const char *needle);
int			ft_strcmp(const char *s1, const char *s2);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*ft_strcat(char *dest, const char *src);
char		*ft_strdup(char const *s);
char		*ft_strncat(char *restrict s1, char *restrict s2, size_t n);
void		ft_striteri(char *s, void (*f)(unsigned int, char *));
char		*ft_strmap(char const *s, void (*f)(char));
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void		ft_memdel(void **ap);
int			ft_atoi(const char *str);
char		**ft_strspli(char const *s, char c);
void		*ft_memcpy(void *restrict dst, const void *restrict src, size_t n);
void		*ft_memccpy(void *s1, const void *s2, int c, size_t n);
void		*ft_memmove(void *dst, const void *src, size_t len);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
void		*ft_memchr(const void *s, int c, size_t n);
char		*ft_strnstr(const char *big, const char *little, size_t len);
size_t		ft_strlcat(char *dst, const char *src,size_t size);
char		**ft_strsplit(char const *s, char c);
char		*ft_epur_str(const char *s);

#endif
