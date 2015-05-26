#include <cstdio>
#include <cstring>

int t,n,m,i,j,k;
int zw[1005][4],ip[55][4],num[55];
int v1[256][256],v2[256][256],v3[256][256];
int v4[256][256],v5[256][256],v6[256][256];

int main()
{
    scanf("%d",&t);
    int flag=1;
    while(t--) {
        scanf("%d %d",&n,&m);
        for(i=0;i<n;i++)
            scanf("%d.%d.%d.%d",&zw[i][0],&zw[i][1],&zw[i][2],&zw[i][3]);
        for(i=0;i<m;i++)
            scanf("%d.%d.%d.%d",&ip[i][0],&ip[i][1],&ip[i][2],&ip[i][3]);
        memset(num,0,sizeof(num));
        for(i=0;i<m;i++) {
            for(j=0;j<256;j++)
                for(k=0;k<256;k++) {
                    v1[j][k]=v2[j][k]=v3[j][k]=0;
                }
            for(j=0;j<n;j++) {
                int x=zw[j][0]&ip[i][0];
                int y=zw[j][1]&ip[i][1];
                int u=zw[j][2]&ip[i][2];
                int v=zw[j][3]&ip[i][3];
                //printf("%d %d %d %d\n",x,y,u,v);
                //printf("%d %d %d\n",v1[x][y],v2[y][u],v3[u][v]);
                if(v1[x][y]&&v2[x][u]&&v3[x][v]&&
                   v4[y][u]&&v5[y][v]&&v6[u][v])
                    num[i]--;
                num[i]++;
                v1[x][y]=v2[x][u]=v3[x][v]=1;
                v4[y][u]=v5[y][v]=v6[u][v]=1;
            }
        }
        printf("Case #%d:\n",flag++);
        for(i=0;i<m;i++)
            printf("%d\n",num[i]);
    }
}
