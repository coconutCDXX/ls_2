/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwartell <cwartell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 17:15:08 by cwartell          #+#    #+#             */
/*   Updated: 2019/05/01 19:54:03 by cwartell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls_lib.h"

/*
** Dir_control takes *list which has all folders from av or simply ./
** Creates a new linked list for each folder called *dive
*/

void	dir_control(t_info *list, t_opt options)
{
	char	*filepath;
	t_info	*dive;
	t_bool	a;

	a = TRUE;
	while (list != NULL)
	{
		dive = (t_info*)malloc(sizeof(t_info));
		filepath = dir_path_name(list->filepath, "./", list);
		dir_save(filepath, dive);
		file_save(dive);
		// printf("before sort the filepath: %s \n inside a dir: %s %s %s\n\n", filepath, dive->filename, dive->next->filename, dive->next->next->filename);
		list_sort(&dive, options, 2);
		// printf("the filepath: %s \n inside a dir: %s %s %s\n\n", filepath, dive->filename, dive->next->filename, dive->next->next->filename);
		if (a == FALSE)
			write(1, "\n", 1);
		a = FALSE;
		write(1, list->filepath, strlen(list->filepath));
		write(1, ":\n", 2);
		print_list(dive, options, 2);
		if (options.ur == TRUE)
			dir_dive(dive, options);
		list = list->next;
		free(dive);
	}
}

void	print_list(t_info *cur, t_opt options, int a)
{
	while (cur != NULL)
	{
		if (options.l == TRUE || options.g == TRUE || options.o == TRUE)
		{
			write(1, cur->str_rights, 10);
			write(1, "  ", 2);
			write(1, &cur->links, sizeof(cur->links));
			// printf("%d ", cur->links);
			write(1, cur->user_name, strlen(cur->user_name));
			write(1, "  ", 2);
			write(1, cur->grp_name, strlen(cur->grp_name));
			write(1, "  ", 2);
			write(1, " \t", 2);
			write(1, cur->date + 4, 12);
			write(1, " ", 1);
		}
		write(1, cur->filename, strlen(cur->filename));
		putchar('\n');
		if (a == 1)
			return ;
		cur = cur->next;
	}
}
/*
** dir_dive does the recursion, links to sorting and printing of each DIR
*/

void	dir_dive(t_info *dive, t_opt options)
{
	char	*filepath;
	t_info	*deep;
	//sort
	while (dive != NULL)
	{
		if (dive->str_rights[0] == 'd' && (strcmp(dive->filename, "..") != 0)
		&& (strcmp(dive->filename, ".") != 0))
		{
			deep = (t_info*)malloc(sizeof(t_info));
			dir_save(dive->filepath, deep);
			file_save(deep);
			list_sort(&deep, options, 2);
			write(1, "\n", 1);
			write(1, deep->filepath, strlen(deep->filepath));
			write(1, ":\n", 2);
			print_list(deep, options, 2);
			dir_dive(deep, options);
		}
		dive = dive->next;
	}
}

/*
** dir_save opens up a DIR and saves all the files into the given linked list
** also updates the filepath
*/

void	dir_save(char *filepath, t_info *dive)
{
	struct dirent	*read;
	DIR				*d;
	char			*name;

	d = opendir(filepath);
	dive->filepath = NULL;
	while ((read = readdir(d)) != NULL)
	{
		if (dive->filepath != NULL)
		{
			dive->next = (t_info*)malloc(sizeof(t_info));
			dive = dive->next;
		}
		// printf("im reading\n");
		dive->filepath = dir_path_name(read->d_name, filepath, dive);
		// printf("inside %s: %s\n", filepath, dive->filename);
	}
	dive->next = NULL;
	closedir(d);
}

char	*dir_path_name(char *name, char *root, t_info *list)
{
	char	*ret;
	int		i;

	i = 0;
	// if (!(strcmp(root, "./")))
	// {
	// 	if (!(strcmp(name, "./")))
	// 		return(root);
	// 	ret = (char*)malloc(sizeof(char) * (strlen(name) + strlen(root) + 1));
	// 	strcpy(ret, root);
	// }
	if (!(strcmp(root, "./")) && !(strcmp(name, "./")))
		return (root);
	else
	{
		ret = (char*)malloc(sizeof(char) * (strlen(name) + strlen(root) + 2));
		strcpy(ret, root);
		strcat(ret, "/");
	}
	strcat(ret, name);
	list->filename = (char*)malloc(sizeof(char) * (strlen(name) + 1));
	strcpy(list->filename, name);
	while ((list->filename[i]) != '\0')
	{
		if ((list->filename[i]) < 0x20 || (list->filename[i]) > 0x7e)
			(list->filename[i]) = '?';
		i++;
	}
	return (ret);
}
//
// if (!(strcmp(root, "./")) && !(strcmp(name, "./")))
// 	return (root);
// else if (!(strcmp(root, "./")))
// {
// 	ret = (char*)malloc(sizeof(char) * (strlen(name) + strlen(root) + 1));
// 	strcpy(ret, root);
// }
// else
// {
// 	ret = (char*)malloc(sizeof(char) * (strlen(name) + strlen(root) + 2));
// 	strcpy(ret, root);
// 	strcat(ret, "/");
// }
// char isprint (unsigned char c)
// {
//     if ( c >= 0x20 && c <= 0x7e )
//         return 1;
//     return 0;
// }
