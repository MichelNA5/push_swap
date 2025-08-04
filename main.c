/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaouss <mnaouss@student.42beirut.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 18:38:42 by mnaouss           #+#    #+#             */
/*   Updated: 2025/07/30 20:13:34 by mnaouss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf/ft_printf.h"

static int	is_sorted(int *arr, int size)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		if (arr[i] > arr[i + 1])
			return (0);
		i++;
	}
	return (1);
}

static void	free_all(int argc, char **temp, int *a, int *b)
{
	if (argc == 2)
		free_split(temp);
	else
		free(temp);
	free(a);
	free(b);
}

static void	exit_free(int argc, char **temp, int *a, int *b)
{
	free_all(argc, temp, a, b);
	exit(EXIT_SUCCESS);
}

void	error_exit_free(int argc, char **temp, int *a, int *b)
{
	free_all(argc, temp, a, b);
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

int	main(int argc, char **argv)
{
	int		*a;
	int		*b;
	int		size;
	char	**temp;

	if (argc == 1)
		exit(EXIT_SUCCESS);
	if (argc < 2 || (argc == 2 && argv[1][0] == '\0'))
	{
		write(2, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
	temp = parse_args(argc, argv, &size);
	a = malloc(sizeof(int) * size);
	b = malloc(sizeof(int) * size);
	if (!fill_array(temp, a, size))
		error_exit_free(argc, temp, a, b);
	if (has_duplicates(a, size))
		error_exit_free(argc, temp, a, b);
	if (is_sorted(a, size))
		exit_free(argc, temp, a, b);
	index_array(a, size);
	sort_picker(a, b, size);
	free_all(argc, temp, a, b);
	return (0);
}
