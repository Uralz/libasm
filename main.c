/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbritni <wbritni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 22:28:53 by wbritni           #+#    #+#             */
/*   Updated: 2021/04/27 10:53:04 by wbritni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "libasm.h"
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>

int main(void)
{
    char    buff[100];
    int     fd;
    int     ret;

/*
** ft_write
*/
	printf("\n*******FT_WRITE*******\n--------------\n");
	printf("\ttry (1, \"test\\n\", 5)\n");
   
    errno = 0;
    ret = write(1, "test\n", 5);
    printf("write errno: %d\n", errno);
    printf("%s\n", strerror(errno));
    printf("write return: %d\n\n", ret);
    
    errno = 0;
    ret = ft_write(1, "test\n", 5);
    printf("ft_write errno: %d\n", errno);
    printf("%s\n", strerror(errno));
    printf("ft_write return: %d\n\n", ret);

	printf("\ttry (-1, \"test\\n\", 5)\n");
	errno = 0;
    ret = write(-1, "test\n", 5);
    printf("write errno: %d\n", errno);
    printf("%s\n", strerror(errno));
    printf("write return: %d\n\n", ret);

	errno = 0;
    ret = ft_write(-1, "test\n", 5);
    printf("ft_write errno: %d\n", errno);
    printf("%s\n", strerror(errno));
    printf("ft_write return: %d\n\n", ret);

/*
** FT_STRLEN
*/
	printf("*******FT_STRLEN*******\n--------------\n");
	printf("ft_strlen(\"abcdeabcdeabcdeabcdeabcdeabcde\") = %d\n", ft_strlen("abcdeabcdeabcdeabcdeabcdeabcde"));
	printf("ft_strlen(\"\") = %d\n\n", ft_strlen(""));

/*
** FT_STRCPY
*/
	printf("*******FT_STRCPY*******\n--------------\n");
	memset(buff, '\0', 100);
	memset(buff, '*', 10);
	printf("buff: %s\n", buff);
	printf("ft_strcpy(buff, \"\")\n");
	ft_strcpy(buff, "");
	printf("buff: %s\n", buff);
	printf("ft_strcpy(buff, \"012345678901234567890123456789012345678901234567890123456789\")\n");
	ft_strcpy(buff, "012345678901234567890123456789012345678901234567890123456789");
	printf("buff: %s\n\n", buff);

/*
** FT_STRCMP
*/
	printf("*******FT_STRCMP*******\n--------------\n");
	printf("ft_strcmp(\"abcd\", \"abcd\"): %d\n", ft_strcmp("abcd", "abcd"));
	printf("strcmp(\"abcd\", \"abcd\"): %d\n\n", strcmp("abcd", "abcd"));
	printf("ft_strcmp(\"abcd\", \"abcde\"): %d\n", ft_strcmp("abcde", "abcd"));
	printf("strcmp(\"abcd\", \"abcde\"): %d\n\n", strcmp("abcde", "abcd"));
	printf("ft_strcmp(\"abcde\", \"abcd\"): %d\n", ft_strcmp("abcd", "abcde"));
	printf("strcmp(\"abcde\", \"abcd\"): %d\n\n", strcmp("abcd", "abcde"));
	printf("ft_strcmp(\"\", \"\"): %d\n", ft_strcmp("", ""));
	printf("strcmp(\"\", \"\"): %d\n\n", strcmp("", ""));
	printf("ft_strcmp(\"abc\", \"\"): %d\n", ft_strcmp("abc", ""));
	printf("strcmp(\"abc\", \"\"): %d\n\n", strcmp("abc", ""));
	printf("ft_strcmp(\"\", \"abc\"): %d\n", ft_strcmp("", "abc"));
	printf("strcmp(\"\", \"abc\"): %d\n\n", strcmp("", "abc"));
/*
** FT_STRDUP
*/
	printf("*******FT_STRDUP*******\n--------------\n");
	char *res = "";
	printf("res: %s\n", res);
	printf("res = ft_strdup(\"ft_ft_ft\")\n");
	res = ft_strdup("ft_ft_ft");
	printf("res: %s\n\n", res);
	free(res);
	printf("res = ft_strdup(\"dup_dup_dup\")\n");
	res = ft_strdup("dup_dup_dup");
	printf("res: %s\n", res);
	free(res);
/*
** ft_read
*/
	printf("\n*******FT_READ*******\n--------------\n");
	memset(buff, '\0', 100);
	printf("\ttry ft_read w stdin: \n");
	ret = ft_read(0, buff, 3);
	printf("\nft_read return: %d\n", ret);
	printf("%s\n", buff);
	
	fd = open("main.c", O_RDONLY);
	printf("\ttry (fd, buff, 10)\n");
	ret = ft_read(fd, buff, 10);
    printf("ft_read errno: %d\n", errno);
    printf("%s\n", strerror(errno));
    printf("ft_read return: %d\n\n", ret);
	
	errno = 0;
    ret = read(fd, buff, 10);
    printf("read errno: %d\n", errno);
    printf("%s\n", strerror(errno));
    printf("read return: %d\n\n", ret);
    
    errno = 0;
	printf("\ttry (-1, buff, 10)\n");
    ret = ft_read(-1, buff, 10);
    printf("ft_read errno: %d\n", errno);
    printf("%s\n", strerror(errno));
    printf("ft_read return: %d\n\n", ret);
    
    errno = 0;
    ret = read(-1, buff, 10);
    printf("read errno: %d\n", errno);
    printf("%s\n", strerror(errno));
    printf("read return: %d\n\n", ret);
}