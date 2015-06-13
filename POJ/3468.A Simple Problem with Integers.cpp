/*
OJ: POJ
ID: 3013216109
TASK: 3468.A Simple Problem with Integers
LANG: C++
NOTE: 线段树
*/
#include <cstdio>
#include <cstring>

const int MAX=400005;
long long a[MAX],b[MAX];

void build(int l,int r,int flag) {
    b[flag]=0;
    if(l==r) {
        scanf("%lld",&a[flag]);
        return;
    }
    int m=(l+r)/2;
    build(l,m,flag<<1);
    build(m+1,r,flag<<1|1);
    a[flag]=a[flag<<1]+a[flag<<1|1];
}

void update(int x,int y,int z,int l,int r,int flag) {
    if(x<=l&&r<=y) {
        a[flag]+=(long long)z*(r-l+1);
        b[flag]+=z;
        return;
    }
    if(b[flag]) {
        b[flag<<1]+=b[flag];
        b[flag<<1|1]+=b[flag];
        int m=r-l+1;
        a[flag<<1]+=b[flag]*(m-(m>>1));
        a[flag<<1|1]+=b[flag]*(m>>1);
        b[flag]=0;
    }
    int m=(l+r)/2;
    if(x<=m)
        update(x,y,z,l,m,flag<<1);
    if(y>m)
        update(x,y,z,m+1,r,flag<<1|1);
    a[flag]=a[flag<<1]+a[flag<<1|1];
}

long long query(int x,int y,int l,int r,int flag) {
    if(x<=l&&r<=y)
        return a[flag];
    if(b[flag]) {
        b[flag<<1]+=b[flag];
        b[flag<<1|1]+=b[flag];
        int m=r-l+1;
        a[flag<<1]+=b[flag]*(m-(m>>1));
        a[flag<<1|1]+=b[flag]*(m>>1);
        b[flag]=0;
    }
    int m=(l+r)/2;
    long long ans=0;
    if(x<=m)
        ans+=query(x,y,l,m,flag<<1);
    if(y>m)
        ans+=query(x,y,m+1,r,flag<<1|1);
    return ans;
}

int main()
{
    int n,q;
    scanf("%d %d",&n,&q);
    memset(b,0,sizeof(b));
    build(1,n,1);
    while(q--) {
        char str[2];
        scanf("%s",str);
        int x,y,z;
        if(str[0]=='C') {
            scanf("%d %d %d",&x,&y,&z);
            update(x,y,z,1,n,1);
        }
        else {
            scanf("%d %d",&x,&y);
            printf("%lld\n",query(x,y,1,n,1));
        }
    }
    return 0;
}
