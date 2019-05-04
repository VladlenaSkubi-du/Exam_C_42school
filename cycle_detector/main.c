/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschmele <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 14:58:04 by sschmele          #+#    #+#             */
/*   Updated: 2019/05/04 14:59:22 by sschmele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include <stdio.h>

int		main(void)
{
	t_list	*list;
	t_list	*list1;
	t_list	*list2;
	t_list	*list3;
	t_list	*list4;

	list = malloc(sizeof(t_list));
	list->data = 0;
	list->next = NULL;

	list1 = malloc(sizeof(t_list));
	list1->data = 1;
	//list1->next = list;

	list2 = malloc(sizeof(t_list));
	list2->data = 2;
	list2->next = list1;

	list3 = malloc(sizeof(t_list));
	list3->data = 3;
	list3->next = list2;

	list4 = malloc(sizeof(t_list));
	list4->data = 4;
	list4->next = list3;

	list1->next = list4;

	printf("%d	%d	%d	%d	%d\n", list4->data,
			list4->next->data,
			list4->next->next->data,
			list4->next->next->next->data,
			list4->next->next->next->next->data);
	printf("%d\n", (cycle_detector(list4)));
	exit(0);
}
