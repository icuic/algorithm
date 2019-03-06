#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

#define LOCAL

#define PUZZLE_SCALE		(5)
#define MAX_PUZZLE_NUM		(1000)
#define MAX_MOVE_SIZE		(1000)
#define MAX_BUFFER_SIZE		(1000)

#pragma pack(1)
typedef struct
{
	int x;
	int y;
}stPosition;

typedef struct
{
	char puzzle[PUZZLE_SCALE][PUZZLE_SCALE + 1];
	char move[MAX_MOVE_SIZE];
	stPosition blankPosition;
}stPuzzle;
#pragma pack()

static stPuzzle puzzles[MAX_PUZZLE_NUM] = {0};
static char buffer[MAX_BUFFER_SIZE];

int idx = 0;

int main(void)
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif    
    
	int i = 0, j = 0, k = 0;
	
	for (;;)
	{
		i = 0;
		
		while(i < PUZZLE_SCALE)
		{
			scanf("%[^\n]", buffer);	// stop on '\n'
			getchar();					// read '\n'	
			
			if ( buffer[0] == 'Z')
				goto START_PROCESS;

			char *ret = (char *)memchr(buffer, ' ', PUZZLE_SCALE);	// find space			
			if (ret != NULL)
			{				
				puzzles[idx].blankPosition.x = i;
				puzzles[idx].blankPosition.y = ret - buffer;
			}
			else if (strlen(buffer) == PUZZLE_SCALE - 1)
			{
				puzzles[idx].blankPosition.x = i;
				puzzles[idx].blankPosition.y = 4;	// if there are only 4 characters in a line, then the 5 character is space by default
				
				buffer[PUZZLE_SCALE - 1] = ' ';
			}

			memcpy(&puzzles[idx].puzzle[i++][0], buffer, PUZZLE_SCALE);
		}

		scanf("%[^0]", puzzles[idx].move);								// stop on '0'
		puzzles[idx].move[strlen(puzzles[idx].move)] = getchar();		// read '0'
		getchar();															// read '\n'
		
		idx++;	
	}

START_PROCESS:

	// process input
	i = 0;

	while (i < idx)
	{
		bool bRet = true;		// have answer or not
		int preX = puzzles[i].blankPosition.x;
		int preY = puzzles[i].blankPosition.y;
		
		j = 0;
		
		while(puzzles[i].move[j] != '0')
		{
			int newX = preX;
			int newY = preY;
			
			// printf("##A: preX: %d, preY: %d, newX: %d, newY: %d\n", preX, preY, newX, newY);
			
			switch (puzzles[i].move[j])
			{
				case 'A':	newX -= 1; 		break;
				case 'B': 	newX += 1;		break;
				case 'L':	newY -= 1;		break;
				case 'R':	newY += 1;		break;
				case '\n':					
				case ' ':
				case '\t':					break;
				default:	bRet = false;	break;
			}
			
			if (newX < 0 || newX > PUZZLE_SCALE - 1 ||	\
				newY < 0 || newY > PUZZLE_SCALE - 1 || 	\
				bRet == false)
			{
				bRet = false;
				break;	
			}
	
			swap(puzzles[i].puzzle[preX][preY], puzzles[i].puzzle[newX][newY]);
			
			preX = newX;
			preY = newY;
			
			j++;		
		}
		
		printf("Puzzle #%d:\n", i + 1);
		
		if (bRet)
		{
			j = 0, k = 0;
			
			for (j = 0; j < PUZZLE_SCALE; j++)
			{
				for (k = 0; k < PUZZLE_SCALE; k++)
				{
					printf("%c", puzzles[i].puzzle[j][k]);
					
					(k < PUZZLE_SCALE - 1) ? printf(" ") : printf("\n");
				}
                
			}
		}
		else
		{
			printf("This puzzle has no final configuration.\n");
		}
		
        if (i < idx - 1)
            printf("\n");
        
		i++;
	}

	return 0;
}