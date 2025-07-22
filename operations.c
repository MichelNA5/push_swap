/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaouss <mnaouss@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 20:00:43 by mnaouss           #+#    #+#             */
/*   Updated: 2025/07/22 22:10:28 by mnaouss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
}
