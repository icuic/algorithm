#include <stdio.h>
#include <string.h>
#include <algorithm>

#define PUZZLE_SCALE     (5)
#define MAX_PUZZLE_NUM  (10)
#define STEPS_SIZE      (20)
#define BUFFER_LENGTH   (20)

typedef struct
{
    char puzzle[PUZZLE_SCALE][PUZZLE_SCALE];    // 题面
    char steps[STEPS_SIZE];     //  移动步骤
}stPuzzle;

stPuzzle puzzles[MAX_PUZZLE_NUM] = {0};

using namespace std;

// 找到空格的坐标
bool findSpace(char arr[][PUZZLE_SCALE], char *x, char *y)
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
                
                return true;
            }            
            j++;
        }        
        i++;
    }

    return false;
}

char getInput()
{
    char buffer[BUFFER_LENGTH] = {0};  // 用于临时接收每一行输入的字符
    
    int i = 0, j = 0;
    char puzzle_id = 0;         // 用于遍历多组题目
    
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

    return puzzle_id;
}

void processInput(char total)
{
    int i = 0;
    
    for (i = 0; i < total; i++)
    {
        bool bRet = true;
        char row = 0, column = 0;
        
        if(findSpace(puzzles[i].puzzle, &row, &column))
        {
            for (int j = 0; j < strlen(puzzles[i].steps); j++)
            {   
                char oldX = row;
                char oldY = column;
                
                switch (puzzles[i].steps[j])
                {
                    case 'A':   row -= 1;       break;                        
                    case 'B':   row += 1;       break;                        
                    case 'L':   column -= 1;    break;                        
                    case 'R':   column += 1;    break;                        
                    case '0':                   break;                        
                    default:    bRet = false;   break;                    
                }
                
                if (row < 0 || row > PUZZLE_SCALE - 1 || column < 0 || column > PUZZLE_SCALE - 1)
                {
                    bRet = false; 
                    break;
                }
                else
                {
                    swap(puzzles[i].puzzle[row][column], puzzles[i].puzzle[oldX][oldY]);
                }                                       
            }
        }
        else
        {
            bRet = false;
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
        
        if (i < total - 1)
            printf("\n");

    }    
}

int main()
{    
    char totalPuzzleNum = getInput();

    processInput(totalPuzzleNum);
      
    return 0;
}