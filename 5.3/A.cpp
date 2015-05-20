#include <cstdio>

int x,y,k,n,sum,i,j;

int main()
{
    while(scanf("%d %d %d",&y,&k,&n)!=EOF) {
        int flag=0;
        for(i=k;i<=n;i+=k) {
            if(i>y) {
                flag=1;
                if(i+k>=n)
                    printf("%d\n",i-y);
                else
                    printf("%d ",i-y);
            }
        }
        if(!flag) puts("-1");
    }
}
