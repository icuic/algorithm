#include <stdio.h>
#include <string.h>

#define _LOCAL_

//#define MAX_LENGTH      (100000)

char s[MAX_LENGTH] = {0};
char t[MAX_LENGTH] = {0};

int main()
{

#ifdef _LOCAL_
    freopen("input_3_9.txt", "r", stdin);
    freopen("output_3_9.txt", "w", stdout);
#endif

    while(1)
    {
        if(scanf("%s %s", s, t) == EOF)
            return 0;
        
        int lens = strlen(s);
        int lenl = strlen(t);
        
        int i = 0, j = 0;
        
        while(i < lens && j < lenl)
        {
            if (s[i] == t[j])
            {
                i++;
                j++;
            }
            else
            {
                j++;
            }            
        }
        
        if (i == lens)
            printf("Yes\n");
        else
            printf("No\n");
    }
}