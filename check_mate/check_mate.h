/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_mate.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschmele <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 11:43:35 by sschmele          #+#    #+#             */
/*   Updated: 2019/04/29 15:37:30 by sschmele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_MATE_H
# define CHECK_MATE_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

void	print_map(char **map);
int		ft_strlen(char *s);
void	check_mate(char **map, int size);
int		check_validity(char **map, int size);
int		check_result(char **map, int size, short i, short j);

#endif
