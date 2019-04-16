/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rpn_calc.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschmele <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 16:12:37 by sschmele          #+#    #+#             */
/*   Updated: 2019/04/16 16:54:38 by sschmele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_CALC_H
# define RPN_CALC_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

void		rpn_calc(char *s);
int			ft_strlen(char *s);
int			first_invalidity(char *s, int len);
void		fill_the_arrays(char *s, int len, int *nums, char *signs);


#endif
