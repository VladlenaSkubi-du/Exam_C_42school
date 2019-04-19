/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brainfuck.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschmele <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 19:48:01 by sschmele          #+#    #+#             */
/*   Updated: 2019/04/19 14:19:25 by sschmele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**The easiest test: "+++++[>++++++++++<-]>++.--."
**Test with four cycles: "+[>+++++[>++++[>++++[>+>+<<-]<-]>>-->+<<<<-]<-]>>>>++.>.<+."
**Comments: malloc is not needed, in conditions for '[' and ']' if is very
**necessary that i++ and i-- stay before ifs.
*/

#include <unistd.h>
#include <stdlib.h>

void		brainfuck(char *s, char *str)
{
	int		i;
	int		j;
	int		flag;

	i = 0;
	j = 0;
	flag = 0;
	while (s[i])
	{
		if (s[i] == '+')
			str[j]++;
		else if (s[i] == '-')
			str[j]--;
		else if (s[i] == '>')
			j++;
		else if (s[i] == '<')
			j--;
		else if (s[i] == '.')
			write(1, &str[j], 1);
		if (s[i] == '[' && str[j] == 0)
		{
			flag = 1;	
			while (flag)
			{
				i++;
				if (s[i] == '[')
					flag++;
				else if (s[i] == ']')
					flag--;
			}
		}
		if (s[i] == ']' && str[j])
		{
			flag = 1;
			while (flag)
			{
				i--;
				if (s[i] == ']')
					flag++;
				else if (s[i] == '[')
					flag--;
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
	else
		write(1, "\n", 1);
	return (0);
}
