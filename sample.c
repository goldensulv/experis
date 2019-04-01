#include <stdio.h>

int main(void)
{
	char str[50];
	int n = 4;

	char str1[100], str2[100];
	int i;
	char ch;

	sprintf(str, "Hello world %d\n", n);
	printf("%s\n", str);

	sscanf(str, "%s %s %d", str1, str2, &i);
	printf("%d%s%s\n", i, str1, str2);

	i = 0;
	while (str[i] != '\n')
	{
		printf("%c\n", str[i]);
		i++;
	}

	return 0;
}