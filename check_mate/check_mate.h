/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_mate.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschmele <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 11:43:35 by sschmele          #+#    #+#             */
/*   Updated: 2019/04/19 15:16:46 by sschmele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_MATE_H
# define CHECK_MATE_H

# include <unistd.h>
# include <stdlib.h>

typedef struct	s_list
{
	int			size;
	int			K_x;
	int			K_y;
}				t_list;

void	print_map(char **map);
int		ft_strlen(char *s);
void	check_mate(char **map, int size);
int		check_validity(char **map, int size);
void	check_result(t_list *chess);

#endif
