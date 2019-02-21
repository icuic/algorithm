#include <stdio.h>

#define MAX_INPUT	10

int main()
{
    int n[MAX_INPUT] = {0}, j = 0, kase = 0;
    int x[MAX_INPUT][MAX_INPUT] = {0};

    while(scanf("%d", &n[j]) == 1 && n[j])
    {
        for (int i = 0; i < n[j]; i++)
 	{
	    scanf("%d", &x[j][i]);
	}

	j++;	// next input 
    }

    for (int jj = 0; jj < j; jj++)
    {
	int s = 0, min = 0, max = 0;

	for (int i = 0; i < n[jj]; i++)
	{
	    int tmp = x[jj][i];
	    s += tmp;

	    if (i == 0)
	    {
		min = tmp;
		max = tmp;
	    }
	    else
	    {
		min = (tmp < min) ? tmp : min;
		max = (tmp > max) ? tmp : max;
	    }
	}

	if (kase)
	{
	    printf("\n");
	}

	printf("Case %d: %d %d %.3f", ++kase, min, max, (double)s/n[jj]);
    }

    printf("\n");
}
