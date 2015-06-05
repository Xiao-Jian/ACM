/*
OJ: POJ
ID: 3013216109
TASK: 2127.Greatest Common Increasing Subsequence
LANG: C++
NOTE: DP
*/
#include <cstdio>
#include <cstring>

const int MAX=505;
int a[MAX],b[MAX],ma[MAX];
int c[MAX][MAX],d[MAX][MAX];

int main()
{
	int m,n,i,j,k;
	while(scanf("%d",&m)!=EOF) {
		for(i=0;i<m;i++)
			scanf("%d",&a[i]);
		scanf("%d",&n);
		for(i=0;i<n;i++)
			scanf("%d",&b[i]);

		memset(c,0,sizeof(c));
		memset(d,-1,sizeof(d));
		for(i=0;i<m;i++) {
			for(j=0;j<n;j++) {
				if(a[i]!=b[j])
					c[i][j]=c[i][j-1];
				else {
					int l=0,flag=0;
					for(k=0;k<i;k++)
						if(a[k]<a[i]) {
							if(l<c[k][j-1]) {
								l=c[k][j-1];
								flag=k;
							}
						}
					if(l+1>c[i][j]) {
						c[i][j]=l+1;
						d[i][j]=flag;
					}
				}
			}
		}

		int l=0,x=0,y=0;
		for(i=0;i<m;i++)
			for(j=0;j<n;j++)
				if(l<c[i][j]) {
					l=c[i][j];
					x=i;y=j;
				}
		printf("%d\n",l);

		ma[0]=a[x];
		for(i=1;i<l;) {
			if(d[x][y]>=0) {
				ma[i++]=a[d[x][y]];
				x=d[x][y];
			}
			y--;
		}
		for(i=l-1;i>0;i--)
			printf("%d ",ma[i]);
		if(l!=0)
			printf("%d\n",ma[0]);
	}
	return 0;
}
