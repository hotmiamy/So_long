/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 17:12:28 by llopes-n          #+#    #+#             */
/*   Updated: 2022/01/19 02:33:13 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# ifndef OPEN_MAX
#  define OPEN_MAX 256
# endif

# define INT_MIN -2147483648
# define INT_MAX 2147483647

int		ft_isalpha(int c);
int		ft_isalnum(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
size_t	ft_strlen(const char *str);
size_t	ft_strlcpy(char *dest, const char *src, size_t destsize);
size_t	ft_strlcat(char *dest, const char *src, size_t n);
void	*ft_memset(void *dest, int c, size_t len);
void	ft_bzero(void *b, size_t lenght);
void	*ft_memmove(void *dest, const void *src, size_t len);
void	*ft_memcpy(void *dst, const void *src, size_t len);
int		ft_toupper(int c);
int		ft_tolower(int c);
char	*ft_strchr(const char *string, int c);
char	*ft_strrchr(const char *string, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t len);
void	*ft_memchr(const void *byte, int chr, size_t len);
int		ft_memcmp(const void *byte1, const void *byte2, size_t len);
char	*ft_strnstr(const char *bigStr, const char *littleStr, size_t len);
int		ft_atoi(const char *numstr);
void	*ft_calloc(size_t number, size_t size);
char	*ft_strdup(const char *str);
char	*ft_substr(char const *str, unsigned int start, size_t len);
char	*ft_strjoin(const char *str1, const char *str2);
char	*ft_strtrim(char const *str, char const *set);
char	**ft_split(char const *str, char chr);
char	*ft_itoa(int nbr);
char	*ft_strmapi(char const *str, char (*ft)(unsigned int, char));
void	ft_striteri(char *str, void (*ft)(unsigned int, char*));
void	ft_putchar_fd(char chr, int fd);
void	ft_putendl_fd(char *str, int fd);
void	ft_putnbr_fd(int nbr, int fd);
void	ft_putstr_fd(char *str, int fd);
char	*ft_base_converter(unsigned long nbr, char *base);
char	*ft_uitoa(unsigned int nbr);
char	*ft_get_next_line(int fd);

#endif
