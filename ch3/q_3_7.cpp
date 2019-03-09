#include <stdio.h>
#include <string.h>

//#define _LOCAL_

#define MIN_ROW         (4)
#define MAX_ROW         (50)
#define MIN_COLUMN      (4)
#define MAX_COLUMN      (1000)
#define NUCLEOTIDES_NUM (4)

char S[MAX_ROW][MAX_COLUMN] = {0};  // DNA sequences
char consensus[MAX_COLUMN] = {0};   // consensus string

char nucleotides[NUCLEOTIDES_NUM] = {'A', 'C', 'G', 'T'};
int  cnt[NUCLEOTIDES_NUM] = {0};

char getNucelotide(int *arr, int * ret)
{
    int max = arr[0];
    char idx = 0;

    for (int i = 1; i < NUCLEOTIDES_NUM; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
            idx = i;
        }
    }

    *ret = max;
    return nucleotides[idx];
}

int main()
{
#ifdef _LOCAL_
    freopen("input_3_7.txt", "r", stdin);
    freopen("output_3_7.txt", "w", stdout);
#endif

    int i = 0;
    int totalNum = 0;

    scanf("%d", &totalNum);
    getchar();          // read '\n'

    while(i < totalNum)
    {
        int row = 0, column = 0;
        int tmp = 0, errNum = 0;

        scanf("%d %d", &row, &column);
        getchar();      // read '\n'

        for (int k = 0; k < row; k++)
        {
            scanf("%[^\n]", S[k]);
            getchar();
        }

        for (int c = 0; c < column; c++)
        {
            memset(cnt, 0, sizeof(cnt));

            for (int r = 0; r < row; r++)
            {
                int j = 0;

                while(j < NUCLEOTIDES_NUM)
                {
                    if (S[r][c] == nucleotides[j])
                    {
                        cnt[j]++;
                        break;
                    }
                    j++;
                }
            }

            printf("%c", getNucelotide(cnt, &tmp));

            errNum += tmp;
        }
        printf("\n%d\n", row*column-errNum);

        i++;
    }
}