/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   biggest_pal.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschmele <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 17:15:28 by sschmele          #+#    #+#             */
/*   Updated: 2019/04/30 18:13:22 by sschmele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BIGGEST_PAL_H
# define BIGGEST_PAL_H

# include <unistd.h>
# include <stdio.h>

void	biggest_pal(char *s);
int		ft_strlen(char *s);
int		check(char *s, int len);
void	ft_putnstr(char *s, int i);

#endif
