/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaouss <mnaouss@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 19:30:07 by mnaouss           #+#    #+#             */
/*   Updated: 2025/07/23 23:32:18 by mnaouss          ###   ########.fr       */
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

void	radix_pass(t_radix *r, int bit, int total)
{
	int	j;
	int	bit_val;

	j = 0;
	while (j < total)
	{
		bit_val = (r->a[0] >> bit) & 1;
		if (bit_val == 0)
		{
			pb(r->a, r->b, r->size_a, r->size_b);
			r->size_a--;
			r->size_b++;
		}
		else
		{
			ra(r->a, r->size_a);
		}
		j++;
	}
}

void	sort(int *a, int *b, int size)
{
	int		i;
	int		maxbits;
	t_radix	r;

	maxbits = get_max_bits(a, size);
	r.a = a;
	r.b = b;
	r.size_a = size;
	r.size_b = 0;
	i = 0;
	while (i < maxbits)
	{
		radix_pass(&r, i, r.size_a);
		while (r.size_b > 0)
		{
			pa(r.a, r.b, r.size_a, r.size_b);
			r.size_a++;
			r.size_b--;
		}
		i++;
	}
}

void	sort_picker(int *a, int *b, int size)
{
	if (size == 2)
	{
		if (a[0] > a[1])
			sa(a);
	}
	else if (size == 3)
		sort_three(a);
	else if (size <= 5)
		sort_five(a, b, size);
	else
	{
		sort(a, b, size);
	}
}
