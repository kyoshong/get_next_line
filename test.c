#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
	char c[10];
	
	read(1, c, 10);
	printf("%s", c);
	return 0;
}
