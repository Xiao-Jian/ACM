#include <stdio.h>

int sum[32768];
struct node{
    int num,data;
}q[32768];

int main()
{
    int n,l,u,i,j,k;
    while(scanf("%d",&n),n) {
        scanf("%d %d",&l,&u);
        sum[0]=0;
        for(i=1;i<=n;i++) {
            scanf("%d",&sum[i]);
            sum[i]+=sum[i-1];
        }
        int f=0,t=0,m=9999999;
        for(i=l;i<=n;i++) {
            while(f<t && sum[i-l]>q[t-1].data)
                t--;
            q[t].num=i-l;
            q[t].data=sum[i-l];
            t++;
            while(q[f].num+u<i)
                f++;
            if(m>(sum[i]-q[f].data))
                m=sum[i]-q[f].data;
        }
        printf("%d\n",m);
    }
    return 0;
}
