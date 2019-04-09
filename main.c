/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwartell <cwartell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 14:23:22 by cwartell          #+#    #+#             */
/*   Updated: 2019/04/08 19:05:41 by cwartell         ###   ########.fr       */
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
	printf("start %s\n", *av);

	list = av_to_list(av);
	printf(" b4 %s\n", (list)->filename);
	print_invalid(&list, options);
	printf("after %s\n", (list)->filename);
	// save_print_files(list, options);
	// save_print_folders(list, options);
	return (0);
}

void	swap_node(void** list, int (*fun)(void*, ...))
{
	t_filename *cur;
	t_filename *tmp;
	t_filename *st;

	cur = *list;
	st = *list;

	while (cur->next)
	{
		// if (cur->is_exist == TRUE && cur->next->is_exist == FALSE)
		if (fun(cur->is_exist, cur->next->is_exist))
		{
			printf("before flip------ %s\n", cur->filename);
			tmp = cur->next;
			cur->next = tmp->next;
			tmp->next = cur;
			*list = (*list == cur) ? tmp : *list;
			st->next = (*list != tmp) ? tmp : st->next;
			cur = *list;
			printf("after flip------ %s\n", cur->filename);
		}
		else
		{
			st = cur;
			cur = cur->next;
		}
	}
}

int		is_exist(t_bool a, t_bool b)
{
	if (a == TRUE && b == FALSE)
		return (1);
	else
		return (0);
}

void	print_invalid(t_filename **list, t_opt options)
{
	/* Only affected by option f (no sort alpha) */
	t_bool a;
	t_bool b;

	int (*fun)(t_bool, t_bool);
	fun = &is_exist;
	swap_node(list, fun);
	// t_filename *ret;
	// t_filename *tmp;
	// t_filename *st;
    //
	// ret = *list;
	// st = *list;
    //
	// while (ret->next)
	// {
	// 	if (ret->is_exist == TRUE && ret->next->is_exist == FALSE)
	// 	{
	// 		printf("before flip------ %s\n", ret->filename);
	// 		tmp = ret->next;
	// 		ret->next = tmp->next;
	// 		tmp->next = ret;
	// 		*list = (*list == ret) ? tmp : *list;
	// 		st->next = (*list != tmp) ? tmp : st->next;
	// 		ret = *list;
	// 		printf("after flip------ %s\n", ret->filename);
	// 	}
	// 	else
	// 	{
	// 		st = ret;
	// 		ret = ret->next;
	// 	}
	// }
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
			list->is_exist = TRUE;
		if (S_ISDIR(stats.st_mode))
			list->is_fold = TRUE;
		printf("%s %s \t\t D?: %s\n", list->is_exist ? "true" : "false", list->filename,
		list->is_fold ? "true" : "false");
		list->next = (t_filename*)malloc(sizeof(t_filename));
		list = list->next;
		i++;
		list->next = NULL;
	}
	printf("%s\n", (ret)->filename);
	return (ret);
}


