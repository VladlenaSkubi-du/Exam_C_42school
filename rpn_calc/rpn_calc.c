/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rpn_calc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschmele <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 16:48:43 by sschmele          #+#    #+#             */
/*   Updated: 2019/04/17 11:16:21 by sschmele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rpn_calc.h"

/*
**Test for invalid_first:
**-"100+ 677 *"
**-"100 64"
**-"100 64+ +"
**-"100 64 **"
**-"100 64 6 * * "
**-"100 64 6 * * 5 ++"
**-"100 64 6 * * 5 + +"
**-"100 64 6 * * 5 1000 4563 + +"
*/

int		main(int argc, char **argv)
{
	if (argc == 2)
		rpn_calc(argv[1]);
	else
		write(1, "Error\n", 6);
	return (0);
}

/*
**I tried to get rid of char *signs and not to write the same double times, but
**could not solve the problems that arise if we count when we meet operands.
**Better to collect everything and then count.
*/

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
		nums = (int*)malloc(sizeof(int) * (len - len / 2 - len / 2 / 2));
		signs = (char*)malloc(sizeof(int) * (len / 2));
		fill_the_arrays(s, nums, signs);
		free(nums);
		free(signs);
	}
}

/*
** Everything that we can check in the string:
** -the first and the last char;
** -the length of the string - not less than parameters: "1 2 *";
** -there are other than needed letters;
** -there int more than one space between the letters;
** -there is more than one operand one after another;
*/

int		first_invalidity(char *s, int len)
{
	int		i;
	int		sign;
	int		nb;

	i = 0;
	sign = 0;
	nb = 0;
	if (len < 5)
		return (1);
	if (!((s[0] >= '0' && s[0] <= '9') || s[0] == '-'))
		return (1); //the first char
	if (!(s[len - 1] == '+' || s[len - 1] == '-' || s[len - 1] == '*' ||
				s[len - 1] == '/' || s[len - 1] == '%'))
		return (1); //the last char
	while (s[i])
	{
		if (!((s[i] >= '0' && s[i] <= '9') || s[i] == ' ' || s[i] == '+' ||
					s[i] == '-' || s[i] == '*' || s[i] == '/' || s[i] == '%'))
			return (1); //not the needed letters
		if (s[i] == '-' && (s[i + 1] >= '0' && s[i + 1] <= '9'))
			i++; //for work with negative numbers
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

/*
**Second invalidity we can check after we have numbers that fit in an int and
**can compare with the nb of signs and spaces
**(I check spaces as a double check here)
*/

void	fill_the_arrays(char *s, int *nums, char *signs)
{
	int		i;
	int		j;
	int		space;
	char	*p;

	i = 0;
	j = 0;
	space = 0;
	while (*s)
	{
		p = s;
		if (*s == '-' && (*(s + 1) >= '0' && *(s + 1) <= '9'))
			s++; //for work with negative numbers
		if (*s >= '0' && *s <= '9')
		{
			while (*s >= '0' && *s <= '9' && *s)
				s++;
			nums[i] = atoi(p);
			i++;
		}
		if (*s == ' ')
			space++;
		else if (*s == '+' || *s == '-' || *s == '*' || *s == '/' || *s == '%')
		{
			signs[j] = *s;
			j++;
		}
		s++;
	}
	if (!((j + 1 == i) && (i + j - 1 == space)))
		write(1, "Error\n", 6); //second level of invalidity check
	else
		printf("%d\n", calculation(nums, signs));
}

int		calculation(int *nums, char *signs)
{
	int		res;
	int		i;
	int		j;

	res = nums[0];
	i = 0;
	j = 1;
	while (signs[i])
	{
		if (signs[i] == '+')
			res = res + nums[j];
		else if (signs[i] == '-')
			res = res - nums[j];
		else if (signs[i] == '*')
			res = res * nums[j];
		else if (signs[i] == '/')
			res = res / nums[j];
		else if (signs[i] == '%')
			res = res % nums[j];
		i++;
		j++;
	}
	return (res);
}

int		ft_strlen(char *s)
{
	int		len;

	len = 0;
	while (*s++)
		len++;
	return (len);
}
