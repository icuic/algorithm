#include <stdio.h>

#define MAX_ENTRY	(10)

int main()
{
    int idx = 0;
    int entry[MAX_ENTRY][3] = {0};

    // handle input
    // input EOF by ctrl+D on Linux, ctrl+Z on Windows
    while(scanf("%d %d %d", &entry[idx][0], &entry[idx][1], &entry[idx][2] ) != EOF  && 
		idx < MAX_ENTRY)
    {
	getchar();	// used to get enter key

	idx++;
    }    

    // handle output
    for (int i = 0; i < idx; i++)
    {
	int j = 10;
        for (; j <= 100; j++)
        {
            if (j % 3 == entry[i][0] && 
                j % 5 == entry[i][1] && 
                j % 7 == entry[i][2])
	    {
		printf("Case %d: %d\n", i+1, j);
		
		break;
	    }
        }

	if (j == 101)
	{
	    printf("Case %d: No answer\n", i);
	}
    }

    return 0;
}
