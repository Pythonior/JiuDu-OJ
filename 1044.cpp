#include <cstdio>
#include <cstring>
const int maxm = 25;
int C[maxm][maxm];

int n;
char pre[30];
char last[30];

void initC()
{
    C[1][0] = C[1][1] = 1;
    for(int i = 2; i < maxm; i++)
    {
        C[i][0] = C[i][i] = 1;
        for(int j = 1; j < i; j++)
            C[i][j] = C[i-1][j] + C[i-1][j-1];
    }
}

int getResult(int p1, int p2, int q2)
{
    if(p2 == q2) return C[n][1];

    int result = 1;
    int m = 0;
    for(int i = p2; i <= q2; i++)
    {
        if(pre[p1] == last[i])
        {
            if(p2 < i) {
                result *= getResult(p1+1, p2, i-1);
            }
            p1 += i + 1 - p2;
            p2 = i + 1;
            m++;
        }
    }

    return C[n][m]*result;
}

int main()
{

    initC();
    while(scanf("%d%s%s", &n, pre, last) != EOF)
        printf("%d\n", getResult(1, 0, strlen(last) - 2));
    return 0;

}
