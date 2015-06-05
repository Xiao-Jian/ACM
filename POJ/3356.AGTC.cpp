/*
OJ: POJ
ID: 3013216109
TASK: 3356.AGTC
LANG: C++
NOTE: DP
*/
#include <cstdio>

const int MAX=1005;
int m,n,i,j,k;
char a[MAX],b[MAX];
int dp[MAX][MAX],c[MAX];

int min(int x,int y,int z) {
    if(x<+y&&x<=z)
        return x;
    if(y<=x&&y<=z)
        return y;
    if(z<=x&&z<=y)
        return z;
}

int main()
{
    while(scanf("%d %s",&m,a)!=EOF) {
        scanf("%d %s",&n,b);
        for(i=0;i<=m;i++)
            dp[i][0]=i;
        for(j=0;j<=n;j++)
            dp[0][j]=j;
        k=0;
        for(i=1;i<=m;i++) {
            for(j=1;j<=n;j++) {
                if(a[i-1]==b[j-1])
                    dp[i][j]=dp[i-1][j-1];
                else
                    dp[i][j]=min(dp[i-1][j-1],dp[i-1][j],dp[i][j-1])+1;
            }
        }
        printf("%d\n",dp[m][n]);
    }
    return 0;
}
