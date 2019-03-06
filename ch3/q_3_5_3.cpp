#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

#define LOCAL

#define PUZZLE_SCALE		(5)
#define MAX_MOVE_SIZE		(100)
#define MAX_BUFFER_SIZE		(100)

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

static stPuzzle puzzles;
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
        bool bFlag = true;
		i = 0;

		while(i < PUZZLE_SCALE)
		{
			scanf("%[^\n]", buffer);	// stop on '\n'
			getchar();					// read '\n'

			if ( buffer[0] == 'Z')
				return 0;

            if (idx != 0 && bFlag)
            {
                bFlag = false;
                printf("\n"); 
            }                
            
			char *ret = (char *)memchr(buffer, ' ', PUZZLE_SCALE);	// find space
			if (ret != NULL)
			{
				puzzles.blankPosition.x = i;
				puzzles.blankPosition.y = ret - buffer;
			}
			else if (strlen(buffer) == PUZZLE_SCALE - 1)
			{
				puzzles.blankPosition.x = i;
				puzzles.blankPosition.y = PUZZLE_SCALE - 1;	// if there are only 4 characters in a line, then the 5 character is space by default

				buffer[PUZZLE_SCALE - 1] = ' ';
			}

			memcpy(&puzzles.puzzle[i++][0], buffer, PUZZLE_SCALE);
		}

		scanf("%[^0]", puzzles.move);								// stop on '0'
		puzzles.move[strlen(puzzles.move)] = getchar();		// read '0'
		getchar();															// read '\n'

		idx++;

        // process input

		bool bRet = true;		// have answer or not
		int preX = puzzles.blankPosition.x;
		int preY = puzzles.blankPosition.y;

		j = 0;
        while(puzzles.move[j] != '0')
		{
			int newX = preX;
			int newY = preY;

			// printf("##A: preX: %d, preY: %d, newX: %d, newY: %d\n", preX, preY, newX, newY);

			switch (puzzles.move[j])
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

			swap(puzzles.puzzle[preX][preY], puzzles.puzzle[newX][newY]);

			preX = newX;
			preY = newY;

			j++;
		}


        printf("Puzzle #%d:\n", idx);

		if (bRet)
		{
			j = 0, k = 0;

			for (j = 0; j < PUZZLE_SCALE; j++)
			{
				for (k = 0; k < PUZZLE_SCALE; k++)
				{
					printf("%c", puzzles.puzzle[j][k]);

					(k < PUZZLE_SCALE - 1) ? printf(" ") : printf("\n");
				}

			}
		}
		else
		{
			printf("This puzzle has no final configuration.\n");
		}
	}
}