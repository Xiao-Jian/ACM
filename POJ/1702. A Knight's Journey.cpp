/*
OJ: TOJ
ID: 3013216109
TASK: 1702.A Knight's Journey
LANG: C++
NOTE: DFS
*/
#include <cstdio>
#include <cstring>

int n,p,q,flag;
int x[8]={-2,-2,-1,-1,1,1,2,2};
int y[8]={-1,1,-2,2,-2,2,-1,1};
char tmp[27]={"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
char ans1[27];
int ans2[27];
int visited[35][35];

bool dfs(int a,int b) {
    if(!visited[a][b]) visited[a][b]=1;
    else return false;
    ans1[flag]=tmp[a-1];
    ans2[flag]=b;
    flag++;
    if(flag>=p*q) return true;
    for(int i=0;i<8;i++) {
		if(a+x[i]>0&&a+x[i]<=p&&b+y[i]>0&&b+y[i]<=q&&dfs(a+x[i],b+y[i]))
            return true;
	}
	visited[a][b]=0;
	flag--;
	return false;
}

int main()
{
    scanf("%d",&n);
    int i,j,k=1;
    while(n--) {
        printf("Scenario #%d:\n",k++);
        scanf("%d %d",&q,&p);
        flag=0;
        memset(visited,0,sizeof(visited));
        int solved=0;
        for(i=1;i<=p;i++) {
            for(j=1;j<=q;j++) {
                if(dfs(i,j)) {
                    solved=1;
                    for(int l=0;l<p*q;l++)
                        printf("%c%d",ans1[l],ans2[l]);
                    printf("\n\n");
                break;
                }
            }
        }
        if(!solved)
            printf("impossible\n\n");
    }
    return 0;
}

