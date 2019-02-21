#include <stdio.h>

int main()
{
    int n = 0, kase = 0;

    while(scanf("%d", &n) == 1 && n)
    {
        int s = 0, x = 0, min = 0, max = 0;

        for (int i = 0; i < n; i++)
        {
            scanf("%d", &x);

            s += x;		// sum
            
            if (i == 0)
            {
 	        min = x;	// initial value
		max = x;	// initial value
	    }
	    else
	    {
 	        min = (x < min) ? x : min;	// update min
		max = (x > max) ? x : max;	// update max
	    }
        }

	if (kase)
	{
	    printf("\n");
	}


	printf("Case %d: %d %d %.3f\n", ++kase, min, max, (double)s / n);
    }

    return 0;
}
