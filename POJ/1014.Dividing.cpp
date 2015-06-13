/*
OJ: POJ
ID: 3013216109
TASK: 1014.Dividing
LANG: C++
NOTE: DFS
*/
#include <cstdio>

int n[6],k=1,sum;

bool dfs(int x) {
    if(x==sum/2) return true;
    for(int i=5;i>=0;i--) {
        if(n[i]&&x+i+1<=sum/2) {
            n[i]--;
            if(dfs(x+i+1))
                return true;
        }
    }
    return false;
}

int main()
{
    while(scanf("%d",&n[0])!=EOF) {
        sum=n[0];
        for(int i=1;i<6;i++) {
            scanf("%d",&n[i]);
            sum+=(n[i]*(i+1));
        }
        if(sum==0) break;
        printf("Collection #%d:\n",k++);
        if(sum%2==1) {
            printf("Can't be divided.\n\n");
            continue;
        }
        if(dfs(0))
            printf("Can be divided.\n\n");
        else
            printf("Can't be divided.\n\n");
    }
    return 0;
}
