#include <cstdio>

char oil[105][105];
int m,n;
int x[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
int y[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
bool dfs(int p,int q) {
	oil[p][q]='*';
	int i,a,b;
	for(i=0;i<8;i++) {
		a=p+x[i],b=q+y[i];
		if(a>=0&&b>=0&&a<m&&b<n && oil[a][b]=='@') {
			dfs(a,b);
		}
	}
}

int main() {
	int i,j,ans;
	while(scanf("%d %d",&m,&n),m) {
		ans=0;
		for(i=0;i<m;i++)
			scanf("%s",oil[i]);
		for(i=0;i<m;i++) {
			for(j=0;j<n;j++) {
				if(oil[i][j]=='@') {
					ans++;
					dfs(i,j);
				}
			}
		}
		printf("%d\n",ans);
	}
}