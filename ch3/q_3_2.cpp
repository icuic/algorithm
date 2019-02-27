#include <stdio.h>
#include <string.h>

#define M_C (12.01)
#define M_H (1.008)
#define M_O (16.00)
#define M_N (14.01)

#define MAX_FORMULA (100)
#define MAX_LENGTH  (80)

char isCHON(char x)
{
    if (x == 'C' || x == 'H' || x == 'O' || x == 'N')
    return x;
    else
    return x - '0';
}

int main()
{
    int n = 0; 
    int i = 0, j = 0, k = 0;
    char formula[MAX_FORMULA][MAX_LENGTH] = {0};
    
    scanf("%d", &n);
    
    while(i < n)
    { 
        scanf("%s", formula[i++]);
    }

    while(j < n)
    {
        k = 0;
        char numberAhead = 0xFF;   
        char m = 0, n = 0;
        char symbol[MAX_LENGTH * 2] = {0};
        char number[MAX_LENGTH * 2] = {0}; 
        
        memset(number, 1, MAX_LENGTH*2);
        
        while(formula[j][k] != '\0')
        {
            char ret = isCHON(formula[j][k]);       
            
            if (ret == 'C' || ret == 'H' || ret == 'O' || ret == 'N')
            {
                symbol[m++] = ret;
                
                if (numberAhead == 0)
                {
                    number[n] = 1;
                    n++;
                }
                else if (numberAhead == 1)
                {
                    n++;
                }
                
                numberAhead = 0;
            }
            else
            {
                if (numberAhead == 1)
                {
                    number[n] *= 10;
                    number[n] += ret;
                }
                else if (numberAhead == 0)
                {
                    number[n] = ret;      
                }
                
                numberAhead = 1;
            }
            
            k++;
        }
        
        n++;
        //number[n] = 1;

/*         for (int x = 0; x < m; x++)
            printf("%c  ", symbol[x]);
        
        printf("\n");
        
        for (int y = 0; y < n; y++)
            printf("%d ", number[y]);
        
        printf("\n\n");
 */        
        float s = 0;
        
        for (int x = 0; x < m; x++)
        {
            float mass = 0;
            
            switch (symbol[x])
            {
                case 'C':
                    mass = M_C;
                    break;

                case 'H':
                    mass = M_H;
                    break;
                
                case 'O':
                    mass = M_O;
                    break;

                case 'N':
                    mass = M_N;
                    break;
            }

            s += mass * number[x];
        }

        printf("%.3f\n", s);
        
        j++;
    
    }
    return 0;
}
