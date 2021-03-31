/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbritni <wbritni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 22:28:53 by wbritni           #+#    #+#             */
/*   Updated: 2021/03/31 16:33:56 by wbritni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "libasm.h"
#include <stdlib.h>

int main(void)
{
    char    *str;
    char    dest[10];
    char    *str2;
    char    *buff;

    str = "abcd";
    str2 = "abcde";
    printf("%d\n", ft_strlen(str));
    printf("%s\n", str);
    printf("%s\n", dest);
    ft_strcpy(dest, str);
    printf("%s\n", dest);
    printf("%d\n", strcmp(str, str2));
    printf("%d\n", ft_strcmp(str, str2));
    write(1, "this is write\n", 14);
    ft_write(1, "this is write\n", 14);
    /*
    buff = (char *)calloc(10, sizeof(char));
    read(1, buff, 10);
    printf("%s is read\n", buff);
    bzero(buff, 10);
    ft_read(1, buff, 10);
    printf("%s is ft_read\n", buff);
    */
   buff = strdup(str2);
   printf("strdup - %s\n", buff);
   free(buff);
   buff = ft_strdup(str2);
   printf("ft_strdup - %s\n", buff);
   free(buff);
}