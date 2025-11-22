/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvieira <vvieira@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 10:57:58 by vvieira           #+#    #+#             */
/*   Updated: 2025/08/16 10:58:00 by vvieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>

int	ft_print_char(char c);
int	ft_print_str(char *str);
int	ft_print_number(int nb);
int	ft_print_ptr(va_list *ptr);
int	ft_checker(char c, va_list *ptr);
int	ft_printf(const char *format, ...);
int	ft_print_adr(unsigned long int nb);
int	ft_print_unsigned(unsigned int nb);
int	ft_print_hex(unsigned int nb, int s);

#endif