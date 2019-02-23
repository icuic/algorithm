#include <stdio.h>
#include <math.h>

#define MAX_INPUT       10

int main()
{
    // handle user input
    int total_pair = 0;         // how many pairs input by user
    long pairs[MAX_INPUT] = {0};

    while(scanf("%ld %ld %ld", &pairs[total_pair * 3], &pairs[total_pair * 3 + 1], &pairs[total_pair * 3 + 2]) == 3 &&
                            pairs[total_pair * 3 + 2] > 0 &&
                            pairs[total_pair * 3] != 0 && pairs[total_pair * 3 + 1] != 0 && pairs[total_pair *3 + 2] != 0)
    {
        total_pair++;
    }

    // handle output
    for (int i = 0; i < total_pair; i++)
    {
        double s = 0;

        printf("Case %i: %ld.", i + 1, pairs[i * 3] / pairs[i * 3 + 1]);

	int D = pairs[i * 3] % pairs[i * 3 + 1] * 10;	// D: Divisor
	int Q = D / pairs[i * 3 + 1];	// Q: Quotient
	int R = D % pairs[i * 3 + 1];	// R: Remainder

	for (int j = 0; j < pairs[i * 3 + 2]; j++)
	{
	    printf("%d", Q);

	    D = R * 10;
	    Q = D / pairs[i * 3 + 1];
	    R = D % pairs[i * 3 + 1];
	}

	printf("\n");
    }
    
    return 0;
}
