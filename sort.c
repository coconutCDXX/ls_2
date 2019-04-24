/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwartell <cwartell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 15:22:07 by cwartell          #+#    #+#             */
/*   Updated: 2019/04/23 15:22:23 by cwartell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls_lib.h"

void	swap_node(t_info** list, int (*f_exist)(t_info* cur))
{
	t_info *cur;
	t_info *tmp;
	t_info *st;

	st = *list;
	cur = *list;
	while (cur->next)
	{
		// if (cur->is_exist == TRUE && cur->next->is_exist == FALSE)
		if ((*f_exist)(cur))
		{
			printf("before flip------ %s\n", cur->filepath);
			tmp = cur->next;
			cur->next = tmp->next;
			tmp->next = cur;
			printf("after flip------ %s\n", tmp->filepath);
			if (*list == cur)
				*list = tmp;
			else
				st->next = tmp;
			// *list = (*list == cur) ? tmp : *list;
			// st->next = (*list != cur) ? tmp : st->next;
			cur = *list;
		}
		else
		{
			st = cur;
			cur = cur->next;
		}
	}
}

int		is_dir(t_info* cur)
{
	if (cur->is_dir == TRUE && cur->next->is_dir == FALSE && cur->next != NULL)
		return (1);
	else
		return (0);
}

int		is_exist(t_info* cur)
{
	if (cur->is_exist == TRUE && cur->next->is_exist == FALSE
		&& cur->next !=NULL)
		return (1);
	else
		return (0);
}