#include <stdio.h>
#include <limits.h>
#include <fcntl.h>
#include "get_next_line.h"

int main(void)
{
	/* code */
	//char *in = "22222222222222222222";
	char in[21] = {0};
	int i = -1;

	while (++i < 10)
	{
		ft_memset(in, i+48, 20);
	//i = LONG_MIN;
	//while (i > (LONG_MAX / 10) )
	//{
	//	sprintf(in, "%li", i++);
		//scanf("%s", in);
	//	if (ft_atoi(in) != atoi(in))
		printf("%s\n", in);
		if (ft_atoi(in) == atoi(in))
			printf("OK\n");
		else
			printf ("FAIL:%s\n", in);
			//printf("atoi:%d || libc:%d\n", ft_atoi(in), atoi(in));
//		if (!(i / 10000))
//			printf ("%li\n",i);
	}
	/* ******************* READ TEST ******************* */

	int f;
	int red;
	char *buf;

	buf = NULL;
	f = open("text.txt", O_RDONLY);
	red = read(f, buf, 0);
	while (get_next_line(f, &buf))
	{
		printf("buf = %s\n", buf);
	}

	buf = (char*)malloc(BUFF_SIZE);
	while (get_next_line(f, &buf))
	{
		printf("buf = %s\n", buf);
	}

	while (get_next_line(f, NULL))
	{
		printf("buf = %s\n", buf);
	}
	return (0);
}
