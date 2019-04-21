#include <limits.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>
#include "libft/libft.h"

int main(void)
{

	//char *in = "22222222222222222222";
	char in[21] = {0};
	int i = -1;

	while (++i < 10)
	{
		ft_memset(in, i + 48, 20);
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
			printf("FAIL:%s\n", in);
		//printf("atoi:%d || libc:%d\n", ft_atoi(in), atoi(in));
		//		if (!(i / 10000))
		//			printf ("%li\n",i);
	}
	return (0);
}
