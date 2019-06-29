#include <limits.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>
#include "get_next_line.h"

int main(int argc, char *argv[])
{
	int f;
	char *buf;

	buf = NULL;
	if (argc > 1)
	{
		f = open(argv[1], O_RDONLY);
	}
	else
	{
		f = 0;
	}

		// Нормальное поведение
		while (get_next_line(f, &buf))
		{
			printf("%s\n", buf);
		}
/*
		printf("str:%s\n", buf);
		// Передача строки с содержимым
		buf = (char *)malloc(BUFF_SIZE);
		while (get_next_line(f, &buf))
		{
			printf("buf = %s\n", buf);
		}

		// Передача нулевого указателя
		while (get_next_line(f, NULL) >= 0)
		{
			printf("buf = %s\n", buf);
		}
		// Передача невалидного FD
		while (get_next_line(100, &buf) >= 0)
		{
			printf("buf = %s\n", buf);
		}

		// Передача FD > MAX_FD
		int f2;
		printf("%d\n", get_next_line(f, &buf));
		free(buf);
		f2 = dup2(f, MAX_FD + 1);
		while (get_next_line(f2, &buf) > 0)
		{
			printf("%s\n", buf);
			free(buf);
		}
*/
	if (f)
		close(f);
	free (buf);
	buf = NULL;
	return (0);
}
