/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htinisha <htinisha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 19:20:34 by htinisha          #+#    #+#             */
/*   Updated: 2020/05/28 19:53:37 by htinisha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int     ft_intlen(long int n);

char    *ft_itoa(int x) 
{
    char *s;
    size_t len;
    long int n;

    n = x;
    if (x == -2147483648)
        return (ft_strdup("-2147483648"));

    len = 1 + ft_intlen(n);
    if (!(s = (char*)malloc(sizeof(char) * len)))
        return (NULL);

    if (n == 0)
        s[0] = '0';

    if (n < 0) {
        s[0] = '-';
        n = -n;
    }
    s[len - 1] = '\0';
    while (n) {
        len--;
        s[len - 1] = (n % 10) + '0';
        n /= 10;
    }
    return (s);
}
