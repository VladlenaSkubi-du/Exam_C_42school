/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fprime.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschmele <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 16:43:24 by sschmele          #+#    #+#             */
/*   Updated: 2019/05/05 16:34:02 by sschmele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int		fprime(char *s)
{
	unsigned int	nb;
	char			*start;
	unsigned int	b;

	start = s;
	while (*s)
	{
		if (*s >= '0' && *s <= '9')
			s++;
		else
			return (-1);
	}
	nb = atoi(start);
	if (nb == 1 || nb == 2147483647)
	{
		printf("%d\n", ((nb == 1) ? 1 : 2147483647));
		return (0);
	}
	while (1)
	{
		b = 1;
		while (++b <= nb)
		{
			if (nb % b == 0)
			{
				printf("%d", b);
				nb = nb / b;
				break ;
			}
		}
		if (nb == 1)
			break ;
		else
			printf("*");
	}
	printf("\n");
	return (0);
}

int		main(int argc, char **argv)
{
	int		tmp;

	if (argc == 2 && argv[1][0] != '0' && argv[1][0] != 0)
	{
		if ((tmp = fprime(argv[1])) == -1)
			printf("\n");
	}
	else
		printf("\n");
	return (0);
}
