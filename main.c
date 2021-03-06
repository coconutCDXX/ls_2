/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwartell <cwartell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 14:23:22 by cwartell          #+#    #+#             */
/*   Updated: 2019/05/01 19:31:35 by cwartell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls_lib.h"

int			main(int ac, char **av)
{
	t_opt 	options;
	t_info	*list;

	// memset(&options, 0, sizeof(options));
	options = find_options(av);
	// printf("a %s\n", options.a ? "TRUE" : "FALSE");
	// printf("l %s\n" ,options.l ? "TRUE" : "FALSE");
	// printf("R %s\n" ,options.ur ? "TRUE" : "FALSE");
	// printf("r %s\n", options.r ? "TRUE" : "FALSE");
	// printf("t %s\n" ,options.t ? "TRUE" : "FALSE");
	// printf("F %s\n", options.uf ? "TRUE" : "FALSE");
	// printf("G %s\n", options.ug ? "TRUE" : "FALSE");
	// printf("S %s\n", options.us ? "TRUE" : "FALSE");
	// printf("U %s\n", options.uu ? "TRUE" : "FALSE");
	// printf("f %s\n", options.f ? "TRUE" : "FALSE");
	// printf("g %s\n", options.g ? "TRUE" : "FALSE");
	// printf("o %s\n", options.o ? "TRUE" : "FALSE");
	// printf("p %s\n", options.p ? "TRUE" : "FALSE");
	// printf("u %s\n", options.u ? "TRUE" : "FALSE");

	if (ac == 1)
	{
		list = (t_info*)malloc(sizeof(t_info));
		list->filepath = (char*)malloc(sizeof(char) * 3);
		strcpy(list->filepath, "./");
		list->next = NULL;
		dir_control(list, options);
		exit (1);
	}
	av++;
	while (*(*av) == '-')
		av++;
	list = av_to_list(av);  // List created from av
	// printf(" b4 %s\n", (list)->filepath);
	invalid_print_pop(&list, options);  // 1. sort/print the bad files 2. free and pop them
	// printf("after invalids 1.%s 2.%s 3.%s\n", (list)->filepath, (list)->next->filepath, (list)->next->next->filepath);

	/*print-files-pop: 1.sort files 2. save if long list 3. print 4. free and pop */

	file_control_pop(&list, options);
	// printf("after filesave 1.%s 2.%s 3.%s\n", (list)->filepath, (list)->next->filepath, (list)->next->next->filepath);
	// printf("file pop %s\n", list->filepath);

	/* 1. sort if needed 2. save treename and all files (saving short or long)
	3. print and free and pop 4. repeat 2 and 3 until no more to go (if R)  */

	dir_control(list, options);
	return (0);
}



void	invalid_print_pop(t_info **list, t_opt options)
{
	t_info	*cur;/* Only affected by option f (no sort alpha) */
	int (*f_exist)(t_info *cur);
	int	(*f_alpha)(t_info *cur);

	f_exist = &is_exist;
	f_alpha = &s_alpha;
	if (options.f == FALSE)
		swap_node(list, f_alpha);
	swap_node(list, f_exist);
	cur = *list;
	while (cur->is_exist == FALSE)
	{
		// write(1, cur->filename, strlen(cur->filename));
		// perror("No such file or directory");
		write(1, "ls:  ", 4);
		perror(cur->filename);
		// write(1, "\n", 1);
		cur = cur->next;
	}
	*list = cur;
}

t_info*	av_to_list(char **av)
{
	int		i;
	t_stat	stats;
	t_info	*list;
	t_info	*ret;

	i = 0;
	list = (t_info*)malloc(sizeof(t_info));
	ret = list;
	while (av[i] != '\0')
	{
		list->filepath = (char*)malloc(sizeof(char) * (strlen(av[i]) + 1));
		strcpy(list->filepath, av[i]);
		list->filename = list->filepath;
		list->is_exist = ((stat((av[i]), &stats)) == -1) ? FALSE : TRUE;
		list->is_dir = (S_ISDIR(stats.st_mode)) && (!(stat((av[i]), &stats)))
		? TRUE : FALSE;
		// printf("%s %s \t\t D?: %s\n", list->is_exist ? "true" : "false", list->filepath,
		// list->is_dir ? "true" : "false");
		if (av[i + 1])
		{
			list->next = (t_info*)malloc(sizeof(t_info));
			list = list->next;
		}
		i++;
	}
	list->next = NULL;
	// printf("%s\n", (ret)->filepath);
	return (ret);
}
