/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwartell <cwartell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 17:15:08 by cwartell          #+#    #+#             */
/*   Updated: 2019/04/10 18:43:12 by cwartell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls_lib.h"

void	dir_save_print_dive(t_info list, t_opt options)
{
	struct dirent	*read;
	DIR				*d;
	char			*filepath;

	d = opendir(list->filename);
	//if (options R l)
	while ((read = readdir(d)) != NULL)
	{
		filepath = create_filepath(read->d_name, list->filename);
		file_save(list);

	}
	/*else
	{
		while (list)
		{
			print
			list = list->next
		}
	}
		*/
}
