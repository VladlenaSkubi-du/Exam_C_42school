/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_mate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschmele <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 12:26:24 by sschmele          #+#    #+#             */
/*   Updated: 2019/06/08 15:10:59 by sschmele         ###   ########.fr       */
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

	x = i;
	y = j;
	while (i < size)
	{
		if (map[i][j] == 'R' || map[i][j] == 'Q')
			return (-1);
		i++;
	}
	i = x;
	while (i >= 0)
	{
		if (map[i][j] == 'R' || map[i][j] == 'Q')
			return (-1);
		i--;
	}
	i = x;
	while (j < size)
	{
		if (map[i][j] == 'R' || map[i][j] == 'Q')
			return (-1);
		j++;
	}
	j = y;
	while (j >= 0)
	{
		if (map[i][j] == 'R' || map[i][j] == 'Q')
			return (-1);
		j--;
	}
	i = x;
	j = y;
	while (i < size && j < size)
	{
		if (map[i][j] == 'Q' || map[i][j] == 'B')
			return (-1);
		i++;
		j++;
	}
	i = x;
	j = y;
	while (i >= 0 && j < size)
	{
		if (map[i][j] == 'Q' || map[i][j] == 'B')
			return (-1);
		i--;
		j++;
	}
	i = x;
	j = y;
	while (i < size && j >= 0)
	{
		if (map[i][j] == 'Q' || map[i][j] == 'B')
			return (-1);
		i++;
		j--;
	}
	i = x;
	j = y;
	while (i >= 0 && j >= 0)
	{
		if (map[i][j] == 'Q' || map[i][j] == 'B')
			return (-1);
		i--;
		j--;
	}
	i = x;
	j = y;
	if (i - 1 >= 0 && j - 1 >= 0)
		if (map[i - 1][j - 1] == 'P')
			return (-1);
	if (i - 1 >= 0 && j + 1 < size)
		if (map[i - 1][j + 1] == 'P')
			return (-1);
	return (1);
}

int		check_validity(char **map, int size)
{
	int		i;
	int		j;
	int		len;
	int		king;

	i = 0;
	j = -1;
	king = 0;
	while (i < size)
	{
		len = ft_strlen(map[i]);
		if (len < 1 && len > 7)
			return (-1);
		if (len != size)
			return (-1);
		if (len == 1 && map[i][0] != 'K')
			return (-1);
		while (map[i][++j])
		{
			if (map[i][j] == 'K')
				king++;
		}
		j = -1;
		i++;
	}
	if (king != 1)
		return (-1);
	return (1);
}

int		check_mate(char **map, int size)
{
	int		tmp;
	int		i;
	int		j;

	tmp = 0;
	i = 0;
	j = 0;
	if (check_validity(map, size) == -1)
		return (-2);
//	print_map(map);
	while (map[i])
	{
		while (map[i][j])
		{
			if (map[i][j] == 'K')
			{
				tmp = 1;
				break ;
			}
			j++;
		}
		if (tmp == 1)
			break ;
		j = 0;
		i++;
	}
	if ((tmp = check_result(map, size, i, j)) == -1)
		return (1);
	else if (tmp == 1)
		return (-1);
	return (-1);
}

int		main(int argc, char **argv)
{
	int		tmp;

	if (argc < 2 || argc > 8)
		write(1, "\n", 1);
	else
	{
		if ((tmp = check_mate(&argv[1], argc - 1)) == -1)
			write(1, "Fail\n", 5);
		else if (tmp == 1)
			write(1, "Success\n", 8);
		else if (tmp == -2)
			write(1, "\n", 1);
	}
	return (0);
}
