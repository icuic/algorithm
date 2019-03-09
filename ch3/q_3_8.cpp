#include <stdio.h>
#include <string.h>

#define _LOCAL_

#define MAX_DIVIDEND        (3000+5)

int quotient[MAX_DIVIDEND] = {0};              // 商
int reminder[MAX_DIVIDEND] = {0};              // 余数
bool reminderMap[MAX_DIVIDEND] = {0};          // 余数出现后对应元素置1

int main()
{
    
#ifdef _LOCAL_
    freopen("input_3_8.txt", "r", stdin);
    freopen("output_3_8.txt", "w", stdout);
#endif
    
    int numerators = 0, denominators = 0;       // numerators-分子, denominators-分母

    while(1)
    {        
        if (scanf("%d %d", &numerators, &denominators) == EOF)
            return 0;
        
        getchar();      // 清除缓存中的'\n'
        
        memset(quotient, 0, sizeof(quotient)); 
        memset(reminder, 0, sizeof(reminder));        
        memset(reminderMap, 0, sizeof(reminderMap));    
        
        int i = 0;                              // 循环节的最后一位
        int a = numerators;                     // 乘上10后作为下一次除法运算的被除数
 
        printf("%d/%d = ", numerators, denominators);
        
        while(1)
        {                       
            quotient[i] = a / denominators;
            reminder[i] = a % denominators;                               

            if (reminderMap[reminder[i]] == 0)            
            {
                reminderMap[reminder[i]] = 1;
                a = reminder[i] * 10;
                i++;            
            }
            else
            {
                break;
            }
        }

        printf("%d.", quotient[0]);
        
        int j = 0;              // while后指向循环节的第一位
        int len = 0;
        
        while(1)
        {                      
            if (reminder[j] == reminder[i])
            {
                break;
            }
            printf("%d", quotient[j+1]);  // 输出非循环位           
            j++;
        }
        
        len = i - j;            // 循环节长度
        
        printf("%c", '(');
        if (i > 50)
        {                       
            for (int k =j+1; k <= 50; k++)
            {
                printf("%d", quotient[k]);
            }
            printf("...%c\n", ')');
        }
        else
        {
            for (int k =0; k < len; k++)
            {
                printf("%d", quotient[j+1+k]);
            }
            printf("%c\n", ')');
        }
    
        printf("   %d = number of digits in repeating cycle\n\n", len);        
    }
}