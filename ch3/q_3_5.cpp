#include <stdio.h>
#include <string.h>

#define PUZZLE_SCALE     (5)
#define MAX_PUZZLE_NUM  (20)
#define STEPS_SIZE      (20)
#define BUFFER_LENGTH   (20)

typedef struct
{
    char puzzle[PUZZLE_SCALE][PUZZLE_SCALE];
    char steps[STEPS_SIZE];
}stPuzzle;

// 找到空格的坐标
void findSpace(char arr[][PUZZLE_SCALE], char *x, char *y)
{
    int i = 0, j = 0;
    
    while(i < PUZZLE_SCALE)
    {
        j = 0;
        
        while(j < PUZZLE_SCALE)
        {
            if (arr[i][j] == ' ')
            {
                *x = i;
                *y = j;
                
                return;
            }
            
            j++;
        }
        
        i++;
    }    
}

int main()
{
    char buffer[BUFFER_LENGTH] = {0};  // 用于临时接收每一行输入的字符
    stPuzzle puzzles[MAX_PUZZLE_NUM] = {0};
    char puzzle_id = 0;
    char i = 0, j = 0;
    
    // 从标准输入读取所有输入
    for (;;)
    {   
        // 从标准输入读取5行谜题数据
        i = 0;
        fgets(buffer, BUFFER_LENGTH, stdin);
        
        if (buffer[0] == 'Z')
        {
            // 结束读取
            break;              
        }
        else
        {
            memcpy(puzzles[puzzle_id].puzzle[i++], buffer, PUZZLE_SCALE);            
        }
        
        while(i < PUZZLE_SCALE)
        {
            fgets(puzzles[puzzle_id].puzzle[i++], BUFFER_LENGTH, stdin);
        }
     
        // 从标准输入读取1行移动指令
        i = 0;
        int offset = 0;
        
        for (;;)
        {
            memset(buffer, 0xFF, BUFFER_LENGTH);
            fgets(buffer, BUFFER_LENGTH, stdin);

            memcpy(&puzzles[puzzle_id].steps[offset], buffer, strlen(buffer)-1);    // 去掉末尾的\n
            offset += strlen(buffer) - 1;

            if (puzzles[puzzle_id].steps[offset-1] == '0')
            {
                // 结束读取
                break;
            }
        }     
    
        puzzle_id++;
    }
#if 0
    for (i  = 0; i < puzzle_id; i++)
    {
        for (j = 0; j < PUZZLE_SCALE; j++)
        {
            for (int k = 0; k < PUZZLE_SCALE; k++)
            {
                printf("%c", puzzles[i].puzzle[j][k]);
                
                if (k < PUZZLE_SCALE - 1)
                    printf(" "); 
                else
                    printf("\n");
            }
        }
        
        printf("%s\n", puzzles[i].steps);
    }
#endif


    for (i = 0; i < puzzle_id; i++)
    {
        bool bRet = true;
        
        char row = 0, column = 0;
        findSpace(puzzles[i].puzzle, &row, &column);
        // printf("\n## row = %d, column = %d\n", row, column);

        for (j = 0; j < strlen(puzzles[i].steps); j++)
        {               
            switch (puzzles[i].steps[j])
            {
                case 'A':
                    if (row == 0)
                    {
                        bRet = false;
                    }
                    else                    
                    {
                        puzzles[i].puzzle[row][column] = puzzles[i].puzzle[row - 1][column];
                        puzzles[i].puzzle[row - 1][column] = ' ';
                        row -= 1;
                    }
                    break;

                case 'B':
                    if (row == PUZZLE_SCALE - 1)
                    {
                        bRet = false;
                    }
                    else                    
                    {
                        puzzles[i].puzzle[row][column] = puzzles[i].puzzle[row + 1][column];
                        puzzles[i].puzzle[row + 1][column] = ' ';
                        row += 1;
                    }
                    break;
                    
                case 'L':
                    if (column == 0)
                    {
                        bRet = false;
                    }
                    else                    
                    {
                        puzzles[i].puzzle[row][column] = puzzles[i].puzzle[row][column - 1];
                        puzzles[i].puzzle[row][column - 1] = ' ';
                        column -= 1;
                    }
                    break;                    

                case 'R':
                    if (column == PUZZLE_SCALE - 1)
                    {
                        bRet = false;
                    }
                    else                    
                    {
                        puzzles[i].puzzle[row][column] = puzzles[i].puzzle[row][column + 1];
                        puzzles[i].puzzle[row][column + 1] = ' ';
                        column += 1;
                    }
                    break; 
                    
                case '0':
                    break;
                    
                default:
                    bRet = false;
                    break;
            }
            
        }
        
        printf("Puzzle #%d:\n", i + 1);
        if (bRet == false)
        {
            printf("This puzzle has no final configuration.\n");            
        }
        else
        {
            for (int j = 0; j < PUZZLE_SCALE; j++)
            {
                for (int k = 0; k < PUZZLE_SCALE; k++)
                {
                    printf("%c", puzzles[i].puzzle[j][k]);
                    
                    if (k < PUZZLE_SCALE - 1)
                        printf(" "); 
                    else
                        printf("\n");
                }               
            }            
        }
        
        //if (j < PUZZLE_SCALE - 1)
            printf("\n");

    }
      
    return 0;
}