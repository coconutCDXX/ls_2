/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwartell <cwartell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 14:23:22 by cwartell          #+#    #+#             */
/*   Updated: 2019/04/05 19:23:05 by cwartell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls_lib.h"

int			main(int ac, char **av)
{
	t_opt 		options;
	t_filename	*list;

	// options = find_options(av);
	av++;
	while (*(*av) == '-')
		av++;
	printf("%s\n", *av);

	list = av_to_list(av);
	printf("%s\n", (list)->filename);
	// print_invalid(&list, options);
	// save_print_files(list, options);
	// save_print_folders(list, options);
	return (0);
}

void		print_invalid(t_filename **list, t_opt options)
{
	/* Only affected by option f (no sort alpha) */

	int 	i;
	t_stat	stats;

	// if f go thru struct and print as you find then sort
	//else sort by alpha and print
	// sort should be invalid 1st/ files 2nd/ folders 3rd
	//if room then pop invalids
	i = 0;

}
void		save_print_files(char **av, t_opt options)
{
	t_info	*sinfo;
	int		i;

	i = 1;
	sinfo = (t_info*)malloc(sizeof(t_info));

}

t_filename*	av_to_list(char **av)
{
	int			i;
	t_stat		stats;
	t_filename	*list;
	t_filename	*ret;

	i = 0;
	list = (t_filename*)malloc(sizeof(t_filename));
	ret = list;
	printf("%s\n", *av);
	while (av[i] != '\0')
	{
		list->filename = (char*)malloc(sizeof(char) * strlen(av[i]) + 1);
		strcpy(list->filename, av[i]);
		if ((stat((av[i]), &stats)) == -1)
			list->is_exist = FALSE;
		else
		{
			list->is_exist = TRUE;
			if (S_ISDIR(stats.st_mode))
				list->is_fold = TRUE;
		}
		printf("%s %s \t\t D?: %s\n", list->is_exist ? "true" : "false", list->filename,
		list->is_fold ? "true" : "false");
		list->next = (t_filename*)malloc(sizeof(t_filename));
		list = list->next;
		i++;
	}
	printf("%s\n", (ret)->filename);
	return (ret);
}


