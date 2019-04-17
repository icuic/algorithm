#include <stdio.h>
#include <string.h>

#define _LOCAL_

#define MAX_LENGTH  (200+1)

#define S1_LENGTH   (int)strlen(s1)
#define S2_LENGTH   (int)strlen(s2)
#define S3_LENGTH   (int)strlen(s3)

char s1[MAX_LENGTH] = {0};
char s2[MAX_LENGTH] = {0};
char s3[MAX_LENGTH] = {0};

int main()
{

#ifdef _LOCAL_
    freopen("input_3_11.txt", "r", stdin);
    freopen("output_3_11.txt", "w", stdout);
#endif
    
    while(1)
    {
        memset(s1, 0, sizeof(s1));
        memset(s2, 0, sizeof(s2));
        
        if (scanf("%s", s1) == EOF)
            return 0;            
        
        scanf("%s", s2);
        
        if (S1_LENGTH < S2_LENGTH)
        {
            memset(s3, 0, sizeof(s3));
            memcpy(s3, s1, S1_LENGTH);
            
            memset(s1, 0, sizeof(s1));
            memcpy(s1, s2, S2_LENGTH);
            
            memset(s2, 0, sizeof(s2));
            memcpy(s2, s3, S3_LENGTH);
        }
        
        //printf("strlen(s1) = %d, strlen(s2) = %d\r\n", S1_LENGTH, S2_LENGTH);
        
        memset(s1 + S1_LENGTH, 0, S2_LENGTH);
        
        int i = 0, j = 0;
        int ret1 = 0, ret2 = 0;
        
        for (i = 0; i < S1_LENGTH; i++)
        {
            for (j = 0; j < S2_LENGTH; j++)
            {
                if ((s1[i+j] - '0') + (s2[j] - '0') > 3)
                    break;                                
            }
            
            if (j == S2_LENGTH)
            {
                break;
            }
        }
        
        if (i == S1_LENGTH)
        {
            ret1 = S1_LENGTH + S2_LENGTH;
        }
        else if (i + S2_LENGTH <= S1_LENGTH)
        {
            ret1 = S1_LENGTH;
        }
        else
        {
            ret1 = i + S2_LENGTH;            
        }  

        
        char *pEnd1 = s1 + S1_LENGTH - 1;
        char *pEnd2 = s2 + S2_LENGTH - 1;
        
         for (i = 0; i < S1_LENGTH; i++)
        {
            for (j = 0; j < S2_LENGTH; j++)
            {
                if ( (*(pEnd1 - i - j) - '0') + (*(pEnd2 - j) - '0') > 3 )
                    break;                              
            }
            
            if (j == S2_LENGTH)
            {
                break;
            }
        }
        
        if (i == S1_LENGTH)
        {
            ret2 = S1_LENGTH + S2_LENGTH;
        }
        else if (i + S2_LENGTH <= S1_LENGTH)
        {
            ret2 = S1_LENGTH;
        }
        else
        {
            ret2 = i + S2_LENGTH;            
        }    
        
        printf("ret1: %d, ret2: %d\n", ret1, ret2);
        
        //printf("%d\n", ret1 < ret2 ? ret1 : ret2);
    }
}