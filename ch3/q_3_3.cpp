#include <stdio.h>

#define MAX_NUMBER  (10)
#define MAX_ENTRY   (20)
#define MAX_N       (10000)

int main()
{
    int n = 0;
    int array[MAX_ENTRY] = {0};
    int result[MAX_ENTRY][MAX_NUMBER] = {0};
    int i = 0, j = 0;
    
    scanf("%d", &n);
    
    while(i < n)
    {
        scanf("%d", &array[i]);
        i++;
    }
   
    printf("n = %d\n", n);
    
    i = 0;
    while(i < n)
    {
        printf("array[%d] = %d\n", i, array[i]);
        i++;
    }
   
    for (i = 0; i < n; i++)     // loop in cases
    {
        for (j = 1; j <= array[i]; j++)      // loop in integers
        {
            int k = j;
            
            result[i][k % 10]++;
            k /= 10;
  
            while(k)
            {
                result[i][k % 10]++;
                k /= 10;            
            }                
        }
    }
  
    for (i = 0; i < n; i++)     // loop in cases
    {
        for (j = 0; j < MAX_NUMBER; j++)    // loop in integers
        {
            printf("%d", result[i][j]);
            
            if (j < MAX_NUMBER - 1)
                printf(" ");
        }
        
        printf("\n");
    }

    return 0;
}