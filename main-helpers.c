/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main-helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaouss <mnaouss@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 18:14:33 by mnaouss           #+#    #+#             */
/*   Updated: 2025/07/23 18:54:46 by mnaouss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_smaller(int *arr, int size, int nb)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (i < size)
	{
		if (arr[i] < nb)
			count++;
		i++;
	}
	return (count);
}

void	index_array(int *arr, int size)
{
	int		i;
	int		*tmp;

	tmp = malloc(sizeof(int) * size);
	if (!tmp)
		error_exit();
	i = 0;
	while (i < size)
	{
		tmp[i] = count_smaller(arr, size, arr[i]);
		i++;
	}
	i = 0;
	while (i < size)
	{
		arr[i] = tmp[i];
		i++;
	}
	free(tmp);
}

void	free_split(char **arr)
{
	int	i;

	i = 0;
	if (!arr)
		return ;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

char	**parse_args(int argc, char **argv, int *size)
{
	char	**temp;
	int		i;

	if (argc == 2)
	{
		*size = 0;
		temp = ft_split(argv[1], " ", size);
	}
	else
	{
		*size = argc - 1;
		temp = malloc(sizeof(char *) * (*size + 1));
		if (!temp)
			error_exit();
		i = 0;
		while (i < *size)
		{
			temp[i] = argv[i + 1];
			i++;
		}
		temp[*size] = NULL;
	}
	return (temp);
}

void	fill_array(char **temp, int *a, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (!ft_safe_atoi(temp[i], &a[i]))
		{
			error_exit();
		}
		i++;
	}
}
