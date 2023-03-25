#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
int count_digits(long num, long base)
{
	num = num >= 0 ? num : -(num);
	return (num < base ? 1 : 1 + count_digits(num/base, base));
}

char *digTostr(long num)
{
	int lenStr = num < 0 ? 1 : 0;
	char *str;

	lenStr += (count_digits(num, 10));
	
	str = malloc(sizeof(*str) * (lenStr + 1));
	if (!str)
		exit(98);
	
	str[lenStr--] = '\0';
	str[0] = num >= 0 ? 0 : '-'; 
	num = num >= 0 ? num : -(num);
	
	while (num)
	{
		str[lenStr--] = (num % 10) + '0';
		num /=10;
	}
	return (str);
}

int main(void)
{
	time_t time_seed = time(0);
	long num = 0;
	char *res;


	srand(time_seed);
	
	while (num != 1)
	{
		num = (rand() - RAND_MAX/2) % 1024;
		res = digTostr(num);

		printf("%ld\n", num);
		printf("%ld\n", strlen(res));
		printf("%s\n\n", res); 
		free(res);
	}

	return(0);
}
