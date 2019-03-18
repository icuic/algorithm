#include <stdio.h>
#include <string.h>

#define _LOCAL_

#define MAX_WIDTH       (10000)
#define INPUT_NUM       (6)

typedef struct
{
    int width;
    int high;
}stRectangle;

stRectangle rectangle[INPUT_NUM];

bool reOrder(stRectangle arr[INPUT_NUM])
{
    for (int i = 0; i < INPUT_NUM; i++)
    {
        if (arr[i].width > arr[i].high)
        {
            int tmp; 
            tmp = arr[i].width;
            arr[i].width = arr[i].high;
            arr[i].high = tmp;            
        }        
    }
    
    int limit = 3;
    bool bFlag[INPUT_NUM] = {0};
    
    for (int i = 0; i < limit; i++)
    {
        if (bFlag[i] == 0)
        {
            bFlag[i] = 1;
            
            int j = i + 1;
            for (; j < INPUT_NUM; j++)
            {
                if (bFlag[j] == 0 && 
                    arr[i].width == arr[j].width &&
                    arr[i].high == arr[j].high)
                {
                    bFlag[j] = 1; 
                    limit++;   
                    break;
                }                
            }     
            
            if (j == INPUT_NUM)
                return false;
        } 
        else
        {
            //limit++;
        }
    } 
    
    for (int i = 0; i < INPUT_NUM; i++)
    {
        if (bFlag[i] == 0)
            return false;        
    }
    
    return true;
}

int main()
{

#ifdef _LOCAL_
    freopen("input_3_10.txt", "r", stdin);
    freopen("output_3_10.txt", "w", stdout);
#endif
    
    while(1)
    {
        memset(rectangle, 0, sizeof(rectangle));
        
        for (int i = 0; i < INPUT_NUM; i++)
        {
            if (scanf("%d %d", &rectangle[i].width, &rectangle[i].high) == EOF)
                return 0;            
        }
        
        if (reOrder(rectangle) == true)
        {
            printf("POSSIBLE\n");
        }
        else
        {
            printf("IMPOSSIBLE\n");            
        }
    }
}