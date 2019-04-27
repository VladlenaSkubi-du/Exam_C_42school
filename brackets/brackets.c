/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brackets.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschmele <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 16:47:44 by sschmele          #+#    #+#             */
/*   Updated: 2019/04/27 18:22:15 by sschmele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**Tests:
**./a.out '{{[(   ) (   )]  ((  ))}  [((  )  )]}'
*/

#include "brackets.h"

int		invalid(char *s)
{
	int		i;
	int		max;
	int		flag;

	i = 0;
	max = 0;
	flag = 0;
	while (s[i])
	{
		if (s[i] == '(' || s[i] == '[' || s[i] == '{')
		{
			flag++;
			max++;
		}
		if (s[i] == ')' || s[i] == ']' || s[i] == '}')
			flag--;
		i++;
	}
	if (flag != 0)
		return (-1);
	return (max);
}

int		check(char *s, int max)
{
	int		i;
	int		flag;

	i = 0;
	flag = 0;
	if (max == 0)
		return (1);
	while (s[i] && max)
	{
		if (s[i] == '{')
		{
			while (s[i] != '}' && s[i])
			{
				if (s[i] == '{')
					check(&s[i + 1], max);
				if (s[i] == '(' || s[i] == '[')
					flag++;
				if (s[i] == ')' || s[i] == ']')
					flag--;
				i++;
			}
			if (flag != 0)
				return (-1);
			max--;
		}
		else if (s[i] == '[')
		{
			while (s[i] != ']' && s[i])
			{
				if (s[i] == '[')
					check(&s[i + 1], max);
				if (s[i] == '(' || s[i] == '{')
					flag++;
				if (s[i] == ')' || s[i] == '}')
					flag--;
				i++;
			}
			if (flag != 0)
				return (-1);
			max--;
		}
		else if (s[i] == '(')
		{
			while (s[i] != ')' && s[i])
			{
				if (s[i] == '(')
					check(&s[i + 1], max);
				if (s[i] == '[' || s[i] == '{')
					flag++;
				if (s[i] == ']' || s[i] == '}')
					flag--;
				i++;
			}
			if (flag != 0)
				return (-1);
			max--;
		}
		i++;
	}
	return (1);
}

void	brackets(char **arr)
{
	int		i;
	int		max;

	i = 0;
	while (arr[i])
	{
		max = invalid(arr[i]);
		if (max == 0)
			write(1, "OK\n", 3);
		else if (max > 0)
		{
			if (check(arr[i], max) == 1)
				write(1, "OK\n", 3);
			else
				write(1, "Error\n", 6);
		}
		else if (max < 0)
			write(1, "Error\n", 6);
		i++;
	}
}

int		main(int argc, char **argv)
{
	if (argc > 1)
		brackets(&argv[1]);
	else
		write(1, "\n", 1);
	return (0);
}
