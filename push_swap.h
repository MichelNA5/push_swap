/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaouss <mnaouss@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 18:09:39 by mnaouss           #+#    #+#             */
/*   Updated: 2025/07/22 22:11:14 by mnaouss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

void	error_exit(void);
int		has_duplicates(int *arr, int size);
int		ft_safe_atoi(const char *str, int *out);
char	**ft_split(char *str, char *charset, int *count);
void	sort(int *a, int *b, int size);
void	pa(int *a, int *b, int size_a, int size_b);
void	pb(int *a, int *b, int size_a, int size_b);
void	ra(int *a, int size);

#endif
