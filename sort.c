/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaouss <mnaouss@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 19:30:07 by mnaouss           #+#    #+#             */
/*   Updated: 2025/07/22 22:17:14 by mnaouss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf/ft_printf.h"

int	get_max_bits(int *arr, int size)
{
	int	max_num;
	int	bits;
	int	i;

	max_num = arr[0];
	i = 1;
	while (i < size)
	{
		if (arr[i] > max_num)
			max_num = arr[i];
		i++;
	}
	bits = 0;
	while ((max_num >> bits) != 0)
		bits++;
	return (bits);
}

void	sort(int *a, int *b, int size)
{
	int	i;
	int	j;
	int	maxbits;
	int	bit;
	int	size_a;
	int	size_b;
	int	elements_to_process;

	maxbits = get_max_bits(a, size);
	size_a = size;
	size_b = 0;
	i = 0;
	while (i < maxbits)
	{
		j = 0;
		elements_to_process = size_a;
		while (j < elements_to_process)
		{
			bit = (a[0] >> i) & 1;
			if (bit == 0)
			{
				pb(a, b, size_a, size_b);
				ft_printf("pb\n");
				size_a--;
				size_b++;
			}
			else
			{
				ra(a, size_a);
				ft_printf("ra\n");
			}
			j++;
		}
		while (size_b > 0)
		{
			pa(a, b, size_a, size_b);
			ft_printf("pa\n");
			size_a++;
			size_b--;
		}
		i++;
	}
}
