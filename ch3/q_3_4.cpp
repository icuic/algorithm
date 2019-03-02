#include <stdio.h>
#include <string.h>

#define MAX_ENTRY   (100)
#define MAX_LEN     (80)

int main()
{
    char str[MAX_ENTRY][MAX_LEN + 5] = {0};
    char period[MAX_ENTRY] = {0};
    
    int n = 0, i = 0, j = 0, k = 0;
    
    scanf("%d\n", &n);
    
    while(i < n)
    {
        scanf("%s", str[i]);
        i++;
    }

    while(k < n)
    {
        char head = str[k][0];
        int len = strlen(str[k]);
        
        i = 1;
       
        while(i < len)
        {
            if (head == str[k][i])  // 找到和第一个字符相同的元素
            {
                if (len % i == 0)   // 确定i能被字符串长度整除
                {
                    for (j = 1; j < len / i; j++)   // 比对余下的字符串
                    {                        
                        if ( strncmp(&str[k][0], &str[k][i*j], i) != 0 )                        
                        {                           
                            break;      // 发现i不是周期,跳出for循环，继续更新i
                        }                                                 
                    }

                    if (j == len / i)   // 字符串比对完毕，确认i是最小周期
                    {
                        period[k] = i;
                        break;          // 跳出while(i < len)循环，处理下一字符串
                    }  
                }                                      
            }
            
            i++;
        }
        
        if (i == len)   // 未找到周期，将字符串长度作为其周期
        {            
            period[k] = len;
        }
     
        printf("%d\n\n", period[k]);
  
        k++;
    }
}
