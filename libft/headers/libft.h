/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabre <msabre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 21:05:20 by msabre            #+#    #+#             */
/*   Updated: 2020/02/29 14:04:32 by msabre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIBFT_H
# define FT_LIBFT_H
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <limits.h>
# include <ncurses.h>
# include <locale.h>
# include "ft_printf.h"
# include "get_next_line.h"

void					*ft_memset(void *b, int c, size_t len);
void					ft_bzero(void *s, size_t n);
void					*ft_memcpy(void *restrict dst,
						const void *restrict src, size_t n);
void					*ft_memccpy(void *restrict dst,
						const void *restrict src, int c, size_t n);
void					*ft_memmove(void *dst, const void *src, size_t len);
void					*ft_memchr(const void *s, int c, size_t n);
int						ft_memcmp(const void *s1, const void *s2, size_t n);
size_t					ft_strlen(const char *s);
char					*ft_strdup(const char *s1);
char					*ft_strcpy(char *dst, const char *src);
char					*ft_strncpy(char *dst, const char *src, size_t len);
char					*ft_strcat(char *restrict s1,
						const char *restrict s2);
char					*ft_strncat(char *restrict s1,
						const char *restrict s2, size_t n);
size_t					ft_strlcat(char *restrict dst, const char *restrict src,
						size_t size);
char					*ft_strchr(const char *s, int c);
char					*ft_strrchr(const char *s,
						int c);
char					*ft_strstr(const char *haystack,
						const char *needle);
char					*ft_strnstr(const char *haystack,
						const char *needle, size_t len);
int						ft_strcmp(const char *s1, const char *s2);
int						ft_strncmp(const char *s1, const char *s2, size_t n);
signed long long int	ft_atoi(const char *str);
int						ft_isalpha(int c);
int						ft_isdigit(int c);
int						ft_isalnum(int c);
int						ft_isascii(int c);
int						ft_isprint(int c);
int						ft_toupper(int c);
int						ft_tolower(int c);
void					*ft_memalloc(size_t size);
void					ft_memdel(void **ap);
char					*ft_strnew(size_t size);
void					ft_strdel(char **as);
void					ft_strclr(char *s);
void					ft_striter(char *s, void (*f)(char *));
void					ft_striteri(char *s, void (*f)(unsigned int, char *));
char					*ft_strmap(char const *s, char (*f)(char));
char					*ft_strmapi(char const *s,
						char (*f)(unsigned int, char));
int						ft_strequ(char const *s1, char const *s2);
int						ft_strnequ(char const *s1, char const *s2,
						size_t n);
char					*ft_strsub(char const *s, unsigned int start,
						size_t len);
char					*ft_strjoin(char const *s1, char const *s2);
char					*ft_strtrim(char const *s);
char					**ft_strsplit(char const *s, char c);
char					*ft_itoa(long long n);
void					ft_putchar(char c);
void					ft_putstr(char const *s);
void					ft_putendl(char const *s);
int						ft_putnbr(long long n, int count);
void					ft_putchar_fd(char c, int fd);
void					ft_putstr_fd(char const *s, int fd);
void					ft_putendl_fd(char const *s, int fd);
void					ft_putnbr_fd(int n, int fd);
int						*creat_int_mass(int size);
int						integer_size(unsigned long long num);
void					*free_doub_lvl_mass(void **mas);
void					zero_doub_lvl_mass(void **mass, int size);
int						ft_isnum(char c, int exception);
int						size_int_mass(int *a);
int						mod_plus(int a, int b);
int						mod_minus(int a, int b);
int						mod_compair(int a, int b);
char					*ft_strndup(const char *str, int start, int end);
void					ft_swap(int *stack, int l, int r);
void					quick_sort(int *stack, int l, int r);
void					ft_chrfill(char *str, char c, int count);
int						cn_power(int num);
unsigned long long		to_power(unsigned long long a, int power);
int						*ft_digitmass_cpy(int *stack, int size);
int						word_len(char const *str, char c);
int						count_words(char const *s, char c);
int						count_row(void **mass);
void					cpy_double_lvl_mass(void **arr1, void **arr2, int size);
void					str_qsorts(char **array, int l, int r);
void					ft_memswap(void **array, int i, int j);
int						is_num(char c);
int						is_numvalue(char *str);
int						skip_word(char *str, int in, int count);

#endif
