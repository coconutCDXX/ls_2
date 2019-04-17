#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
	struct dirent	*read;
	DIR				*d;
	int i = 0;
	bool a = true;

	d = opendir("./");
	while (a)
	{
		// printf("im reading%d %s\n",i, read->d_name);
		if ((read = readdir(d)) == NULL)
		{
			a = false;
			continue;
		}
		else
			printf("im readingif%d %s\n",i, read->d_name);
		i++;


	}
	closedir(d);
	return (0);
}