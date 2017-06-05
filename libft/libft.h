/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpachy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 14:42:42 by hpachy            #+#    #+#             */
/*   Updated: 2016/11/07 14:42:44 by hpachy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <string.h>
# include <stdint.h>

typedef	struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

char				*ft_strcat(char *s1, const char *s2);
size_t				ft_strlen(const char *s);
char				*ft_strcpy(char *dst, const char *src);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strdup(const char *s1);
void				ft_putchar(char c);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strncat(char *restrict s1,
					const char *restrict s2, size_t n);
int					ft_atoi(const char *str);
int					ft_search_char(char *str);
void				ft_add_end(t_list **begin_list, t_list *new);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
char				*ft_toupper(char *str);
int					ft_tolower(int c);
char				*ft_itoa_base(uintmax_t nb, int base);
int					get_next_line(const int fd, char **line);
char				*ft_strstr(const char *big, const char *little);
char				*ft_strnstr(const char *big, const char *little,
					size_t len);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *restrict dst, const void *restrict src,
					size_t n);
void				*ft_memccpy(void *restrict dst, const void *restrict src,
					int c, size_t n);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);
void				ft_putstr(char const *s);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				ft_putchar_fd(char c, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char(*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
char				*ft_itoa(int n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				ft_putstr_fd(char const *s, int fd);
size_t				ft_strlcat(char *restrict dst, const char *restrict src,
					size_t size);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
int					ft_intlen(intmax_t c, int base);
char				*ft_isspace(char *c);
char				*ft_c_strnew(int size, char c);
char				*ft_itoa_intmax_t(intmax_t nb);
char				*ft_itoa_long_long(long long int n);
char				*ft_itoa_long(long int n);
char				*ft_itoa_size(size_t n);
char				*ft_itoa_short(short int n);
char				*ft_itoa_signed_char(signed char n);
char				*ft_itoa_ulong_long(unsigned long long nb, int base);
char				*ft_itoa_ulong(unsigned long nb, int base);
char				*ft_itoa_base_size(size_t nb, int base);
char				*ft_itoa_base_short(unsigned short int nb, int base);
char				*ft_itoa_base_uchar(unsigned char nb, int base);
int					ft_uintlen(uintmax_t c, int base);

#endif
