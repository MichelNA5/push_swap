/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaouss <mnaouss@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 22:51:12 by mnaouss           #+#    #+#             */
/*   Updated: 2025/07/23 23:32:11 by mnaouss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(int *a)
{
	int	top;
	int	mid;
	int	bot;

	top = a[0];
	mid = a[1];
	bot = a[2];
	if (top > mid && mid < bot && top < bot)
		sa(a);
	else if (top > mid && mid > bot)
	{
		sa(a);
		rra(a, 3);
	}
	else if (top > mid && mid < bot && top > bot)
	{
		ra(a, 3);
	}
	else if (top < mid && mid > bot && top < bot)
	{
		sa(a);
		ra(a, 3);
	}
	else if (top < mid && mid > bot && top > bot)
		rra(a, 3);
}

static int	find_min_idx(int *a, int size_a)
{
	int	min_idx;
	int	i;

	min_idx = 0;
	i = 1;
	while (i < size_a)
	{
		if (a[i] < a[min_idx])
			min_idx = i;
		i++;
	}
	return (min_idx);
}

static void	push_min_to_b(int *a, int *b, int *size_a, int *size_b)
{
	int	min_idx;
	int	i;

	min_idx = find_min_idx(a, *size_a);
	if (min_idx <= *size_a / 2)
	{
		i = 0;
		while (i++ < min_idx)
			ra(a, *size_a);
	}
	else
	{
		i = min_idx;
		while (i++ < *size_a)
			rra(a, *size_a);
	}
	pb(a, b, *size_a, *size_b);
	(*size_a)--;
	(*size_b)++;
}

static void	push_all_b_to_a(int *a, int *b, int *size_a, int *size_b)
{
	while (*size_b > 0)
	{
		pa(a, b, *size_a, *size_b);
		(*size_a)++;
		(*size_b)--;
	}
}

void	sort_five(int *a, int *b, int size_a)
{
	int	size_b;

	size_b = 0;
	while (size_a > 3)
		push_min_to_b(a, b, &size_a, &size_b);
	sort_three(a);
	push_all_b_to_a(a, b, &size_a, &size_b);
}

