/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaouss <mnaouss@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 18:38:42 by mnaouss           #+#    #+#             */
/*   Updated: 2025/07/23 23:01:10 by mnaouss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf/ft_printf.h"

int	is_sorted(int *arr, int size)
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

void	exit_free(void)
{
	exit(EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	int		*a;
	int		*b;
	int		size;
	char	**temp;

	if (argc < 2 || (argc == 2 && argv[1][0] == '\0'))
		error_exit();
	temp = parse_args(argc, argv, &size);
	a = malloc(sizeof(int) * size);
	b = malloc(sizeof(int) * size);
	fill_array(temp, a, size);
	if (has_duplicates(a, size))
		error_exit();
	if (is_sorted(a, size))
		exit_free();
	index_array(a, size);
	sort_picker(a, b, size);
	if (argc == 2)
		free_split(temp);
	else
		free(temp);
	free(a);
	free(b);
	return (0);
}
