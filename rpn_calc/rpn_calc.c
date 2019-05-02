/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rpn_calc2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschmele <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 17:24:00 by sschmele          #+#    #+#             */
/*   Updated: 2019/05/02 17:02:21 by sschmele         ###   ########.fr       */
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

void	rpn_calc(char *s)
{
	int		len;
	t_stack	*nums;

	len = ft_strlen(s);
	if (invalidity(s, len) == -1)
		write(1, "Error\n", 6);
	else
	{
		if (!(nums = malloc(sizeof(t_stack))))
			write(1, "No space left\n", 14);
		else
		{
			nums->nb = 0;
			nums->next = NULL;
			fill_the_stack(s, nums);
			free(nums);
		}
	}
}

/*
** Everything that we can check in the string:
** -the first and the last char;
** -the length of the string - not less than parameters: "1 2 *";
** -there are other than needed letters;
** -there is more than one operand one after another;
** -there should be 1 nb more than the signs;
*/

int		invalidity(char *s, int len)
{
	int		i;
	int		nb;
	int		sign;
	int		num;
	int		si;

	i = 0;
	nb = 0;
	sign = 0;
	num = 0;
	si = 0;
	if (len < 5)
		return (-1);
	if (!(s[0] == '-' || (s[0] >= '0' && s[0] <= '9')))
		return (-1);
	if (!(s[len - 1] == '+' || s[len - 1] == '-' || s[len - 1] == '*'
				|| s[len - 1] == '/' || s[len - 1] == '%'))
		return (-1);
	while (s[i])
	{
		if (!((s[i] >= '0' && s[i] <= '9') || s[i] == ' ' || s[i] == '+'
					|| s[i] == '-' || s[i] == '*' || s[i] == '/' || s[i] == '%'))
			return (-1);
		if (s[i] == '-' && (s[i + 1] >= '0' && s[i + 1] <= '9'))
			i++;
		while (s[i] >= '0' && s[i] <= '9')
		{
			nb = 1;
			i++;
		}
		if (s[i] == ' ')
			while (s[i] == ' ')
				i++;
		else
			return (-1);
		while ((s[i] == '+' || s[i] == '-' || s[i] == '*' ||
				s[i] == '/' || s[i] == '%') &&
				(!(s[i + 1] >= '0' && s[i + 1] <= '9')))
		{
			sign++;
			i++;
		}
		if (sign > 1)
			return (-1);
		if (nb == 1)
			num++;
		if (sign == 1)
			si++;
		nb = 0;
		sign = 0;
	}
	if (si + 1 != num)
		return (-1);
	return (1);
}

void	fill_the_stack(char *s, t_stack *nums)
{
	char	*p;
	int		tmp;
	int		res;
	int		flag;

	flag = 0;
	while (*s)
	{
		if ((*s == '-' && (*(s + 1) >= '0' && *(s + 1) <= '9')) ||
				(*s >= '0' && *s <= '9'))
		{
			p = s;
			if (push_n(&nums, atoi(p)) == -2)
			{
				write(1, "No space left\n", 14);
				flag++;
				break ;
			}
			if (*s == '-')
				s++;
			while (*s >= '0' && *s <= '9')
				s++;
		}
		while (*s == ' ')
			s++;
		if ((*s == '+' || *s == '-' || *s == '*' || *s == '/' || *s == '%') &&
				!(*(s + 1) >= '0' && *(s + 1) <= '9'))
		{
			tmp = pop_n(&nums);
			res = pop_n(&nums);
			if (*s == '+')
				res += tmp;
			else if (*s == '-')
				res -= tmp;
			else if (*s == '*')
				res *= tmp;
			else if (*s == '/')
			{
				if (tmp == 0)
				{
					write(1, "Error\n", 6);
					flag++;
					break ;
				}
				res /= tmp;
			}
			else if (*s == '%')
			{
				if (tmp == 0)
				{
					write(1, "Error\n", 6);
					flag++;
					break ;
				}
				res %= tmp;
			}
			if (push_n(&nums, res) == -2)
			{
				write(1, "No space left\n", 14);
				flag++;
				break ;
			}
			s++;
		}
	}
	if (flag == 0)
		printf("%d\n", pop_n(&nums));
	if (flag > 0)
		clean_stacks(&nums);
}

int		pop_n(t_stack **head_n)
{
	int		res;
	t_stack	*tmp;

	tmp = *head_n;
	if ((*head_n)->next)
		*head_n = (*head_n)->next;
	res = tmp->nb;
	free(tmp);
	return (res);
}

int		push_n(t_stack **head_n, int nb)
{
	t_stack	*tmp;

	if (!(tmp = malloc(sizeof(t_stack))))
		return (-2);
	tmp->next = *head_n;
	tmp->nb = nb;
	*head_n = tmp;
	return (0);
}

void	clean_stacks(t_stack **head)
{
	t_stack	*tmp;

	while (*head)
	{
		tmp = *head;
		if ((*head)->next)
			(*head) = (*head)->next;
		free(tmp);
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
