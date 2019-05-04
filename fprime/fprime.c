/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fprime.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschmele <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 16:43:24 by sschmele          #+#    #+#             */
/*   Updated: 2019/05/04 20:38:31 by sschmele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Assignment name  : fprime
Expected files   : fprime.c
Allowed functions: printf, atoi
--------------------------------------------------------------------------------

Write a program that takes a positive int and displays its prime factors on the
standard output, followed by a newline.

Factors must be displayed in ascending order and separated by '*', so that
the expression in the output gives the right result.

If the number of parameters is not 1, simply display a newline.

The input, when there's one, will be valid.

Examples:

$> ./fprime 225225 | cat -e
3*3*5*5*7*11*13$
$> ./fprime 8333325 | cat -e
3*3*5*5*7*11*13*37$
$> ./fprime 9539 | cat -e
9539$
$> ./fprime 804577 | cat -e
804577$
$> ./fprime 42 | cat -e
2*3*7$
$> ./fprime 1 | cat -e
1$
$> ./fprime | cat -e
$
$> ./fprime 42 21 | cat -e
$
*/

#include <stdlib.h>
#include <stdio.h>

int		find_prime(int b)
{
	int		a;

	a = b - 1;
	while (a > 1)
	{
		if (b % a == 0)
		{
			a = b;
			b++;
		}
		a--;
	}
	return (b);	
}

int		fprime(char *s)
{
	unsigned int	nb;
	char			*start;
	int				flag;
	int				b;
	int				i;
	char			fin[100];

	start = s;
	flag = 0;
	if (s[0] == 1)
	{
		printf("%d\n", 1);
		return (0);
	}
	while (*s)
	{
		if (*s >= '0' && *s <= '9')
			s++;
		else
			return (-1);
	}
	nb = atoi(start);
	b = 2;
	i = 0;
	while (nb > 0)
	{
		if (nb % b == 0)
		{
			if (b > 9)
			{
				fin[i++] = b / 10 + '0';
				fin[i] = b % 10 + '0';
			}
			else
				fin[i] = b + '0';
			nb /= b;
			b = 2;
			if (nb != 1)
			{
				fin[i + 1] = '*';
				i += 2;
			}
			else
			{
				fin[i + 1] = '\0';
				break ;
			}
		}
		else
			b++;
		b = find_prime(b);
	}
	printf("%s\n", fin);
	return (0);
}

int		main(int argc, char **argv)
{
	if (argc == 2 && argv[1][0] != '0')
		fprime(argv[1]);
	else
		printf("\n");
	return (0);
}
