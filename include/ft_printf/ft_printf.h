/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arphueng <arphueng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 19:46:06 by arphueng          #+#    #+#             */
/*   Updated: 2025/04/17 18:29:22 by arphueng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>

# define UPPERHEX "0123456789ABCDEF"
# define LOWERHEX "0123456789abcdef"

int		ft_printf(const char *str, ...);
int		ft_allformat(char c, va_list ap);

int		ft_putnbr(int nbr);

void	ft_printptr(unsigned long n);
int		ft_lenptr(unsigned long n);
int		ft_putptr(unsigned long n);

int		ft_puthex(unsigned int n, const char c, int i);

int		ft_putchar(char c);

int		ft_putper(void);

int		ft_putstr(char *str);

int		ft_putunbr(unsigned int nbr);

#endif
