/*
OJ: TOJ
ID: 3013216109f
TASK: 1765.Longest Ordered Subsequence
LANG: C++
NOTE: LOS(DP)
*/
#include <cstdio>

const int MAX=1005;
int dp[MAX],a[MAX];

int main()
{
	int n,m=0,i,j,k;
	scanf("%d",&n);
	for(i=0;i<n;i++) {
		scanf("%d",&a[i]);
		dp[i]=1;
	}
	for(i=1;i<n;i++)
		for(j=0;j<i;j++)
			if(a[i]>a[j]) {
				if(dp[i]<dp[j]+1)
					dp[i]=dp[j]+1;
			}
	for(i=0;i<n;i++)
		if(m<dp[i])
			m=dp[i];
	printf("%d\n",m);
}