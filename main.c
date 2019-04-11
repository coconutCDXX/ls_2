/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwartell <cwartell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 14:23:22 by cwartell          #+#    #+#             */
/*   Updated: 2019/04/10 17:15:02 by cwartell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls_lib.h"

int			main(int ac, char **av)
{
	t_opt 		options;
	t_info	*list;

	// options = find_options(av); TODO all the options
	av++;
	while (*(*av) == '-')
		av++;
	printf("start %s\n", *av);

	list = av_to_list(av);  // List created from av
	printf(" b4 %s\n", (list)->filename);
	invalid_print_pop(&list, options);  // 1. sort/print the bad files 2. free and pop them
	printf("after 1.%s 2.%s 3.%s\n", (list)->filename, (list)->next->filename, (list)->next->next->filename);

	/*print-files-pop: 1.sort files 2. save if long list 3. print 4. free and pop */

	file_save_print_pop(&list, options);
	printf("after 1.%s 2.%s 3.%s\n", (list)->filename, (list)->next->filename, (list)->next->next->filename);
	printf("file pop %s\n", list->filename);

	/* 1. sort if needed 2. save treename and all files (saving short or long)
	3. print and free and pop 4. repeat 2 and 3 until no more to go (if R)  */

	// dir_save_print_dive(list, options);
	return (0);
}



void	invalid_print_pop(t_info **list, t_opt options)
{
	/* Only affected by option f (no sort alpha) */
	t_info *cur;
	int (*f_exist)(t_info* cur);

	f_exist = &is_exist;
	cur = *list;
	swap_node(list, f_exist);
	/* TODO print the invalids (option f different sort then print) */
	while (cur->is_exist == FALSE)
	{
		/* TODO free struct as you pop */
		cur = cur->next;
	}
	*list = cur;
}

t_info*	av_to_list(char **av)
{
	int			i;
	t_stat		stats;
	t_info	*list;
	t_info	*ret;

	i = 0;
	list = (t_info*)malloc(sizeof(t_info));
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
			list->is_dir = TRUE;
		printf("%s %s \t\t D?: %s\n", list->is_exist ? "true" : "false", list->filename,
		list->is_dir ? "true" : "false");
		list->next = (t_info*)malloc(sizeof(t_info));
		list = list->next;
		i++;
		list->next = NULL;
	}
	printf("%s\n", (ret)->filename);
	return (ret);
}

void	swap_node(t_info** list, int (*f_exist)(t_info* cur))
{
	t_info *cur;
	t_info *tmp;
	t_info *st;

	cur = *list;
	st = *list;
	while (cur->next)
	{
		// if (cur->is_exist == TRUE && cur->next->is_exist == FALSE)
		if ((*f_exist)(cur))
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

int		is_dir(t_info* cur)
{
	if (cur->is_dir == TRUE && cur->next->is_dir == FALSE)
	return (1);
		else
	return (0);
}

int		is_exist(t_info* cur)
{
	if (cur->is_exist == TRUE && cur->next->is_exist == FALSE)
	return (1);
		else
	return (0);
}
