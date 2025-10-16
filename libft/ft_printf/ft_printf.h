/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arpereir <arpereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 22:14:33 by arpereir          #+#    #+#             */
/*   Updated: 2025/05/28 14:49:25 by arpereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>

int		ft_putchar(char c);
int		ft_putstr(char *s);
size_t	ft_strlen(char const *s);
int		ft_putnbr(int nb);
int		ft_putnbr_base(unsigned long long nbr, char format);
int		ft_printf(const char *str, ...);

#endif