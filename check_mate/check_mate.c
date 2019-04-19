/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_mate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschmele <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 12:26:24 by sschmele          #+#    #+#             */
/*   Updated: 2019/04/19 15:16:44 by sschmele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check_mate.h"

/*
 * Assignment name  : check_mate 
 * Expected files   : *.c, *.h
 * Allowed functions: write, malloc, free
 * --------------------------------------------------------------------------------
 *
 *  Write a program who takes rows of a chessboard in argument and check if your 
 *  King is in a check position.
 *
 *  Chess is played on a chessboard, a squared board of 8-squares length with 
 *  specific pieces on it : King, Queen, Bishop, Knight, Rook and Pawns.
 *  For this exercice, you will only play with Pawns, Bishops, Rooks and Queen...
 *  and obviously a King.
 *
 *  Each piece have a specific method of movement, and all patterns of capture are
 *  detailled in the examples.txt file.
 *
 *  A piece can capture only the first ennemy piece it founds on its capture
 *  patterns.
 *
 *  The board have a variable size but will remains a square. There's only one King
 *  and all other pieces are against it. All other characters except those used for
 *  pieces are considered as empty squares.
 *
 *  The King is considered as in a check position when an other enemy piece can
 *  capture it. When it's the case, you will print "Success" on the standard output
 *  followed by a newline, otherwise you will print "Fail" followed by a newline.
 *
 *  If there is no arguments, the program will only print a newline.
 *
 *  Examples:
 *
 *  $> ./chessmate '..' '.K' | cat -e
 *  Fail$
 *  $> ./check_mate 'R...' '.K..' '..P.' '....' | cat -e
 *  Success$
 *  $> ./chessmate 'R...' 'iheK' '....' 'jeiR' | cat -e
 *  Success$
 *  $> ./chessmate | cat -e
 *  $
 *  $>
 */

#include <stdio.h>

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
	int res;
	int	i;

	res = 0;
	i = -1;
	while (s[++i])
		res++;
	return (res);
}

void	check_result(t_list *chess)
{
	printf("K stays:%d	%d\n", chess->K_x, chess->K_y);
}

int		check_validity(char **map, int size)
{
	int		i;
	int		len;

	i = 1;
	len = ft_strlen(map[0]);
	if (len < 1 && len > 7)
		return (-1);
	while (i < size)
	{
		if (ft_strlen(map[i]) != len || ft_strlen(map[i]) != size)
			return (-1);
		i++;
	}
	return (1);

}

void	check_mate(char **map, int size)
{
	t_list	*chess;
	int		i;
	int		j;
	
	print_map(map);	
	if (check_validity(map, size) == -1)
		write(1, "E\n", 2);
	else
	{
		if (size == 1)
			write(1, "Fail\n", 5);
		else
		{
			chess = (t_list*)malloc(sizeof(t_list));
			i = 0;
			j = 0;
			chess->K_x = 0;
			chess->K_y = 0;
			chess->size = size;
			while (j < size)
			{		
				while (map[j][i])
				{
					if (map[j][i] == 'K')
					{
						chess->K_x = i + 1;
						chess->K_y = j + 1;
					}
					i++;
				}
				i = 0;
				j++;
			}
			if (chess->K_x == 0 || chess->K_y == 0)
				write(1, "E\n", 2);
			else
				check_result(chess);
		}
	}
	
}

int		main(int argc, char **argv)
{
	char	**map;
	
	if (argc < 2 || argc > 8)
		write(1, "E\n", 2);
	else
		check_mate(&argv[1], argc - 1);
	return (0);
}
