/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_compare.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwartell <cwartell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 15:57:48 by cwartell          #+#    #+#             */
/*   Updated: 2019/05/01 15:58:45 by cwartell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls_lib.h"

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

int		s_time(t_info *cur)
{
	if (cur->time_sort < cur->next->time_sort)
		return (1);
	else
		return (0);
}

int		s_nosort(t_info *cur)
{
	if (!(strcmp(cur->filename, ".")) || (!(strcmp(cur->filename, ".."))
	&& strcmp(cur->next->filename, ".") != 0))
		return (0);
	if (!(strcmp(cur->next->filename, ".")) || (!(strcmp(cur->next->filename, ".."))
	&& strcmp(cur->filename, ".") != 0))
		return (1);
	return (0);
}

int		s_size(t_info *cur)
{
	if (cur->bytes < cur->next->bytes)
		return (1);
	else
		return (0);
}
