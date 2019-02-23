#include <stdio.h>

int main()
{
    // size of type
    printf("sizeof(char) = %ld\n", sizeof(char));
    printf("sizeof(short) = %ld\n", sizeof(short));
    printf("sizeof(int) = %ld\n", sizeof(int));
    printf("sizeof(long) = %ld\n", sizeof(long));
    printf("sizeof(long long) = %ld\n", sizeof(long long));
 
    printf("sizeof(float) = %ld\n", sizeof(float));
    printf("sizeof(double) = %ld\n", sizeof(double));
 
    // get input
    int line_num;

    scanf("%d", &line_num);

    if (line_num > 20)
        return 1;

    for (int i = 0; i < line_num; i++)		// line loop
    {
        int total_char = line_num * 2 - 1;

	for (int j = 0; j < total_char; j++)    // row loop
	{
            printf("%s", (j < i || j >= (total_char - i)) ? " " : "#");
	}

	printf("\n");
    }

    return 0;
}
