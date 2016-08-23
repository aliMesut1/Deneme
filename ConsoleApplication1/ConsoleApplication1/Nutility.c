#include "Nutility.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define		HIGH_DRAND		10
#define		DRAND	(double)rand() / RAND_MAX + rand() % HIGH_DRAND  


void sl(void)
{
	printf("****************************************\n");
}


int isprime(int val)
{
	if (val == 0 || val == 1)
		return 0;

	if (val % 2 == 0)
		return val == 2;

	if (val % 3 == 0)
		return val == 3;

	if (val % 5 == 0)
		return val == 5;

	for (int k = 7; k * k <= val; k += 2){
		if (val % k == 0)
			return 0;
	}

	return 1;

}

void delay(double sec)
{
	clock_t start = clock();

	while ((double)(clock() - start) / CLOCKS_PER_SEC < sec)
		;
}

void randomize(void)
{
	srand((unsigned)time(0));
}

void isleap(int y)
{
	return y % 4 == 0 && (y % 100 != 0 || y % 400 == 0);
}
