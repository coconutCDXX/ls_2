#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef enum	e_bools
{
	FALSE,
	TRUE
}				t_bool;

typedef struct	test
{
	t_bool GG;
	t_bool FF;
}				t_t;

typedef struct	s_options
{
	t_bool			a;
	t_bool			l;
	t_bool			ur;
	t_bool			r;
	t_bool			t;
	// t_bool			one;
	// t_bool			ub;
	t_bool			uf;
	t_bool			ug;
	t_bool			us;
	// t_bool			ut;
	t_bool			uu;
	// t_bool			b;
	// t_bool			d;
	t_bool			f;
	t_bool			g;
	// t_bool			h;
	// t_bool			i;
	// t_bool			k;
	// t_bool			m;
	// t_bool			n;
	t_bool			o;
	t_bool			p;
	// t_bool			q;
	// t_bool			s;
	t_bool			u;
	// t_bool			x;
}				t_opt;

int main()
{
	// struct dirent	*read;
	// DIR				*d;
	// int i = 0;
	// bool a = true;
    //
	// d = opendir("./");
	// while (a)
	// {
	// 	// printf("im reading%d %s\n",i, read->d_name);
	// 	if ((read = readdir(d)) == NULL)
	// 	{
	// 		a = false;
	// 		continue;
	// 	}
	// 	else
	// 		printf("im readingif%d %s\n",i, read->d_name);
	// 	i++;
    //
    //
	// }
	// closedir(d);
	// return (0);
	t_t at;
	t_opt bt;
	printf("%u\n",at.FF);
	printf("%u\n",at.GG);

	printf("%u\n",bt.a);
	printf("%u\n",bt.l);
	printf("%u\n",bt.ur);
	printf("%u\n",bt.r);
	printf("%u\n",bt.t);
	printf("%u\n",bt.uf);
	printf("%u\n",bt.ug);
	printf("%u\n",bt.us);
	printf("%u\n",bt.uu);
	printf("%u\n",bt.f);
	printf("%u\n",bt.g);
	printf("%u\n",bt.o);
	printf("%u\n",bt.p);
	printf("%u\n",bt.u);

}