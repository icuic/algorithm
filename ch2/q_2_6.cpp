#include <stdio.h>
#include <string.h>

#define MIN		(123)
#define MAX		(987)

#define TOTAL_NUMBERS	(9)

char array[TOTAL_NUMBERS] = {0};

bool isUsed(int x)
{
    if  (array[x - 1] == 1)
    {
	return 1;
    }
    else
    {
	array[x - 1] = 1;
	return 0;
    }
}

int main()
{

    for (int i = MIN; i <= MAX; i++)
    {
	bool flag = 0;
	memset(array, 0, TOTAL_NUMBERS);

	for (int j = 1; j <= 3; j++)
	{
	    int k = i * j;

            if (isUsed(k / 100) || isUsed(k % 100 / 10) || isUsed(k % 10) || k > MAX)
	    {
		flag = 1;
		break;	
	    }
	}

	if (flag == 0)
            printf("%d %d %d\n", i, 2 * i, 3 * i);

    }

    return 0;
}

