#include<stdio.h>
#include<string.h>
int step[30][30],s,que[30][30],q,p;
bool fix(int a,int b)
{
    if ((a>0)&&(a<=p)&&(b>0)&&(b<=q)) return 1;
    else return 0;
}
int dfs(int a,int b)
{
    if (!step[a][b]) step[a][b]=1;
    else return 0;
    que[s][0]=a;
    que[s++][1]=b;
    if (s>p*q) return 1;
    if (fix(a-2,b-1)&&(dfs(a-2,b-1))) return 1;
    if (fix(a-2,b+1)&&(dfs(a-2,b+1))) return 1;
    if (fix(a-1,b-2)&&(dfs(a-1,b-2))) return 1;
    if (fix(a-1,b+2)&&(dfs(a-1,b+2))) return 1;
    if (fix(a+1,b-2)&&(dfs(a+1,b-2))) return 1;
    if (fix(a+1,b+2)&&(dfs(a+1,b+2))) return 1;
    if (fix(a+2,b-1)&&(dfs(a+2,b-1))) return 1;
    if (fix(a+2,b+1)&&(dfs(a+2,b+1))) return 1;
    step[a][b]=0;
    s--;
    return 0;
}
int main()
{
    int n,solve,i,j,k;
    scanf("%d",&n);
    int cas=1;
    while (n--)
{
        printf("Scenario #%d:\n",cas++);
        memset(step,0,sizeof(step));
        s=1;
        solve=0;
        scanf("%d%d",&q,&p);
        for (i=1;i<=p;++i)
            for (j=1;j<=q;++j)
                if (dfs(i,j))
                {
                    solve=1;
                    for (k=1;k<=p*q;++k)
                    {
                        printf("%c%d",que[k][0]-1+'A',que[k][1]);
                    }
                    printf("\n\n");
                    break;
                }
        if (!solve) printf("impossible\n\n");
    }
    return 0;
}
