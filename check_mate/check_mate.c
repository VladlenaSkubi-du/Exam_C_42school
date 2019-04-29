/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_mate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschmele <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 12:26:24 by sschmele          #+#    #+#             */
/*   Updated: 2019/04/29 15:53:33 by sschmele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check_mate.h"

void	print_map(char **map)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (map[i])
	{
		while (map[i][j])
		{
			write(1, &map[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		j = 0;
		i++;
	}
}

int		ft_strlen(char *s)
{
	int		res;
	int		i;

	res = 0;
	i = -1;
	while (s[++i])
		res++;
	return (res);
}

int		check_result(char **map, int size, short i, short j)
{
	short	x;
	short	y;

	x = -1;
	y = 0;
	while (i + (++x) + 1 < size)
		if (map[i + x + 1][j + y] == 'R' || map[x + i + 1][j + y] == 'Q')
			return (-1);
	x = -1;
	while (i - (++x) - 1 >= 0)
		if (map[i - x - 1][j + y] == 'R' || map[i - x - 1][j + y] == 'Q')
			return (-1);
	x = 0;
	y = -1;
	while (j + (++y) + 1 < size)
		if (map[i + x][j + y + 1] == 'R' || map[i + x][j + y + 1] == 'Q')
			return (-1);
	y = -1;
	while (j - (++y) - 1 >= 0)
		if (map[i + x][j - y - 1] == 'R' || map[i + x][j - y - 1] == 'Q')
			return (-1);
	x = -1;
	y = -1;
	while (i + (++x) + 1 < size && j + (++y) + 1 < size)
		if (map[i + x + 1][j + y + 1] == 'Q' || map[i + x + 1][j + y + 1] == 'B'
				|| map[i + x + 1][j + y + 1] == 'P')
			return (-1);
	x = -1;
	y = -1;
	while (i - (++x) - 1 >= 0 && j + (++y) + 1 < size)
		if (map[i - x - 1][j + y + 1] == 'Q' || map[i - x - 1][j + y + 1] == 'B')
			return (-1);
	x = -1;
	y = -1;
	while (i + (++x) + 1 < size && j - (++y) - 1 >= 0)
		if (map[i + x + 1][j - y - 1] == 'Q' || map[i + x + 1][j - y - 1] == 'B'
				|| map[i + x + 1][j - y - 1] == 'P')
			return (-1);
	x = -1;
	y = -1;
	while (i - (++x) - 1 >= 0 && j - (++y) - 1 >= 0)
		if (map[i - x - 1][j - y - 1] == 'Q' || map[i - x - 1][j - y - 1] == 'B')
			return (-1);
	return (1);
}

int		check_validity(char **map, int size)
{
	int		i;
	int		len;
	int		tmp;

	i = 1;
	len = ft_strlen(map[0]);
	if (len < 1 && len > 7)
		return (-1);
	if (len != size)
		return (-1);
	while (i < size)
	{
		tmp = ft_strlen(map[i]);
		if (tmp != len || tmp != size)
			return (-1);
		i++;
	}
	return (1);
}

void	check_mate(char **map, int size)
{
	short	i;
	short	j;
	int		king;
	short	x;
	short	y;
	int		flag;

	print_map(map);
	if (check_validity(map, size) == -1)
		write(1, "\n", 1);
	else
	{
		if (size == 1)
			write(1, "Fail\n", 5);
		else
		{
			i = -1;
			j = -1;
			king = 0;
			flag = 0;
			while (++j < size)
			{
				while (++i < size)
				{
					if (map[j][i] == 'K')
					{
						x = i;
						y = j;
						king++;
					}
					else if (map[j][i] == 'R' || map[j][i] == 'P' || map[j][i] == 'Q'
							|| map[j][i] == 'B')
						flag++;
				}
				i = -1;
			}
			if (king != 1)
				write(1, "\n", 1);
			else
			{
				if (flag == 0)
					write(1, "Fail\n", 5);
				else
				{
					if (check_result(map, size, x, y) == -1)
						write(1, "Fail\n", 5);
					else
						write(1, "Success\n", 8);
				}
			}
		}
	}
}

int		main(int argc, char **argv)
{
	if (argc < 2 || argc > 8)
		write(1, "\n", 1);
	else
		check_mate(&argv[1], argc - 1);
	return (0);
}
