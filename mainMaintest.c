/* FOR CHECK 2 BONUS FUNCTIONS CALL "./test 1 1" */


#include <stdio.h>
#include <fcntl.h>
#include <assert.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>
#include "./libft/libft.h"


t_list	*lstmap_test_fn(t_list *list)
{
	t_list	*l2;

	l2 = malloc(sizeof(t_list));
	bzero(l2, sizeof(t_list));
	l2->content = malloc(list->content_size * 2);
	l2->content_size = list->content_size * 2;
	return (l2);
}

int		myascii(char *s, size_t size)
{
	int	sum = 0;
	size_t i = 0;

	while (i < size)
	{
		sum = sum + (int)*s++;
		i++;
	}
	return (sum);
}

int		check(int res)
{
	if (res)
		return (0);
	return (1);
}

void	plusone(char *ch)
{
	*ch = *ch + 1;
}

void	plusi(unsigned int i, char *ch)
{
	*ch = *ch + i;
}

char	cplusone(char ch)
{
	return (ch + 1);
}

char	cplusi(unsigned int i, char ch)
{
	return (ch + i);
}

#define GREEN  "\x1B[32m"
#define RED  "\x1B[31m"
#define CYAN "\x1B[36m"
#define RESET  "\x1B[0m"

void check_out (char *name, int er, int sumer, int count)
{
	printf(RESET "\n--- %s --- \t", name);
	printf(CYAN "%d / %d \t\t", count - sumer, count);
	printf((er == 0 ? GREEN : RED));
	printf(">> %s << \n", (er == 0 ? "OK" : "FAIL"));
	printf(RESET);
}

