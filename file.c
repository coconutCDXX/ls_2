/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwartell <cwartell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 18:46:57 by cwartell          #+#    #+#             */
/*   Updated: 2019/04/09 19:57:22 by cwartell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls_lib.h"

// void		file_print_pop(t_info **list)
// {
// 	t_info *cur;
//
// 	cur = *list;
// 	while (cur->is_fold == FALSE || cur =! NULL)
// 	{
// 		// TODO print-- spacing?
// 		cur = cur->next;
// 	}
// 	*list = cur;
// }

void		file_save_print_pop(t_info **list, t_opt options)
{
	/* TODO sort alpha and options and print */
	t_info *cur;
	int (*f_isdir)(t_info *cur);
	// int (f_alpha*)(t_info *cur);

	f_isdir = &is_dir;
	cur = *list;
	// swap_node(list, f_alpha);
	swap_node(list, f_isdir);
	//if (long_listing)
		file_save(cur);
	// print_file(list);

	while (cur->is_dir == FALSE || cur != NULL)
	{
		/* TODO free struct as you pop */
		cur = cur->next;
	}
	*list = cur;
}

void		file_save(t_info *cur)
{
	t_stat stats;

	stat(cur->filename, &stats);
	cur->date = (char*)malloc(sizeof(char) * 25);
	strcpy(cur->date, ctime(&stats.st_mtime));
	cur->date[24] = '\0';
	cur->time_sort = stats.st_mtime;
	cur->str_rights = (char*)malloc(sizeof(char) * 11);
	cur->str_rights[0] = '-';
	// (stats.st_mode & S_IRUSR) ? cur->str_rights[1] = 'r' : cur->str_rights[1] = '-';
	cur->str_rights[1] = (stats.st_mode & S_IRUSR) ? 'r' : '-';
}