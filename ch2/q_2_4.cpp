#include <stdio.h>

#define MAX_INPUT       10

int main()
{
    // handle user input
    int total_pair = 0;		// how many pairs input by user
    long pairs[MAX_INPUT] = {0};

    while(scanf("%ld %ld", &pairs[total_pair * 2], &pairs[total_pair * 2 + 1]) == 2 &&
                            pairs[total_pair * 2] <= pairs[total_pair * 2 + 1] && 
		            pairs[total_pair * 2] != 0 && pairs[total_pair * 2 + 1] != 0)
    {
	total_pair++;
    }

    // handle output
    for (int i = 0; i < total_pair; i++)
    {
        double s = 0;

	//printf("(%ld, %ld)\n", pairs[i*2], pairs[i*2+1]);

        for (long j = pairs[i * 2]; j <= pairs[i * 2 + 1]; j++)
	{
	    //printf("%ld * %ld = %ld\n", j, j, j * j);
	    s += (double)1 / (j * j);
	}

	printf("Case %i: %.5f\n", i + 1, s);
    }

    return 0;
}
