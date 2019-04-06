/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_lib.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwartell <cwartell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 14:30:03 by cwartell          #+#    #+#             */
/*   Updated: 2019/04/05 19:00:23 by cwartell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LS_LIB_H
# include <stdio.h>
# include <unistd.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/xattr.h>
# include <string.h>
# include <stdlib.h>
# include <time.h>
# include <pwd.h>
# include <grp.h>
# include <errno.h>
# include <dirent.h>

typedef enum	e_bools
{
	FALSE,
	TRUE
}				t_bool;

typedef struct	s_options
{
	t_bool			one;
	t_bool			A;
	t_bool			B;
	t_bool			C;
	t_bool			F;
	t_bool			G;
	t_bool			H;
	t_bool			L;
	t_bool			O;
	t_bool			R;
	t_bool			S;
	t_bool			T;
	t_bool			U;
	t_bool			W;
	t_bool			a;
	t_bool			b;
	t_bool			c;
	t_bool			d;
	t_bool			e;
	t_bool			f;
	t_bool			g;
	t_bool			h;
	t_bool			i;
	t_bool			k;
	t_bool			l;
	t_bool			m;
	t_bool			n;
	t_bool			o;
	t_bool			p;
	t_bool			q;
	t_bool			r;
	t_bool			s;
	t_bool			t;
	t_bool			u;
	t_bool			w;
	t_bool			x;
}				t_opt;

typedef struct		s_info
{
	t_bool			is_fold;
	t_bool			is_exist;
	int				block_cont;
	char			*str_rights;
	// int				read_and_stat;
	int				links;
	// int				file_type;
	char			*user_name;
	char			*grp_name;
	int				bytes;
	// int				minor;
	// t_boolean		device;
	// time_t			time_sort;
	char			*date;
	char			*filename;
	// char			*linkedfile;
	// char			*filepath;
	struct s_info	*next;
	struct s_info	*tree;
}					t_info;

typedef struct		s_files
{
	char			*filename;
	t_bool			is_fold;
	t_bool			is_exist;
	struct s_files	*next;
}					t_filename;

typedef struct stat	t_stat;

t_filename*	av_to_list(char **av);






#endif