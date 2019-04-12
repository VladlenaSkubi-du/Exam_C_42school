/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_memory_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschmele <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 11:33:06 by sschmele          #+#    #+#             */
/*   Updated: 2019/04/12 17:02:20 by sschmele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print_memory.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *s, int len)
{
	write(1, s, len);
}

void	print_memory(const void *addr, size_t size)
{
	int			*arr;
	int			i;

	arr = (int*)addr;
	i = 0;
	while (size)
	{
		if (size / 4)
		{
			if_4_bytes(&arr[i]);
			i += 4;
		}
		else
			less_than_4_bytes(&arr[i], size);
		size /= 4;
	}
}

void	if_4_bytes(int *arr)
{
	int			i;
	char		res[56];

	i = 0;
	while (i < 40)
	{
		if (i % 5 == 4)
			res[i] = ' ';
		else
			res[i] = '0';
		i++;
	}
	while (i < 56)
	{
		res[i] = '.';
		i++;
	}
	fill_with_nb(res, arr, 4);
}

void	less_than_4_bytes(int *arr, size_t size)
{
	size_t		i;
	char		res[40 + size * 4];

	i = 0;
	while (i < size * 10)
	{
		if (i % 5 == 4)
			res[i] = ' ';
		else
			res[i] = '0';
		i++;
	}
	while (i < 40)
	{
		res[i] = ' ';
		i++;
	}
	while (i < (40 + size * 4))
	{
		res[i] = '.';
		i++;
	}
	fill_with_nb(res, arr, size);
}

void	fill_with_nb(char *res, int *arr, size_t size)
{
	char		*main;
	int			nb;
	size_t		i;
	size_t		j;
	size_t		k;
	int			len_nb_16;

	main = "0123456789abcdef";
	i = 0;
	j = size * 2;

	while (i < size)
	{
		nb = arr[i];
		if (nb != 0)
			while (nb)
			{
				len_nb_16 = 0;
				while (nb && (j > i * 10 + size))
				{
					res[j] = main[nb % 16];
					nb /= 16;
					len_nb_16++;
					j--;
				}
				while (nb)
				{
					j--;
					res[j] = main[nb % 16];
					nb /= 16;
					len_nb_16++;
				}
				if (res[j + 1] >= 'a' && res[j + 1] <= 'f' && len_nb_16 == 1) 
				{
					res[j] = '0';
					len_nb_16++;
					j--;
				}
				if (res[i * 10] == '0')
				{
					k = 0;
					while (len_nb_16)
					{
						res[i * 10 + k] = res[j + 1];
						k++;
						j++;
						len_nb_16--;
					}
					while (k < size)
					{
						res[i * 10 + k] = '0';
						k++;
					}
					while (k < size * 2)
					{
						k++;
						res[i * 10 + k] = '0';
					}
				}
			}
		i++;
		j = i * 10 + size * 2;
	}
	put_ascii(res, size);
	ft_putstr(res, (40 + size * 4));
	ft_putchar('\n');
}

void	put_ascii(char *res, size_t size)
{
	int			i;
	int			j;
	int			one;
	int			two;
	int			ascii;

	i = 0;
	j = 0;
	while (i < 39)
	{
		if (res[i] == ' ')
			i++;
		one = res[i] - '0';
		two = res[i + 1] - '0';
		if (res[i] >= 'a' && res[i] <= 'f')
			one -= 39;
		if (res[i + 1] >= 'a' && res[i + 1] <= 'f')
			two -= 39;
		ascii = one * 16 + two;
		if (!((ascii >= 0 && ascii < 32) || ascii >= 127))
			res[40 + j] = ascii;
		i += 2;
		j++;
	}	
}
