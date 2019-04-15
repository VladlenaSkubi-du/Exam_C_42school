/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_memory.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschmele <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 12:26:27 by sschmele          #+#    #+#             */
/*   Updated: 2019/04/15 12:27:36 by sschmele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_MEMORY_H
# define PRINT_MEMORY_H

# include <unistd.h>
# include <stdio.h>

void	ft_putchar(char c);
void	ft_putstr(char *s, int len);
void	print_memory(const void *addr, size_t size);
void	if_4_bytes(int *arr);
void	less_than_4_bytes(int *arr, size_t size);
void	fill_with_nb(char *res, int *arr, size_t size);
void	put_ascii(char *res);

#endif
