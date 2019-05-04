/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cycle_detector.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschmele <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 17:26:20 by sschmele          #+#    #+#             */
/*   Updated: 2019/05/03 19:20:38 by sschmele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include <stdio.h>

int		cycle_detector(const t_list *list)
{
	const t_list	*tmp1;
	const t_list	*tmp2;

	if (!list)
		return (1);
	tmp1 = list;
	tmp2 = tmp1;
	while (tmp1 && tmp2)
	{
		if (tmp1->next)
			tmp1 = tmp1->next;
		if (tmp2->next && tmp2->next->next)
			tmp2 = tmp2->next->next;
		else
			return (0);
		if (tmp1 == tmp2)
			return (1);
	}
	return (0);
}
