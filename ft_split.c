/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaouss <mnaouss@student.42beirut.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 19:43:30 by mnaouss           #+#    #+#             */
/*   Updated: 2025/07/30 20:14:08 by mnaouss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_strncpy(char *s1, char *s2, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		s1[i] = s2[i];
		i++;
	}
	s1[i] = '\0';
	return (i);
}

static int	is_in_charset(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (charset[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static int	count_words(char *str, char *charset)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*str)
	{
		if (!is_in_charset(*str, charset) && !in_word)
		{
			in_word = 1;
			count++;
		}
		else if (is_in_charset(*str, charset))
		{
			in_word = 0;
		}
		str++;
	}
	return (count);
}

static char	*input_arr(char *str, char *charset, char **arr, int i)
{
	int	arr_size;

	arr_size = 0;
	while (1)
	{
		if (is_in_charset(*str, charset) || *str == '\0')
			break ;
		arr_size++;
		str++;
	}
	arr[i] = (char *)malloc(sizeof(char) * (arr_size + 1));
	ft_strncpy(arr[i], str - arr_size, arr_size);
	return (str);
}

char	**ft_split(char *str, char *charset, int *count)
{
	char	**arr;
	int		i;

	i = 0;
	*count = count_words(str, charset);
	arr = (char **)malloc(sizeof(char *) * (*count + 1));
	while (*str != '\0')
	{
		if (!is_in_charset(*str, charset))
		{
			str = input_arr(str, charset, arr, i);
			if (!str)
				return (NULL);
			i++;
			if (*str == '\0')
				break ;
		}
		str++;
	}
	arr[i] = NULL;
	return (arr);
}
