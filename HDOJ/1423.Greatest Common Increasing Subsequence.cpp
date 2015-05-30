#include <cstdio>
#include <cstring>

const int MAX=505;
int a[MAX],b[MAX],ma[MAX];
int c[MAX][MAX];
int t,m,n,i,j,k,l;

int main()
{
	scanf("%d",&t);
	while(t--) {
		scanf("%d",&m);
		for(i=1;i<=m;i++)
			scanf("%d",&a[i]);
		scanf("%d",&n);
		for(i=1;i<=n;i++)
			scanf("%d",&b[i]);

		memset(c,0,sizeof(c));
		for(i=1;i<=m;i++)
			for(j=1;j<=n;j++) {
				if(a[i]==b[j]) {
					l=0;
					for(k=1;k<j;k++) {
						if(b[k]<b[j]&&l<c[i-1][k])
							l=c[i-1][k];
					}
					c[i][j]=l+1;
				}
				else c[i][j]=c[i-1][j];
			}
		l=0;
		for(i=0;i<=n;i++)
			if(l<c[m][i])
				l=c[m][i];
		printf("%d\n",l);
		if(t) printf("\n");
	}
}