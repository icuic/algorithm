#include <cstdio>
#include <stack>

using namespace std;
const int MAXN = 1000 + 10;

int n, target[MAXN];

int main()
{
    while(scanf("%d", &n) == 1)
    {
        stack <int> s;
        int A = 1, B = 1; //B is used to loop numbers inputed, A is used to loop 1 ~ n
        
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &target[i]);
        }
/*
        printf("B: ");
        for (int i = 1; i <= n; i++ )
        {
            printf("%d ", target[i]);
        }
        printf("\n");

	printf("A: ");
        for (int i = 1; i <= n; i++)
	{
	    printf("%d ", i);
	}
        printf("\n");
*/

        int ok = 1;

        while(B <= n)
        {
            if (A == target[B])
            {
                A++;
                B++;
            }
            else if (!s.empty() && s.top() == target[B])
            {
                s.pop();
                B++;
            }
            else if (A <= n)
            {
                s.push(A++);
            }
            else
            {
                ok = 0;
                break;
            }
        }

        printf("%s\n\n", ok ? "Yes" : "No");

    }
    
    return 0;
}
