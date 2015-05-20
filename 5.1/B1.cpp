#include <cstdio>

const int N = 32768;
int sum[N];
int f,t,n,l,u;
struct node{
    int num,data;
}q[N];

int func() {
    int m=99999999;
    f=t=0;
    for(int i=l;i<=n;i++) {
        while(f<t && sum[i-l]>q[t-1].data)
            t--;
        q[t].num=i-l,q[t].data=sum[i-l];
        t++;
        while(q[f].num+u<i)
            f++;
        int tmp=sum[i]-q[f].data;
        if(m>tmp)
            m=tmp;
    }
    return m;
}

int main()
{
    while(scanf("%d",&n),n) {
        scanf("%d %d",&l,&u);
        sum[0]=0;
        for(int i=1;i<=n;i++) {
            scanf("%d",sum+i);
            sum[i]+=sum[i-1];
        }
        printf("%d\n",func());
    }
    return 0;
}
