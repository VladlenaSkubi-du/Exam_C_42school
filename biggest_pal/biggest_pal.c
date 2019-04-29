/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   biggest_pal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschmele <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 16:49:52 by sschmele          #+#    #+#             */
/*   Updated: 2019/04/29 18:02:41 by sschmele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Assignment name  : biggest_pal
Expected files   : *.c, *.h
Allowed functions: write
--------------------------------------------------------------------------------

Write a program named biggest_pal that takes a string as argument and prints the
biggest palindrome included inside this string, followed by a newline.

This string contains only lowercase characters.

If there is two palindromes of the same length, you have to print the last one.

If there is more or less than 1 argument, your program must print only a newline
only.

Exemples:

$> biggest_pal "abcba"
abcba
$> biggest_pal "aaaaaaaaaabbcbbaaaa"
aaaabbcbbaaaa
$> biggest_pal "aooibdaoiwhoihwdoinzeldaisaboyobasiadlezfdsfnslk"
zeldaisaboyobasiadlez
$> biggest_pal "aeibaabaammaabaalek"
aabaammaabaa
$> biggest_pal abeb qpinqwjobo qkmnwoiq

$> biggest_pal

$>*/

#include "biggest_pal.h"

int		ft_strlen(char *s)
{
	char	*start;

	start = s;
	while (*s)
		s++;
	return (s - start);
}

void	ft_putstrtill(char *s, int i)
{
	char	*start;
	int		len;

	start = s;
	len = 0;
	while (s[len] && s[len] != s[i])
		len++;
	start[len + 1] = '\0';
	write(1, start, len + 1);
}

void	biggest_pal(char *s)
{
	int		len;
	int		i;
	char	*p;

	i = 1;
	p = s;
	len = ft_strlen(p);
	if (len == 1)
		write(1, p, 1);
	if (len == 2)

}

int		main(int argc, char **argv)
{
	if (argc == 2)
		biggest_pal(argv[1]);
	else
		write(1, "\n", 1);
	return (0);
}
