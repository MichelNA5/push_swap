/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaouss <mnaouss@student.42beirut.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 18:38:42 by mnaouss           #+#    #+#             */
/*   Updated: 2025/07/23 10:25:42 by mnaouss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf/ft_printf.h"

void	print_array(int *arr, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		ft_printf("%d\n", arr[i]);
		i++;
	}
}

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

int	main(int argc, char **argv)
{
	int		*a;
	int		*b;
	int		size;
	char	**temp;
	int		i;

	size = 0;
	if (argc != 2)
		error_exit();
	temp = ft_split(argv[1], " ", &size);
	a = malloc(sizeof(int) * size);
	b = malloc(sizeof(int) * size);
	i = 0;
	while (temp[i])
	{
		ft_safe_atoi(temp[i], &a[i]);
		i++;
	}
	if (has_duplicates(a, size))
		error_exit();
	index_array(a, size);
	sort(a, b, size);
	free_split(temp);
	free(a);
	free(b);
	return (0);
}
