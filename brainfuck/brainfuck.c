/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brainfuck.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschmele <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 19:48:01 by sschmele          #+#    #+#             */
/*   Updated: 2019/04/17 12:47:33 by sschmele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * Assignment name  : brainfuck
 * Expected files   : *.c, *.h
 * Allowed functions: write, malloc, free
 * --------------------------------------------------------------------------------
 *
 *  Write a Brainfuck interpreter program.
 *  The source code will be given as first parameter.
 *  The code will always be valid, with no more than 4096 operations.
 *  Brainfuck is a minimalist language. It consists of an array of bytes
 *  (in our case, let's say 2048 bytes) initialized to zero,
 *  and a pointer to its first byte.
 *
 *  Every operator consists of a single character :
 *  - '>' increment the pointer ;
 *  - '<' decrement the pointer ;
 *  - '+' increment the pointed byte ;
 *  - '-' decrement the pointed byte ;
 *  - '.' print the pointed byte on standard output ;
 *  - '[' go to the matching ']' if the pointed byte is 0 (while start) ;
 *  - ']' go to the matching '[' if the pointed byte is not 0 (while end).
 *
 *  Any other character is a comment.
 *
 *  Examples:
 *
 *  $>./brainfuck "++++++++++[>+++++++>++++++++++>+++>+<<<<-]
 *  >++.>+.+++++++..+++.>++.<<+++++++++++++++.>.+++.------.--------.>+.>." | cat -e
 *  Hello World!$
 *  $>./brainfuck "+++++[>++++[>++++H>+++++i<<-]>>>++\n<<<<-]>>--------.>+++++.>." | cat -e
 *  Hi$
 *  $>./brainfuck | cat -e
 *  $
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void		brainfuck(char *s, char *str)
{
	int		i;
	int		j;
	int		flag;

	i = 0;
	j = 0;
	flag = 0;
	printf("here\n");
	while (s[i])
	{
		if (s[i] == '+')
		{
			str[j]++;
			printf("plus: ptr =%d	ascii =%d	char =%c\n", j, str[j], str[j]);
		}
		else if (s[i] == '-')
		{
			str[j]--;
			printf("minus: ptr =%d   ascii =%d   char =%c\n", j, str[j], str[j]);
		}
		else if (s[i] == '>')
		{
			j++;
			printf(">: ptr =%d   ascii =%d   char =%c\n", j, str[j], str[j]);
		}
		else if (s[i] == '<')
		{
			j--;
			printf("<: ptr =%d   ascii =%d   char =%c\n", j, str[j], str[j]);
		}
		else if (s[i] == '.')
			printf("print: %c\n", str[j]);
		else if (s[i] == '[')
		{
			if (str[j] == 0)
			{
				str[j]++;
				while (str[j])
				{
					i++;
					if (s[i] == '[')
						str[j]++;
					if (s[i] == ']')
						str[j]--;
				}
			}
		}
		else if (s[i] == ']')
		{
			if (str[j])
			{
				str[j]++;
				while (str[j])
				{
					i--;
					if (s[i] == '[')
						str[i]--;
					if (s[i] == ']')
						str[j]++;
				}
				i--;
			}
		}
		i++;
	}
}

int			ft_strlen(char *s)
{
	int		i;
	int		res;

	i = 0;
	res = 0;
	while (s[i])
	{
		res++;
		i++;
	}
	return (res);
}

int			main(int argc, char **argv)
{	
	char	str[2048];
	
	if (argc == 2 && argv[1][0] && ft_strlen(argv[1]) <= 4096)
		brainfuck(argv[1], str);
	write(1, "\n", 1);
	return (0);
}
