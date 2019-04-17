#include <stdio.h>
#include <string.h>
#include <math.h>

#define _LOCAL_

int main()
{
    
#ifdef _LOCAL_
    freopen("input_3_12.txt", "r", stdin);
    freopen("output_3_12.txt", "w", stdout);
#endif

    int i,j;
    double M[20][40];
    long long N[20][40];
    
    for (i = 0; i < 10; i++)
    {
        for (j = 1; j < 31; j++)
        {
            double m = 1 - pow(0.5, i+1), e = pow(2,j) - 1;
            double t = log10(m) + e * log10(2);
            N[i][j] = t;
            M[i][j] = pow(10, t-N[i][j]);
        }
    }
    
    char st[22];
    while(scanf("%s",&st))
    {   
        if(st[0] == '0' && st[1] == 'e' && st[2] == '0') 
            break;
        
        int len = strlen(st), a, b;
        
        for(i = 0; i < len; i++)
        {
            if(st[i]=='e') 
            {
                a=i;
                break;
            }
        }
        
        double A = st[0] - 48;
        
        for(i = 2; i < a; i++)
        {
            A += (st[i] - 48) *pow(10, 1-i);
        }
        
        int B=0;
        
        for(i = len - 1; i > a; i--)
        {
            B += (st[i] - 48) * pow(10, len-i-1);
        }
        
        for(i = 0; i < 10; i++)
        { 
            int flag = 0;
            for(j = 0; j < 31; j++)
            {
                if(fabs(M[i][j] - A) < 1e-4 && B == N[i][j]) 
                {
                    printf("%d %d\n", i, j);
                    flag=1;
                    break;
                }
            }
        
            if(flag) 
                break;
        }
    }
    return 0;
}