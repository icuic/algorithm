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
stRectangle tmpRect[INPUT_NUM/2];

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
    
    int k = 0;
    int limit = INPUT_NUM/2;
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
                    
                    tmpRect[k].width = arr[i].width;
                    tmpRect[k].high = arr[i].high;
                    k++;
                    
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
    
    if (k == INPUT_NUM/2)
    {
        for (int x = 0; x < INPUT_NUM/2-1; x++)
        {
            for (int y = x+1; y < INPUT_NUM/2; y++)
            {
                if (tmpRect[y].width < tmpRect[x].width ||
                    (tmpRect[y].width == tmpRect[x].width) && tmpRect[y].high < tmpRect[x].high)
                {
                    stRectangle RECT;
                    // memcpy(&RECT, &tmpRect[x], sizeof(rectangle));
                    // memcpy(&tmpRect[x], &tmpRect[y], sizeof(rectangle));
                    // memcpy(&tmpRect[y], &RECT, sizeof(rectangle));
                    
                    RECT.width = tmpRect[x].width;
                    RECT.high = tmpRect[x].high;
                    
                    tmpRect[x].width = tmpRect[y].width;
                    tmpRect[x].high = tmpRect[y].high;
                    
                    tmpRect[y].width = RECT.width;
                    tmpRect[y].high = RECT.high;
                }
            }            
        }
        
        if (tmpRect[0].width != tmpRect[1].width ||
            tmpRect[1].high != tmpRect[2].high ||
            tmpRect[0].high != tmpRect[2].width)
            return false;        
    }
    else
    {
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
        memset(tmpRect, 0, sizeof(tmpRect));
        
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