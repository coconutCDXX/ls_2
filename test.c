#include <stdio.h>
# include <unistd.h>

void func();
int main()
{
	// int i = -1, j = -1;
	// char *s = "coralie";
	// char *t = "coratie";
	// printf("%c \n", s[0]);
	// func(s);
	// printf("%c \n", s[0]);
	// while (s[++i] == t[++j])
	// 	;
	// printf("s[i] %c t[j] %c\n", s[i], t[j]);
	// return 0;
	int a = 10;
	write(1, &a, sizeof(a));
}

void func(char *s)
{
	s++;
}