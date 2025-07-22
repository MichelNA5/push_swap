/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaouss <mnaouss@student.42beirut.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 16:49:30 by mnaouss           #+#    #+#             */
/*   Updated: 2025/06/17 01:05:52 by mnaouss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>   // For va_list, va_start, etc.
# include <unistd.h>   // For write()
# include <stdlib.h>   // For malloc, free

// Main function
int	ft_printf(const char *format, ...);

// Format handlers
int	handle_format(char specifier, va_list args);

// Printing functions
int	print_char(int c);
int	print_str(const char *s);
int	print_nbr(int n);
int	print_unsigned(unsigned int n);
int	print_hex(unsigned int n, int uppercase);
int	print_ptr(void *ptr);

#endif