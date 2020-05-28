/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htinisha <htinisha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 03:41:40 by htinisha          #+#    #+#             */
/*   Updated: 2020/05/26 03:41:40 by htinisha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
    void	*result;
    size_t	i;

    i = 0;
    if (nmemb == 0 || size == 0)
        return (NULL);
    result = malloc(size * nmemb);
    while (i <= nmemb)
    {
        ((char*)result)[i] = 0;
        i++;
    }
    return (result);
}
