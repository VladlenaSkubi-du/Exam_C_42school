/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rpn_calc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschmele <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 16:48:43 by sschmele          #+#    #+#             */
/*   Updated: 2019/04/16 16:54:36 by sschmele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rpn_calc.h"

/*Test for invalid_first:
 *-"100+ 677 *"
 *-"100 64"
 *-"100 64+ +"
 *-"100 64 **"
 *-"100 64 6 * * "
 *-"100 64 6 * * 5 ++"
 *-"100 64 6 * * 5 + +"
 *-"100 64 6 * * 5 1000 4563 + +"
 * Assignment name  : rpn_calc
Expected files   : *.c, *.h 
Allowed functions: atoi, printf, write, malloc, free
--------------------------------------------------------------------------------

Write a program that takes a string which contains an equation written in
Reverse Polish notation (RPN) as its first argument, evaluates the equation, and
prints the result on the standard output followed by a newline. 

Reverse Polish Notation is a mathematical notation in which every operator
follows all of its operands. In RPN, every operator encountered evaluates the
previous 2 operands, and the result of this operation then becomes the first of
the two operands for the subsequent operator. Operands and operators must be
spaced by at least one space.

You must implement the following operators : "+", "-", "*", "/", and "%".

If the string isn't valid or there isn't exactly one argument, you must print
"Error" on the standard output followed by a newline.

All the given operands must fit in a "int".

Examples of formulas converted in RPN:

3 + 4                   >>    3 4 +
((1 * 2) * 3) - 4       >>    1 2 * 3 * 4 -  ou  3 1 2 * * 4 -
50 * (5 - (10 / 9))     >>    5 10 9 / - 50 *

Here's how to evaluate a formula in RPN:

1 2 * 3 * 4 -
2 3 * 4 -
6 4 -
2

Or:

3 1 2 * * 4 -
3 2 * 4 -
6 4 -
2

Examples:

$> ./rpn_calc "1 2 * 3 * 4 +" | cat -e
10$
$> ./rpn_calc "1 2 3 4 +" | cat -e
Error$
$> ./rpn_calc |cat -e
Error$
*/

int		main(int argc, char **argv)
{
	if (argc == 2)
		rpn_calc(argv[1]);
	else
		write(1, "Error\n", 6);
	return (0);
}

void	rpn_calc(char *s)
{
	int		*nums;
	char	*signs;
	int		len;

	len = ft_strlen(s);
	if (first_invalidity(s, len) == 1)
		write(1, "Error\n", 6);
	else
	{
		//printf("%d	%d	%d\n", len, len - len / 2 - len / 2 / 2, len / 2);
		nums = (int*)malloc(sizeof(int) * (len - len / 2 - len / 2 / 2));
		signs = (char*)malloc(sizeof(char) * (len / 2));

		fill_the_arrays(s, len, nums, signs);
	}
}

/*
 * Everything that we can check in the string:
 * -the first and the last char;
 * -the length of the string - not less than parameters: "1 2 *";
 * -there are other than needed letters;
 * -there int more than one space between the letters;
 * -there is more than one operand one after another;
 */

int		first_invalidity(char *s, int len)
{
	int		i;
	int		sign;
	int		space;
	int		nb;

	i = 0;
	sign = 0;
	space = 0;
	nb = 0;
	if (len < 5)
		return (1);
	if (!(s[0] >= '0' && s[0] <= '9'))
		return (1); //the first char
	if (!(s[len - 1] == '+' || s[len - 1] == '-' || s[len - 1] == '*' ||
				s[len - 1] == '/' || s[len - 1] == '%'))
		return (1); //the last char
	while (s[i])
	{
		if (!((s[i] >= '0' && s[i] <= '9') || s[i] == ' ' || s[i] == '+' ||
					s[i] == '-' || s[i] == '*' || s[i] == '/' || s[i] == '%'))
			return (1); //not the needed letters
		while ((s[i] >= '0' && s[i] <= '9') && s[i])
		{
			nb = 1;
			i++;
		}
		if (nb == 1 && s[i] != ' ')
			return (1); //not a space after a nb
		else
			i++;
		while ((s[i] == '+' || s[i] == '-' || s[i] == '*' ||
					   	s[i] == '/' || s[i] == '%') && s[i])
		{
			i++;
			sign++;
		}
		if (sign > 1)
			return (1); //there are two and more operands one after another
		if (s[i] == ' ' && s[i + 1] == ' ')
			return (1); //there is double space
		else if (s[i] == ' ')
			i++;
		sign = 0;
		nb = 0;
	}
	return (0);
}

void	fill_the_arrays(char *s, int len, int *nums, char *signs)
{
	int		i;
	int		j;
	int		space;
	char	*p;

	i = 0;
	j = 0;
	space = 0;
	p = s;
	while (*s)
	{	
		if (*s >= '0' && *s <= '9')
		{
			while (*s >= '0' && *s <= '9' && *s)
				s++;
			nums[i] = atoi(p);
			//printf("p string =%s, s string =%s\n", p, s);
			i++;
		}
		if (*s == ' ')
			space++;
		else if (*s == '+' || *s == '-' || *s == '*' || *s == '/' || *s == '%')
		{
			signs[j] = *s;
			j++;
		}
		printf("num = %d, signs = %s, space = %d\n", nums[j], signs, space);
		p = s;
		s++;
	}
}

int		ft_strlen(char *s)
{
	int		len;

	len = 0;
	while (*s++)
		len++;
	return (len);
}
