/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htinisha <htinisha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/27 00:32:18 by htinisha          #+#    #+#             */
/*   Updated: 2020/05/27 01:36:11 by htinisha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int     ft_isspace(char c)
{
	return (c == ' ' || c == '\n' || c == '\t');
}

int		count_words(char *str)
{
	int	count;

	count = 0;
	while (*str)
	{
		while (*str && ft_isspace(*str))
			str++;
		if (*str && !ft_isspace(*str))
		{
			count++;
			while (*str && !ft_isspace(*str))
				str++;
		}
	}
	return (count);
}

char    *malloc_word(char *str)
{
	char *word;
	int	i;

	i = 0;
	while (str[i] && !ft_isspace(str[i]))
		i++;
	word = (char *)malloc(sizeof(char) * (i + 1));
	i = 0;
	while (str[i] && !ft_isspace(str[i]))
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char    **ft_split(char *str)
{
	char **arr;
    
    arr = (char **)malloc(sizeof(char *) * (count_words(str) + 1));
	int i = 0;
	while (*str)
	{
		while (*str && ft_isspace(*str))
			str++;
		if (*str && !ft_isspace(*str))
		{
			arr[i] = malloc_word(str);
			i++;
			while (*str && !ft_isspace(*str))
				str++;
		}
	}
	arr[i] = NULL;
	return (arr);
}
