#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int	get_line()
{
	char	con[10];
	read(1, con, 10);

	printf("%s\n", con);
	return (0);
}
int main()
{
	get_line();
	return 0;
}

