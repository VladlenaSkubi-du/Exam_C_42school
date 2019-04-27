/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rpn_calc2.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschmele <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 17:15:59 by sschmele          #+#    #+#             */
/*   Updated: 2019/04/27 18:26:57 by sschmele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_CALC_H
# define RPN_CALC_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct		s_stack
{
	int				nb;
	struct s_stack	*next;
}					t_stack;

void				rpn_calc(char *s);
int					invalidity(char *s, int len);
void				fill_the_stack(char *s, t_stack *nums);
int					pop_n(t_stack **head_n);
int					push_n(t_stack **head_n, int nb);
void				clean_stacks(t_stack **head);
int					ft_strlen(char *s);

#endif
