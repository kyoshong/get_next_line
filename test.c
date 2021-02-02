#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
	static char *tem[4];
	char *i;

	i = "asas";
	tem[0] = "qwqw";
	printf("%s\n", tem[0]);

	tem[0] = i;

	printf("%s", tem[0]);
	return 0;
}

