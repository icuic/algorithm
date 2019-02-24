#include <stdio.h>
#define MAX_INPUT	(100)
#define MAX_ENTRY	(100)

int main()
{
    int T = 0, idx = 0;
    char str[MAX_ENTRY][MAX_INPUT] = {0};
    int score[MAX_ENTRY] = {0};

    scanf("%d", &T);
    //printf("T = %d\n", T);

    while(idx < T)
    {   
        scanf("%s", str[idx]);

	//printf("idx = %d\n", idx);
	idx++;
    }


    int i = 0;
    while(i < T)
    {
	int j = 0, k = 0;

	while(str[i][j] != '\0')
	{
	    if (str[i][j] == 'O')
	    {
		k++;
		score[i] += k;
	    }
	    else
	    {
		k = 0;
	    }
	    
            j++;
	}

	printf("%d\n", score[i++]);
    }

    return 0;
}