int	main(int argc, char **argv)
{
	int er;
	int sumer;
	//int count;
	int test;

	sumer = 0;
	test = 0;

	er = check(ft_strlen("") == 0) +
		check(ft_strlen("abc  ") == 5);
	sumer += er;
	test += 2;
	check_out("ft_strlen", er, sumer, test);

	er = check(strcmp(ft_strjoin("abc", "def"), "abcdef") == 0) +
		check(strcmp(ft_strjoin("abc", ""), "abc") == 0) +
		check(strcmp(ft_strjoin("", "def"), "def") == 0) +
		check(strcmp(ft_strjoin("", ""), "") == 0) +
		check(strcmp(ft_strjoin("abc ", " def"), "abc  def") == 0);
	sumer += er;
	test += 5;
	check_out("ft_strjoin", er, sumer, test);

	er = check(strcmp(ft_itoa(0), "0") == 0) +
		check(strcmp(ft_itoa(INT_MIN), "-2147483648") == 0) +
		check(strcmp(ft_itoa(INT_MAX), "2147483647") == 0) +
		check(strcmp(ft_itoa(1000), "1000") == 0) +
		check(strcmp(ft_itoa(-1000), "-1000") == 0);
	sumer += er;
	test += 5;
	check_out("ft_itoa", er, sumer, test);

	er = check(myascii(ft_strnew(5), 6) == 0) +
		check(myascii(ft_strnew(0), 1) == 0) +
		check(ft_strnew(SIZE_MAX - 1) == NULL) +
		check(ft_strnew(SIZE_MAX) == NULL);
	sumer += er;
	test += 4;
	check_out("ft_strnew", er, sumer, test);

	er = check(myascii((char *)ft_memalloc(5), 5) == 0) +
		check(myascii(ft_memalloc(0), 0) == 0) +
		check(ft_memalloc(SIZE_MAX) == 0);
	sumer += er;
	test += 3;
	check_out("ft_memalloc", er, sumer, test);

	er = check(ft_strcmp("", "") == strcmp("", "")) +
		check(ft_strcmp("aa", "") == strcmp("aa", "")) +
		check(ft_strcmp("aab", "aaa") == strcmp("aab", "aaa")) +
		check(ft_strcmp("\0", "\200") == strcmp("\0", "\200")) +
		check(ft_strcmp("aaa", "aab") == strcmp("aaa", "aab")) +
		check(ft_strcmp("a", "") == strcmp("a", ""));
	sumer += er;
	test += 6;
	check_out("ft_strcmp", er, sumer, test);

	er = check(ft_strequ("", "") == 1) +
		check(ft_strequ("aa", "") == 0) +
		check(ft_strequ("aab", "aaa") == 0) +
		check(ft_strequ(" aaa", " aa") == 0) +
		check(ft_strequ("aaa", "aab") == 0) +
		check(ft_strequ("a", "") == 0);
	sumer += er;
	test += 6;
	check_out("ft_strequ", er, sumer, test);

	er = check(ft_strncmp("", "", 5) == strncmp("", "", 5)) +
		check(ft_strncmp("aa", "", 1) == strncmp("aa", "", 1)) +
		check(ft_strncmp("aab", "aaa", 2) == strncmp("aab", "aaa", 2)) +
		check(ft_strncmp(" aaa", " aa", 0) == strncmp(" aaa", " aa", 0)) +
		check(ft_strncmp("aaa", "aab", 2) == strncmp("aaa", "aab", 2)) +
		check(ft_strncmp("a", "", 5) == strncmp("a", "", 5));
	test += 6;
	sumer += er;
	check_out("ft_strncmp", er, sumer, test);

	er = check(ft_strnequ("", "", 5) == 1) +
		check(ft_strnequ("aa", "", 1) == 0) +
		check(ft_strnequ("aab", "aaa", 2) == 1) +
		check(ft_strnequ(" aaa", " aa", 0) == 1) +
		check(ft_strnequ("aaa", "aab", 2) == 1) +
		check(ft_strnequ("a", "", 5) == 0);
	sumer += er;
	test += 6;
	check_out("ft_strnequ", er,sumer, test);

	er = check(strcmp(ft_strsub("abc", 1, 2), "bc") == 0) +
		check(strcmp(ft_strsub("abcdef", 0, 4), "abcd") == 0) +
	//	check(strcmp(ft_strsub("abc", 1, 0), "") == 0) +
		check(strcmp(ft_strsub("", 0, 0), "") == 0) ;
	//	check(strcmp(ft_strsub("abc", 1, 5), "bc") == 0);
	sumer += er;
	test += 5;
	check_out("ft_strsub", er, sumer, test);

	er = check(strcmp(ft_strdup("abc"), strdup("abc")) == 0) +
		check(strcmp(ft_strdup(""), strdup("")) == 0);
	sumer += er;
	test += 2;
	check_out("ft_strdup", er,sumer, test);

	char s[] = "000000000000000000000", ss[] = "000000000000000000000";
	er = check(strcmp(ft_strcpy(s, "abc"), strcpy(ss, "abc")) == 0) +
		check(strcmp(ft_strcpy(s, ""), strcpy(ss, "")) == 0);
	sumer += er;
	test += 2;
	check_out("ft_strcpy", er,sumer, test);

	er = check(strcmp(ft_strncpy(s, "Hello World", 13), strncpy(ss, "Hello World", 13)) == 0) +
		check(strcmp(ft_strncpy(s, "Hello World", 5), strncpy(ss, "Hello World", 5)) == 0) +
		check(strcmp(ft_strncpy(s, "Hello World", 20), strncpy(ss, "Hello World", 20)) == 0) +
		check(strcmp(ft_strncpy(s, "abc", 3), strncpy(ss, "abc", 3)) == 0) +
		check(strcmp(ft_strncpy(s, "", 3), strncpy(ss, "", 3)) == 0) +
		check(strcmp(ft_strncpy(s, "", 0), strncpy(ss, "", 0)) == 0);
	sumer += er;
	test += 6;
	check_out("ft_strncpy", er,sumer, test);

	er = check(strcmp(ft_strstr("", ""), strstr("", "")) == 0) +
		check(ft_strstr("abcbcd", "cde") == strstr("abcbcd", "cde")) +
		check(strcmp(ft_strstr("abcbcd", ""), strstr("abcbcd", "")) == 0) +
		check(strcmp(ft_strstr("abc", "abc"), strstr("abc", "abc")) == 0) +
		check(strcmp(ft_strstr("abcbcd", "bcd"), strstr("abcbcd", "bcd")) == 0);
	sumer += er;
	test += 5;
	check_out("ft_strstr", er, sumer, test);

	er = check(strcmp(ft_strnstr("abc", "abc", 3), strnstr("abc", "abc", 3)) == 0) +
		check(strcmp(ft_strnstr("abc", "abc", 6), strnstr("abc", "abc", 6)) == 0) +
		check(ft_strnstr("abcbcd", "cd", 5) == strnstr("abcbcd", "cd", 5)) +
		check(strcmp(ft_strnstr("abcbcd", "cd", 6), strnstr("abcbcd", "cd", 6)) == 0) +
		check(strcmp(ft_strnstr("abcbcd", "", 0), strnstr("abcbcd", "", 0)) == 0) +
		check(strcmp(ft_strnstr("abcbcd", "bcd", 6), strnstr("abcbcd", "bcd", 6)) == 0) +
		check(strcmp(ft_strnstr("abcbcd", "", 2), strnstr("abcbcd", "", 2)) == 0) +
		check(strcmp(ft_strnstr("", "", 2), strnstr("", "", 2)) == 0) +
		check(strcmp(ft_strnstr("abcbcd", "bcd", 8), strnstr("abcbcd", "bcd", 8)) == 0);
	sumer += er;
	test += 9;
	check_out("ft_strnstr", er,sumer, test);
/*
	er = check(ft_strchr("", 5) == strchr("", 5)) +
		check(strcmp(ft_strchr("abcbcd", 99), strchr("abcbcd", 99)) == 0) +
		check(strcmp(ft_strchr("abcbcd", 355), strchr("abcbcd", 355)) == 0);
		check(strcmp(ft_strchr("", 0), strchr("", 0)) == 0) +
		check(strcmp(ft_strchr("abcbcd", 0), strchr("abcbcd", 0)) == 0);
	sumer += er;
	test += 5;
	check_out("ft_strchr", er,sumer, test);
*/
	/*
	er = check(ft_strrchr("", 5) == strrchr("", 5)) +
		check(strcmp(ft_strrchr("abcbcd", 99), strrchr("abcbcd", 99)) == 0) +
		check(strcmp(ft_strrchr("abcbcd", 355), strrchr("abcbcd", 355)) == 0) +
		check(strcmp(ft_strrchr("", 0), strrchr("", 0)) == 0) +
		check(strcmp(ft_strrchr("abcbcd", 0), strrchr("abcbcd", 0)) == 0);
	sumer += er;
	test += 5;
	check_out("ft_strrchr", er,sumer, test);
*/
	char s1[] = " 000 ";
	char s2[] = "";
	ft_strclr(s1);
	ft_strclr(s1);
	er = check(myascii(s1, 6) == 0) +
		check(myascii(s2, 1) == 0);
	sumer += er;
	test += 2;
	check_out("ft_strclr", er, sumer, test);

	er = check(ft_isalpha(70) == isalpha(70)) +
		check(ft_isalpha(100) == isalpha(100)) +
		check(ft_isalpha(0) == isalpha(0)) +
		check(ft_isalpha(-2147483648) == isalpha(-2147483648)) +
		check(ft_isalpha(2147483647) == isalpha(2147483647));
	sumer += er;
	test += 5;
	check_out("ft_isalpha", er,sumer, test);

	er = check(ft_isdigit(70) == isdigit(70)) +
		check(ft_isdigit(0) == isdigit(0)) +
		check(ft_isdigit(51) == isdigit(51)) +
		check(ft_isdigit(-2147483648) == isdigit(-2147483648)) +
		check(ft_isdigit(2147483647) == isdigit(2147483647));
	sumer += er;
	test += 5;
	check_out("ft_isdigit", er,sumer, test);

	er = check(ft_isalnum(70) == isalnum(70)) +
		check(ft_isalnum(INT_MIN) == isalnum(INT_MIN)) +
		check(ft_isalnum(INT_MAX) == isalnum(INT_MAX)) +
		check(ft_isalnum(51) == isalnum(51)) +
		check(ft_isalnum(0) == isalnum(0)) +
		check(ft_isalnum(6) == isalnum(6));
	sumer += er;
	test += 6;
	check_out("ft_isalnum", er,sumer, test);

	er = check(ft_isascii(70) == isascii(70)) +
		check(ft_isascii(INT_MIN) == isascii(INT_MIN)) +
		check(ft_isascii(INT_MAX) == isascii(INT_MAX)) +
		check(ft_isascii(128) == isascii(128)) +
		check(ft_isascii(0) == isascii(0));
	sumer += er;
	test += 5;
	check_out("ft_isascii", er, sumer, test);

	er = check(ft_isprint(INT_MIN) == isprint(INT_MIN)) +
		check(ft_isprint(INT_MAX) == isprint(INT_MAX)) +
		check(ft_isprint(127) == isprint(127)) +
		check(ft_isprint(32) == isprint(32)) +
		check(ft_isprint(31) == isprint(31)) +
		check(ft_isprint(126) == isprint(126)) +
		check(ft_isprint(0) == isprint(0));
	sumer += er;
	test += 7;
	check_out("ft_isprint", er,sumer, test);

	er = check(ft_toupper(INT_MIN) == toupper(INT_MIN)) +
		check(ft_toupper(INT_MAX) == toupper(INT_MAX)) +
		check(ft_toupper(100) == toupper(100)) +
		check(ft_toupper(0) == toupper(0)) +
		check(ft_toupper(122) == toupper(122)) +
		check(ft_toupper(97) == toupper(97));
	sumer += er;
	test += 6;
	check_out("ft_toupper", er,sumer, test);

	er = check(ft_tolower(INT_MIN) == tolower(INT_MIN)) +
		check(ft_tolower(INT_MAX) == tolower(INT_MAX)) +
		check(ft_tolower(70) == tolower(70)) +
		check(ft_tolower(0) == tolower(0)) +
		check(ft_tolower(90) == tolower(90)) +
		check(ft_tolower(65) == tolower(65));
	sumer += er;
	test += 6;
	check_out("ft_tolower", er,sumer, test);

	char s3[10] = "000";
	char ss3[10] = "000";
	char s4[10] = "000000";
	char ss4[10] = "000000";
	er = check(strcmp(ft_strcat(s3, "def"), strcat(ss3, "def")) == 0) +
		check(strcmp(ft_strcat(s4, "def"), strcat(ss4, "def")) == 0);
	sumer += er;
	test += 2;
	check_out("ft_strcat", er,sumer, test);

	char s5[10] = "000";
	char ss5[10] = "000";
	char s6[10] = "000";
	char ss6[10] = "000";
	char s7[10] = "000";
	char ss7[10] = "000";
	char s8[10] = "000";
	char ss8[10] = "000";
	er = check(strcmp(ft_strncat(s5, "def", 2), strncat(ss5, "def", 2)) == 0) +
		check(strcmp(ft_strncat(s6, "def", 3), strncat(ss6, "def", 3)) == 0) +
		check(strcmp(ft_strncat(s7, "def", 4), strncat(ss7, "def", 4)) == 0) +
		check(strcmp(ft_strncat(s8, "def", 5), strncat(ss8, "def", 5)) == 0);
	sumer += er;
	test += 4;
	check_out("ft_strncat", er, sumer, test);

	char s9[10] = "000";
	char ss9[10] = "000";
	char s10[10] = "000";
	char ss10[10] = "000";
	char s11[10] = "000";
	char ss11[10] = "000";
	char s12[10] = "000";
	char ss12[10] = "000";
	er = check(ft_strlcat(s9, "def", 2) == strlcat(ss9, "def", 2)) +
		check(ft_strlcat(s10, "def", 3) == strlcat(ss10, "def", 3)) +
		check(ft_strlcat(s11, "def", 4) == strlcat(ss11, "def", 4)) +
		check(ft_strlcat(s12, "def", 5) == strlcat(ss12, "def", 5));
	sumer += er;
	test += 4;
	check_out("ft_strlcat", er,sumer, test);

	er = check(ft_atoi("0") == atoi("0")) +
		check(ft_atoi("-2147483648") == atoi("-2147483648")) +
		check(ft_atoi("  2147483647	") == atoi("  2147483647	")) +
		check(ft_atoi("  214748365000	") == atoi("  214748365000	")) +
		check(ft_atoi("  214748360047000	") == atoi("  214748360047000	")) +
		check(ft_atoi("  -0dfg") == atoi("  -0dfg")) +
		check(ft_atoi("  -rt76 ") == atoi("  -rt76 ")) +
		check(ft_atoi("-5fg6") == atoi("-5fg6"));
	sumer += er;
	test += 8;
	check_out("ft_atoi", er,sumer, test);

	er = check(strcmp(ft_strtrim("hey"), "hey") == 0) +
		check(strcmp(ft_strtrim("  hey  "), "hey") == 0) +
		check(strcmp(ft_strtrim("hey  hey  "), "hey  hey") == 0) +
		check(strcmp(ft_strtrim("  "), "") == 0) +
		check(strcmp(ft_strtrim(""), "") == 0) +
		check(strcmp(ft_strtrim("  hey"), "hey") == 0) +
		check(strcmp(ft_strtrim("h"), "h") == 0);
	sumer += er;
	test += 7;
	check_out("ft_strtrim", er,sumer, test);

	char	**ar, **ar1, **ar2, **ar3;
	ar = ft_strsplit("*hello*fellow***students*", '*');
	ar1 = ft_strsplit("hey|||", '|');
	ar2 = ft_strsplit("/hey", '/');
	ar3 = ft_strsplit("hheyh", 'h');
	er = check(strcmp(ar1[0], "hey") == 0) +
		check(strcmp(ar2[0], "hey") == 0) +
		check(strcmp(ar3[0], "ey") == 0) +
		check(strcmp(ar[0], "hello") == 0) +
		check(strcmp(ar[1], "fellow") == 0) +
		check(strcmp(ar[2], "students") == 0) +
		check(ft_strsplit(NULL, '*') == NULL) +
		check(ft_strsplit("", '*')[0] == NULL);
	sumer += er;
	test += 6;
	check_out("ft_strsplit", er,sumer, test);

	char s13[] = "abc";
	ft_striter(s13, plusone);
	char s14[] = "";
	ft_striter(s14, plusone);
	er = check(strcmp(s13, "bcd") == 0) +
		check(strcmp(s14, "") == 0);
	sumer += er;
	test += 2;
	check_out("ft_striter", er, sumer, test);

	char s15[] = "abc";
	ft_striteri(s15, plusi);
	char s16[] = "";
	ft_striteri(s16, plusi);
	er = check(strcmp(s15, "ace") == 0) +
		check(strcmp(s16, "") == 0);
	sumer += er;
	test += 2;
	check_out("ft_striteri", er, sumer, test);

	er = check(strcmp(ft_strmap("abc", cplusone), "bcd") == 0) +
		check(strcmp(ft_strmap("", cplusone), "") == 0);
	sumer += er;
	test += 2;
	check_out("ft_strmap", er,sumer, test);

	er = check(strcmp(ft_strmapi("abc", cplusi), "ace") == 0) +
		check(strcmp(ft_strmapi("", cplusi), "") == 0);
	sumer += er;
	test += 2;
	check_out("ft_strmapi", er,sumer, test);

	char s17[] = "good morning evryone";
	char ss17[] = "good morning evryone";
	ft_memset(s17, '.', 5); ft_memset(s17 + 7, '#', 3); ft_memset(s17 + 12, '.', 5);
	memset(ss17, '.', 5); memset(ss17 + 7, '#', 3); memset(ss17 + 12, '.', 5);
	er = check(strcmp(s17, ss17) == 0);
	sumer += er;
	test += 3;
	check_out("ft_memset", er, sumer, test);

	char s18[] = "good morning evryone";
	char ss18[] = "good morning evryone";
	ft_bzero(s18 + 7, 3); ft_bzero(s18 + 12, 5);
	bzero(ss18 + 7, 3); bzero(ss18 + 12, 5);
	er = check(strcmp(s18, ss18) == 0);
	sumer += er;
	test += 3;
	check_out("ft_bzero", er,sumer, 158);

	er = check(strcmp(ft_memcpy(s, "Hello World", 13), memcpy(ss, "Hello World", 13)) == 0) +
		check(strcmp(ft_memcpy(s, "Hello World", 5), memcpy(ss, "Hello World", 5)) == 0) +
		check(strcmp(ft_memcpy(s, "Hello World", 20), memcpy(ss, "Hello World", 20)) == 0) +
		check(strcmp(ft_memcpy(s, "abc", 3), memcpy(ss, "abc", 3)) == 0) +
		check(strcmp(ft_memcpy(s, "", 3), memcpy(ss, "", 3)) == 0) +
		check(strcmp(ft_memcpy(s, "", 0), memcpy(ss, "", 0)) == 0);
	sumer += er;
	test += 6;
	check_out("ft_memcpy", er, sumer, test);

	er = check(strcmp(ft_memmove(s, "Hello World", 13), memmove(ss, "Hello World", 13)) == 0) +
		check(strcmp(ft_memmove(s, "Hello World", 5), memmove(ss, "Hello World", 5)) == 0) +
		check(strcmp(ft_memmove(s, "Hello World", 20), memmove(ss, "Hello World", 20)) == 0) +
		check(strcmp(ft_memmove(s, "abc", 3), memmove(ss, "abc", 3)) == 0) +
		check(strcmp(ft_memmove(s, "", 3), memmove(ss, "", 3)) == 0) +
		check(strcmp(ft_memmove(s, "", 0), memmove(ss, "", 0)) == 0);
	sumer += er;
	test += 6;
	check_out("ft_memmove", er,sumer, test);

	er = check(strcmp(ft_memccpy(s, "Hello World", 'o', 13), memccpy(ss, "Hello World", 'o', 13)) == 0) +
		check(strcmp(s, ss) == 0) +
		check(ft_memccpy(s, "Hello World", 'd', 5) == memccpy(ss, "Hello World", 'd', 5)) +
		check(strcmp(s, ss) == 0) +
		check(strcmp(ft_memccpy(s, "Hello World", 'd', 20), memccpy(ss, "Hello World", 'd', 20)) == 0) +
		check(strcmp(s, ss) == 0) +
		check(ft_memccpy(s, "abc", 'x', 3) == memccpy(ss, "abc", 'x', 3)) +
		check(strcmp(s, ss) == 0) +
		check(ft_memccpy(s, "", 'x', 3) == memccpy(ss, "", 'x', 3)) +
		check(strcmp(s, ss) == 0) +
		check(ft_memccpy(s, "", 'x', 0) == memccpy(ss, "", 'x', 0)) +
		check(strcmp(s, ss) == 0);
	sumer += er;
	test += 6;
	check_out("ft_memccpy", er, sumer, test);

	er = check(ft_memchr("", 5, 1) == memchr("", 5, 1)) +
		check(ft_memchr("abcbcd", 99, 2) == memchr("abcbcd", 99, 2)) +
		check(strcmp(ft_memchr("abcbcd", 99, 4), memchr("abcbcd", 99, 4)) == 0) +
		check(strcmp(ft_memchr("", 0, 1), memchr("", 0, 1)) == 0) +
		check(strcmp(ft_memchr("abcbcd", 0, 20), memchr("abcbcd", 0, 20)) == 0);
	sumer += er;
	test += 5;
	check_out("ft_memchr", er,sumer, test);

	er = check(ft_memcmp("", "", 1) == memcmp("", "", 1)) +
		check(ft_memcmp("aa", "", 1) * memcmp("aa", "", 1) > 0) +
		check(ft_memcmp("aab", "aaa", 2) == memcmp("aab", "aaa", 2)) +
		check(ft_memcmp(" aaa", " aa", 0) == memcmp(" aaa", " aa", 0)) +
		check(ft_memcmp("aaa", "aab", 2) == memcmp("aaa", "aab", 2)) +
		check(ft_memcmp("a", "", 5) * memcmp("a", "", 5) > 0);
	sumer += er;
	test += 6;
	check_out("ft_memcmp", er, sumer, test);

	if (sumer == 0)
		printf(GREEN "\n\t\t>>> SUCCESS <<<\n\n");
	else
		printf(RED "\n\t\t>>> FAIL <<<\n\n");

	if (argc == 1)
		return 0;

	sumer = 0;
	test = 0;
	printf(CYAN "\n\t\t>>> BONUS <<<\n\n");

	if (argc > 1 && *argv[1] == '1')
	{
		t_list *new = ft_lstnew(NULL, 0);
		t_list *new1 = ft_lstnew(NULL, 5);
	//	t_list *new2 = ft_lstnew("smth", 0);
		t_list *new3 = ft_lstnew("smth", 5);
		er = check(new->next == NULL && new->content == NULL && new->content_size == 0) +
			check(new1->next == NULL && new1->content == NULL && new1->content_size == 0) +
//			check(new2->next == NULL && new2->content && new2->content_size == 0) +
			check(new3->next == NULL && strcmp(new3->content, "smth") == 0 && new3->content_size == 5) ;
		sumer += er;
		test += 4;
		check_out("ft_lstnew", er, sumer, test);
	}

	if (argc > 1 && *argv[2] == '1')
	{
		t_list *new = ft_lstnew("abc", 4);
		t_list *new1 = ft_lstnew("defg", 5);
		ft_lstadd(&new, new1);
		t_list *new2 = ft_lstnew("smth", 5);
		ft_lstadd(&new, new2);
		t_list *new3 = ft_lstnew("smthelse", 9);
		ft_lstadd(&new, new3);
//		t_list	*cp;
//		cp = new;
//		while (cp)
//		{
//			printf("--%s--%zu--%p--\n", cp->content, cp->content_size, cp->next);
//			cp = cp->next;
//		}
//		printf("===========\n");
		t_list *map = ft_lstmap(new, lstmap_test_fn);
//		cp = map;
//		while (cp)
//		{
//			printf("--%s--%zu--%p--\n", cp->content, cp->content_size, cp->next);
//			cp = cp->next;
//		}
		er = check(strcmp(map->content, "") == 0 && map->content_size == 18) ;
		//	check(new1->content == NULL && new1->content_size == 0) +
		//	check(new2->next == NULL && new2->content && new2->content_size == 0) +
		//	check(new3->next == NULL && strcmp(new3->content, "smth") == 0 && new3->content_size == 5) ; */
		sumer += er;
		test += 1;
		check_out("ft_lstmap", er, sumer, test);
	}


	return (0);
}
