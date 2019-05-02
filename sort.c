/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwartell <cwartell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 15:22:07 by cwartell          #+#    #+#             */
/*   Updated: 2019/05/01 19:04:03 by cwartell         ###   ########.fr       */
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
			// printf("before flip------ %s\n", cur->filepath);
			tmp = cur->next;
			cur->next = tmp->next;
			tmp->next = cur;
			// printf("after flip------ %s\n", tmp->filepath);
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

void	list_sort(t_info **dive, t_opt options, int a)
{
	int		(*f_alpha)(t_info *cur);
	int		(*f_size)(t_info *cur);
	int		(*f_time)(t_info *cur);
	int		(*f_nosort)(t_info *cur);

	f_alpha = &s_alpha;
	f_size = &s_size;
	f_time = &s_time;
	f_nosort = &s_nosort;
	if (options.f == TRUE)
	{
		if (a == 1)
			return ;
		swap_node(dive, f_nosort);
		return ;
	}
	swap_node(dive, f_alpha);
	if (options.t == TRUE && options.us == FALSE)
		swap_node(dive, f_time);
	if (options.us == TRUE)
		swap_node(dive, f_size);
	if (options.r == TRUE)
		sort_rev(dive);
}

int		s_alpha(t_info* cur)
{
	int j;
	int i;

	j = -1;
	i = -1;
	// printf("cur %s curnext %s\n", cur->filename, cur->next->filename);
	// if (!(strcmp(cur->filename, ".")) || (!(strcmp(cur->filename, ".."))
	// && strcmp(cur->next->filename, ".") != 0))
	// 	return (0);
	// if (!(strcmp(cur->next->filename, ".")) || (!(strcmp(cur->next->filename, ".."))
	// && strcmp(cur->filename, ".") != 0))
	// 	return (1);
	while (cur->filename[++j] == cur->next->filename[++i])
		;
	// printf("passed these\n");
	// if (cur->filename[j] >= 65 && cur->filename[j] <= 90 && !(cur->next->filename[i] >= 65 && cur->next->filename[i] <= 90))
	// {
	// 	if (cur->filename[j] > cur->next->filename[i])
	// 		return (1);
	// 	else
	// 		return (0);
	// }
	// if (cur->next->filename[i] >= 65 && cur->next->filename[i] <= 90 && !(cur->filename[j] >= 65 && cur->filename[j] <= 90))
	// {
	// 	if (cur->next->filename[i] < cur->filename[j])
	// 		return (1);
	// 	else
	// 		return (0);
	// }
	// if (cur->filename[j] > cur->next->filename[i])
	// 	return (1);
	// return (0);
	if (cur->filename[j] >= 65 && cur->filename[j] <= 90
	&& !(cur->next->filename[i] >= 65 && cur->next->filename[i] <= 90))
		if (cur->filename[j] > cur->next->filename[i])
			return (1);
	if (cur->next->filename[i] >= 65 && cur->next->filename[i] <= 90
	&& !(cur->filename[j] >= 65 && cur->filename[j] <= 90))
		if (cur->next->filename[i] < cur->filename[j])
			return (1);
	if (cur->filename[j] > cur->next->filename[i])
		return (1);
	return (0);
}

void		sort_rev(t_info **dive)
{
	t_info *cur;
	t_info *prev;
	t_info *next;

	cur = *dive;
	prev = NULL;
	next = NULL;
	while (cur != NULL)
	{
		next = cur->next;
		cur->next = prev;
		prev = cur;
		cur = next;
	}
	*dive = prev;
}
















