/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_mate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschmele <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 12:26:24 by sschmele          #+#    #+#             */
/*   Updated: 2019/04/18 19:05:29 by sschmele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

#include <unistd.h>

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
	
	//write(1, "Success\n", 8);
}

void	check_mate(char **map)
{
	
}

int		main(int argc, char **argv)
{
	char	**map;
	
	if (argc < 2 || argc > 8)
		write(1, "\n", 1);
	else
		check_mate(&argv[1]);
	return (0);
}
