/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   biggest_pal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschmele <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 18:59:26 by sschmele          #+#    #+#             */
/*   Updated: 2019/04/30 19:01:07 by sschmele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "biggest_pal.h"

int		ft_strlen(char *s)
{
	char	*start;

	start = s;
	while (*s)
		s++;
	return (s - start);
}

void	ft_putnstr(char *s, int len)
{
	char	*start;
	int		nb;

	start = s;
	nb = 0;
	while (s[nb] && s[nb] != s[len])
		nb++;
	start[len] = '\0';
	write(1, start, len);
}

int		check(char *s, int len)
{
	int		i;
	int		j;

	i = 0;
	j = len - 1;
	while (i != j && j >= 0 && i < len)
	{
		if (s[i] != s[j])
			return (-1);
		i++;
		j--;
	}
	return (1);
}

void	biggest_pal(char *s)
{
	int		i;
	int		j;
	int		k;
	char	*start;
	int		fin;
	int		len;
	int		tmp;

	i = 0;
	j = 0;
	k = 0;
	start = s;
	len = 1;
	while (s[i])
	{
		fin = ft_strlen(s + i);
		while ((tmp = check(s + i, fin - k)) != 1)
			k++;
		if (tmp == 1)
			if (fin - k > len)
			{
				start = &s[i + j];
				len = fin - k;
				fin -= k;
			}
		k = 0;
		while ((tmp = check(s + i + j, fin - k)) != 1)
		{
			k += 2;
			j++;
		}
		if (tmp == 1)
			if (fin - k > len)
			{
				start = &s[i + j];
				len = fin - k;
				fin -= k;
			}
		j = 0;
		k = 0;
		i++;
	}
	if (len == 1)
		write(1, &s[ft_strlen(s) - 1], 1);
	else
		ft_putnstr(start, len);
}

int		main(int argc, char **argv)
{
	if (argc == 2)
		biggest_pal(argv[1]);
	write(1, "\n", 1);
	return (0);
}
