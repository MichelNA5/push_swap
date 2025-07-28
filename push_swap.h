/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaouss <mnaouss@student.42beirut.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 18:09:39 by mnaouss           #+#    #+#             */
/*   Updated: 2025/07/24 16:48:21 by mnaouss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_radix
{
	int	*a;
	int	*b;
	int	size_a;
	int	size_b;
}	t_radix;

void	error_exit_free(int argc, char **temp, int *a, int *b);
void	error_exit(void);
int		has_duplicates(int *arr, int size);
int		ft_safe_atoi(const char *str, int *out);
char	**ft_split(char *str, char *charset, int *count);
void	sort(int *a, int *b, int size);
void	pa(int *a, int *b, int size_a, int size_b);
void	pb(int *a, int *b, int size_a, int size_b);
void	ra(int *a, int size);
int		count_smaller(int *arr, int size, int nb);
void	index_array(int *arr, int size);
void	free_split(char **arr);
char	**parse_args(int argc, char **argv, int *size);
int		fill_array(char **temp, int *a, int size);
void	sa(int *a);
void	rra(int *a, int size);
void	sort_picker(int *a, int *b, int size);
int		count_smaller(int *arr, int size, int nb);
void	sort_five(int *a, int *b, int size_a);
void	sort_three(int *a);

#endif
