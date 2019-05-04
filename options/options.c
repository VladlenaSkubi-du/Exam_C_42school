/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschmele <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 16:49:09 by sschmele          #+#    #+#             */
/*   Updated: 2019/05/04 16:08:54 by sschmele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "options.h"

int		options(char **arr, int nb)
{
	int		i;
	int		j;
	char	main[35];
	int		flag;

	i = -1;
	while (++i < 35)
		main[i] = ((i == 8 || i == 17 || i == 26) ? ' ' : '0');
	i = 0;
	while (i < nb)
	{
		if (arr[i][0] != '-')
			return (-1);
		j = 0;
		flag = 0;
		while (arr[i][++j])
		{
			if (!(arr[i][j] >= 'a' && arr[i][j] <= 'z'))
				return (2);
			if (arr[i][j] >= 'a' && arr[i][j] <= 'h')
			{
				if (flag == 0 || flag == 1)
					flag = 1;
				else
					return (-1);
				main[34 - (arr[i][j] - 'a')] = '1';
			}
			else if (arr[i][j] >= 'i' && arr[i][j] <= 'p')
			{
				if (flag == 0 || flag == 2)
					flag = 2;
				else
					return (-1);
				main[25 - (arr[i][j] - 'i')] = '1';
			}
			else if (arr[i][j] >= 'q' && arr[i][j] <= 'x')
			{
				if (flag == 0 || flag == 3)
					flag = 3;
				else
					return (-1);
				main[16 - (arr[i][j] - 'q')] = '1';
			}
			else if (arr[i][j] >= 'y' && arr[i][j] <= 'z')
			{
				if (flag == 0 || flag == 4)
					flag = 4;
				else
					return (-1);
				main[7 - (arr[i][j] - 'y')] = '1';
			}
		}
		i++;
	}
	write(1, main, 35);
	return (0);
}

int		main(int argc, char **argv)
{
	int		tmp;

	if (argc == 1 || argc > 5)
		write(1, "options: abcdefghijklmnopqrstuvwxyz", 35);
	else
	{
		if ((tmp = options(&argv[1], argc - 1)) == -1)
			write(1, "options: abcdefghijklmnopqrstuvwxyz", 35);
		else if (tmp == 2)
			write(1, "Invalid Option", 14);
	}
	write(1, "\n", 1);
	return (0);
}
