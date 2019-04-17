/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwartell <cwartell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 18:46:57 by cwartell          #+#    #+#             */
/*   Updated: 2019/04/16 22:38:38 by cwartell         ###   ########.fr       */
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
	// swap_node(list, f_alpha);
	swap_node(list, f_isdir);
	cur = *list;
	printf("after swapnodes 1.%s 2.%s 3.%s\n", (cur)->filename, (cur)->next->filename, (cur)->next->next->filename);

	//if (long_listing)
		file_save(cur);
	// file_print(list);
	// printf("the rights %s\n%s\n", cur->str_rights, cur->next->str_rights);
	while (cur->is_dir == FALSE && cur->next != NULL)
	{
		/* TODO free struct as you pop */
		printf("i poped this%s\n", cur->filename);
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
	cur->str_rights[0] = (S_ISDIR(stats.st_mode)) ? 'd' : '-';
	cur->str_rights[1] = (stats.st_mode & S_IRUSR) ? 'r' : '-';
	cur->str_rights[2] = (stats.st_mode & S_IWUSR) ? 'w' : '-';
	cur->str_rights[3] = (stats.st_mode & S_IXUSR) ? 'x' : '-';
	cur->str_rights[4] = (stats.st_mode & S_IRGRP) ? 'r' : '-';
	cur->str_rights[5] = (stats.st_mode & S_IWGRP) ? 'w' : '-';
	cur->str_rights[6] = (stats.st_mode & S_IXGRP) ? 'x' : '-';
	cur->str_rights[7] = (stats.st_mode & S_IROTH) ? 'r' : '-';
	cur->str_rights[8] = (stats.st_mode & S_IWOTH) ? 'w' : '-';
	cur->str_rights[9] = (stats.st_mode & S_IXOTH) ? 'x' : '-';
	cur->str_rights[10] = '\0';
	printf("the rights: %s->%s \n\n", cur->filename, cur->str_rights);

	file_save_more(cur, stats);
	if (cur->next != NULL)
		file_save(cur->next);
}

void		file_save_more(t_info *cur, t_stat stats)
{
	struct passwd	*usr;
	struct group	*grp;
	int				l;

	// printf("************************%s\n", cur->filename);
	// usr = getpwuid(stats.st_uid);
	// l = strlen(usr->pw_name);
	// cur->user_name = (char*)malloc(sizeof(char) * l + 1);
	// strcpy(cur->user_name, usr->pw_name);
	// grp = getgrgid(stats.st_gid);
	// l = strlen(grp->gr_name);
	// cur->grp_name = (char*)malloc(sizeof(char) * l + 1);
	// strcpy(cur->grp_name, grp->gr_name);
	// cur->bytes = stats.st_size;
}

void		file_print(t_bool ll, t_info *cur, t_opt options)
{
	if (ll == TRUE)
	{

	}
	else
	{
		//TODO spacing print

	}
}














