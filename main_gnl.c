#include <limits.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>
#include "get_next_line.h"

int main(void)
{
	int f;
	int f2;
	char *buf;

	buf = NULL;
	f = open("text.txt", O_RDONLY);

	/* Нормальное поведение */
	while (get_next_line(f, &buf))
	{
		printf("buf = %s\n", buf);
	}
	printf("str:%s\n", buf);
	/* Передача строки с содержимым */
	buf = (char *)malloc(BUFF_SIZE);
	while (get_next_line(f, &buf))
	{
		printf("buf = %s\n", buf);
	}

	/* Передача нулевого указателя */
	while (get_next_line(f, NULL) >= 0)
	{
		printf("buf = %s\n", buf);
	}
	/* Передача невалидного FD */
	while (get_next_line(100, &buf) >= 0)
	{
		printf("buf = %s\n", buf);
	}

	/* Передача FD > MAX_FD */
	f2 = dup2(f, MAX_FD + 1);
	while (get_next_line(f2, &buf) >= 0)
	{
		printf("buf = %s\n", buf);
	}
	return (0);
}
