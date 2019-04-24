/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwartell <cwartell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 17:15:08 by cwartell          #+#    #+#             */
/*   Updated: 2019/04/23 16:43:51 by cwartell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls_lib.h"

void	dir_control(t_info *list, t_opt options)
{
	char	*filepath;
	t_info	*dive;

	while (list != NULL)
	{
		dive = (t_info*)malloc(sizeof(t_info));
		filepath = dir_path_name(list->filepath, "./", list);
		dir_save(filepath, dive);
		file_save(dive);
		printf("the filepath: %s \n inside a dir: %s %s\n\n", filepath, dive->filepath, dive->next->filepath);
		// if (recursive)
		dir_print_dive(dive, options);
		list = list->next;
		free(dive);
	}
}

void	dir_print_dive(t_info *dive, t_opt options)
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
			//print
			dir_print_dive(deep, options);
		}
		dive = dive->next;
	}
}

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
		printf("im reading\n");
		dive->filepath = dir_path_name(read->d_name, filepath, dive);
		printf("inside %s: %s\n", filepath, dive->filename);
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
