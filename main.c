/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaouss <mnaouss@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 18:38:42 by mnaouss           #+#    #+#             */
/*   Updated: 2025/07/22 22:13:25 by mnaouss          ###   ########.fr       */
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
	int	i;
	int	value;

	i = 0;
	while (i < size)
	{
		value = count_smaller(arr, size, arr[i]);
		arr[i] = value;
		i++;
	}
}

void	convert_binary(int *arr, int size)
{
	int	i;
	int	value;
	int	decimal;
	int	binary;
	int	base;

	i = 0;
	while (i < size)
	{
		decimal = arr[i];
		binary = 0;
		base = 1;
		while (decimal > 0)
		{
			if (decimal % 2)
				binary += base;
			decimal /= 2;
			base *= 10;
		}
		value = binary;
		arr[i] = value;
		i++;
	}
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
	print_array(a, size);
}
