/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libasm.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbritni <wbritni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 23:13:21 by wbritni           #+#    #+#             */
/*   Updated: 2021/03/31 15:18:27 by wbritni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBASM_H
# define LIBASM_H
# include <unistd.h>

int     ft_strlen(const char *str);
char    *ft_strcpy(char *dest, const char *src);
int     ft_strcmp (const char *str1, const char *str2);
ssize_t ft_write(int fd, const void *buf, size_t count);
ssize_t ft_read(int fd, void *buf, size_t count);
char    *ft_strdup(const char *s);

#endif