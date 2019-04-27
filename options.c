/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwartell <cwartell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 14:52:19 by cwartell          #+#    #+#             */
/*   Updated: 2019/04/26 14:52:33 by cwartell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls_lib.h"

t_opt	find_options(char **av)
{
	t_opt opt;
	int i;

	i = 1;
	opt = set_options_zero(opt);
	// printf("%u\n",opt.a);
	// printf("a %s\n", opt.a ? "TRUE" : "FALSE");
	// printf("l %s\n" ,opt.l ? "TRUE" : "FALSE");
	// printf("R %s\n" ,opt.ur ? "TRUE" : "FALSE");
	// printf("r %s\n", opt.r ? "TRUE" : "FALSE");
	// printf("t %s\n" ,opt.t ? "TRUE" : "FALSE");
	// printf("F %s\n", opt.uf ? "TRUE" : "FALSE");
	// printf("G %s\n", opt.ug ? "TRUE" : "FALSE");
	// printf("S %s\n", opt.us ? "TRUE" : "FALSE");
	// printf("U %s\n", opt.uu ? "TRUE" : "FALSE");
	// printf("f %s\n", opt.f ? "TRUE" : "FALSE");
	// printf("g %s\n", opt.g ? "TRUE" : "FALSE");
	// printf("o %s\n", opt.o ? "TRUE" : "FALSE");
	// printf("p %s\n", opt.p ? "TRUE" : "FALSE");
	// printf("u %s\n", opt.u ? "TRUE" : "FALSE");
	if (av[i] == NULL || av[i][0] != '-')
		return (opt);
	while (av[i] != NULL && av[i][0] == '-')
	{
		if (opt.a == FALSE)
			opt.a = strchr(av[i], 'a') ? TRUE : FALSE;
		if (opt.g == FALSE)
			opt.g = strchr(av[i], 'g') ? TRUE : FALSE;
		if (opt.l == FALSE)
			opt.l = strchr(av[i], 'l') ? TRUE : FALSE;
		if (opt.o == FALSE)
			opt.o = strchr(av[i], 'o') ? TRUE : FALSE;
		if (opt.p == FALSE)
			opt.p = strchr(av[i], 'p') ? TRUE : FALSE;
		i++;
	}
	opt = find_more_options(av, opt);
	opt = options_override(opt, av);
	return (opt);
}

t_opt	find_more_options(char **av, t_opt opt)
{
	int i;

	i = 1;
	while (av[i] != NULL && av[i][0] == '-')
	{
		if (opt.r == FALSE)
			opt.r = strchr(av[i], 'r') ? TRUE : FALSE;
		if (opt.t == FALSE)
			opt.t = strchr(av[i], 't') ? TRUE : FALSE;
		if (opt.u == FALSE)
			opt.u = strchr(av[i], 'u') ? TRUE : FALSE;
		if (opt.uf == FALSE)
			opt.uf = strchr(av[i], 'F') ? TRUE : FALSE;
		if (opt.ug == FALSE)
			opt.ug = strchr(av[i], 'G') ? TRUE : FALSE;
		if (opt.ur == FALSE)
			opt.ur = strchr(av[i], 'R') ? TRUE : FALSE;
		if (opt.us == FALSE)
			opt.us = strchr(av[i], 'S') ? TRUE : FALSE;
		if (opt.uu == FALSE)
			opt.uu = strchr(av[i], 'U') ? TRUE : FALSE;
		i++;
	}
	return (opt);
}

t_opt	set_options_zero(t_opt options)
{
	options.a = FALSE;
	options.g = FALSE;
	options.l = FALSE;
	options.o = FALSE;
	options.p = FALSE;
	options.r = FALSE;
	options.t = FALSE;
	options.u = FALSE;
	options.uf = FALSE;
	options.ug = FALSE;
	options.ur = FALSE;
	options.us = FALSE;
	options.uu = FALSE;
	options.o_pf = 2;
	options.o_st = 2;
	options.o_uu = 2;
	return(options);
}

t_opt	options_override(t_opt opt, char **av)
{
	// opt.p = strrchr(av[i], 'p') > strrchr(av[i], 'F')
	// ? TRUE : FALSE;
	// opt.uf = opt.p ? FALSE : TRUE;
	int i;

	i = 1;
	while (av[i] != NULL && av[i][0] == '-')
	{
		if (strchr(av[i], 'S'))
		{
			opt.us = TRUE;
			opt.t = FALSE;
		}
		if (strchr(av[i], 'f'))
		{
			opt.us = FALSE;
			opt.t = FALSE;
			opt.r = FALSE;
			opt.a = FALSE;
			opt.f = TRUE;
		}
		if (strrchr(av[i], 'p') && strrchr(av[i], 'F'))
			opt.o_pf = (strrchr(av[i], 'p') > strrchr(av[i], 'F')) ? 0 : 1;
		if (strrchr(av[i], 'p') && strrchr(av[i], 'F') == NULL)
			opt.o_pf = 0;
		if (strrchr(av[i], 'p') == NULL && strrchr(av[i], 'F'))
			opt.o_pf = 1;
		if (strrchr(av[i], 'u') && strrchr(av[i], 'U'))
			opt.o_uu = (strrchr(av[i], 'u') > strrchr(av[i], 'U')) ? 0 : 1;
		if (strrchr(av[i], 'u') && strrchr(av[i], 'U') == NULL)
			opt.o_uu = 0;
		if (strrchr(av[i], 'u') == NULL && strrchr(av[i], 'U'))
			opt.o_uu = 1;
		// if (strrchr(av[i], 'u') && strrchr(av[i], 'U'))
		// {
		// 	opt.u = strrchr(av[i], 'u') > strrchr(av[i], 'U')
		// 	? TRUE : FALSE;
		// 	opt.uu = opt.u ? FALSE : TRUE;
		// }
		i++;
	}
	if (opt.o_pf != 2)
	{
		opt.p = opt.o_pf == 0 ? TRUE : FALSE;
		opt.uf = opt.o_pf == 1 ? TRUE : FALSE;
	}
	if (opt.o_uu != 2)
	{
		opt.u = opt.o_uu == 0 ? TRUE : FALSE;
		opt.uu = opt.o_uu == 1 ? TRUE : FALSE;
	}
	return(opt);
}