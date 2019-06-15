/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschmele <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 16:49:09 by sschmele          #+#    #+#             */
/*   Updated: 2019/06/15 13:57:22 by sschmele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "options.h"

//Test 1: -abcz -w -ijfek -lildali -pirmakn -apizobouzaguaoca
//Test 2: -z bonjour -cd -e

int		options(char **arr)
{
	int		i;
	int		j;
	char	main[] = "00000000 00000000 00000000 00000000";
	int		tmp;

	i = -1;
	j = 0;
	if (arr[0][0] != '-')
		return (-1);
	while (arr[++i])
	{
		if (arr[i][0] == '-')
		{
			while (arr[i][++j])
			{	
				if (arr[i][j] == 'h')
					return (-1);
				if (!(arr[i][j] >= 'a' && arr[i][j] <= 'z'))
					return (-2);
				tmp = 6 - arr[i][j] + 'z';
				if (tmp >= 8 && tmp < 16)
					tmp++;
				else if (tmp >= 16 && tmp < 24)
					tmp += 2;
				else if (tmp >= 24 && tmp < 32)
					tmp += 3;
				main[tmp] = '1';
			}
		}
		j = 0;
	}
	write(1, &main, 35);
	write(1, "\n", 1);
	return (1);
}

int		main(int argc, char **argv)
{
	int		tmp;

	if (argc == 1)
		write(1, "options: abcdefghijklmnopqrstuvwxyz\n", 36);
	else
	{
		if ((tmp = options(&argv[1])) == -1)
			write(1, "options: abcdefghijklmnopqrstuvwxyz\n", 36);
		else if (tmp == -2)
			write(1, "Invalid Option\n", 15);
	}
	return (0);
}
