/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwartell <cwartell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 17:15:08 by cwartell          #+#    #+#             */
/*   Updated: 2019/04/16 21:12:05 by cwartell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls_lib.h"

void	dir_save_print_dive(t_info *list, t_opt options)
{
	// struct dirent	*read;
	// DIR				*d;
	// char			*filepath;
	// t_info			*dive;
	// t_info			*deep;
    //
	// d = opendir(list->filename);
	// //if (options R l)
	// while (list != NULL)
	// {
	// 	dive = (t_info*)malloc(sizeof(t_info));
	// 	while ((read = readdir(d)) != NULL)
	// 	{
	// 		filepath = create_filepath(read->d_name, list->filename);
	// 		// file_save(list);
	// 		// print
	// 	}
    //
	// }
	char	*filepath;
	t_info	*dive;

	dive = (t_info*)malloc(sizeof(t_info));
	while (list != NULL)
	{
		filepath = create_filepath(list->filename, "./");
		dir_save(filepath, dive);
		file_save(dive);
		printf("the filepath: %s \n inside a dir: %s %s\n\n", filepath, dive->filename, dive->next->filename);
		// printf("the rights: %s->%s %s->%s\n\n\n", dive->filename, dive->str_rights, dive->next->filename, dive->next->str_rights);
		// if (dive != NULL)
		// 	dir_dive(dive);
		list = list->next;
	}
}

// t_info	*dir_save(char *filepath)
// {
// 	struct dirent	*read;
// 	DIR				*d;
// 	t_info			*dive;
// 	t_info			*ret;
//
// 	dive = (t_info*)malloc(sizeof(t_info));
// 	ret = dive;
// 	d = opendir(filepath);
// 	while ((read = readdir(d)) != NULL)
// 	{
//
// 		printf("im reading\n");
// 		dive->filename = create_filepath(read->d_name, filepath);
// 		// dive->filename = (char*)malloc(sizeof(char) * strlen(read->d_name) + 1);
// 		// strcpy(dive->filename, read->d_name);
// 		printf("inside %s: %s\n", filepath, dive->filename);
// 		dive->next = (t_info*)malloc(sizeof(t_info));
// 		dive = dive->next;
// 	}
// 	dive = NULL;
// 	closedir(d);
// 	return (ret);
// }

void	dir_save(char *filepath, t_info *dive)
{
	struct dirent	*read;
	DIR				*d;
	t_bool			a;

	d = opendir(filepath);
	a = TRUE;
	read = readdir(d);
	dive->filename = create_filepath(read->d_name, filepath);
	printf("inside %s: %s\n", filepath, dive->filename);
	while (a)
	{
		if ((read = readdir(d)) != NULL)
		{
			dive->next = (t_info*)malloc(sizeof(t_info));
			dive = dive->next;
			printf("im reading\n");
			dive->filename = create_filepath(read->d_name, filepath);
			// dive->filename = (char*)malloc(sizeof(char) * strlen(read->d_name) + 1);
			// strcpy(dive->filename, read->d_name);
			printf("inside %s: %s\n", filepath, dive->filename);
		}
		else
			a = FALSE;
	}
	dive->next = NULL;
	closedir(d);
}
char	*create_filepath(char *name, char *root)
{
	char	*ret;

	ret = (char*)malloc(sizeof(char) * strlen(name) + strlen(root) + 1);
	strcpy(ret, root);
	strcat(ret, name);
	return (ret);
}
