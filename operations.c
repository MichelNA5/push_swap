/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaouss <mnaouss@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 20:00:43 by mnaouss           #+#    #+#             */
/*   Updated: 2025/07/23 23:16:39 by mnaouss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf/ft_printf.h"

void	pa(int *a, int *b, int size_a, int size_b)
{
	int	i;

	i = size_a;
	while (i > 0)
	{
		a[i] = a[i - 1];
		i--;
	}
	a[0] = b[0];
	i = 0;
	while (i < size_b - 1)
	{
		b[i] = b[i + 1];
		i++;
	}
	ft_printf("pa\n");
}

void	pb(int *a, int *b, int size_a, int size_b)
{
	int	i;

	i = size_b;
	while (i > 0)
	{
		b[i] = b[i - 1];
		i--;
	}
	b[0] = a[0];
	i = 0;
	while (i < size_a - 1)
	{
		a[i] = a[i + 1];
		i++;
	}
	ft_printf("pb\n");
}

void	ra(int *a, int size)
{
	int	temp;
	int	i;

	temp = a[0];
	i = 0;
	while (i < size - 1)
	{
		a[i] = a[i + 1];
		i++;
	}
	a[size - 1] = temp;
	ft_printf("ra\n");
}

void	sa(int *a)
{
	int	temp;

	temp = a[0];
	a[0] = a[1];
	a[1] = temp;
	ft_printf("sa\n");
}

void	rra(int *a, int size)
{
	int	temp;
	int	i;

	temp = a[size - 1];
	i = size - 1;
	while (i > 0)
	{
		a[i] = a[i - 1];
		i--;
	}
	a[0] = temp;
	ft_printf("rra\n");
}
