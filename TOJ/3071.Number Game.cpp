/*
OJ: TOJ
ID: 3013216109
TASK: 3071.Number Game
LANG: C++
NOTE: BFS
*/
#include <cstdio>
#include <cstring>
#include <queue>

int ans,t,k,p,visited[100005];
struct node {
    int x,num;
}begin,next,current;

int bfs() {
    std::queue<node> q;
    begin.x=k;
    begin.num=0;
    q.push(begin);
    visited[k]=1;

    while(!q.empty()) {
        for(int i=0;i<3;i++)
        {
            if(i==0)
                next.x=q.front().x*2;
            else if(i==1)
            {
                if(q.front().x%2==0)
                    next.x=q.front().x/2;
            }
            else if(i==2)
                next.x=q.front().x+1;
            next.num=q.front().num+1;
            if(next.x==p) return next.num;
            if(next.x>0&&next.x<100000&&!visited[next.x]) {
                q.push(next);
                visited[next.x]=1;
            }
        }
        q.pop();
    }
	return 0;
}

int main()
{
	scanf("%d",&t);
	while(t--) {
		memset(visited,0,sizeof(visited));
		scanf("%d %d",&k,&p);
		ans=bfs();
		if(ans) printf("%d\n",ans);
		else printf("-1\n");
	}
}
