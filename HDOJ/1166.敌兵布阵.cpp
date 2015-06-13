/*
OJ: HDOJ
ID: forever
TASK: 1166.敌兵布阵
LANG: C++
NOTE: 线段树
*/
#include <cstdio>

const int MAX=200005;
int a[MAX];
char str[10];

void build(int l,int r,int flag) {
    if(l==r) {
        scanf("%d",&a[flag]);
        return;
    }
    int m=(l+r)/2;
    build(l,m,flag*2);
    build(m+1,r,flag*2+1);
    a[flag]=a[flag*2]+a[flag*2+1];
}

void update(int x,int y,int l,int r,int flag) {
    if(l==r) {
        a[flag]+=y;
        return;
    }
    int m=(l+r)/2;
    if(x<=m)
        update(x,y,l,m,flag*2);
    else
        update(x,y,m+1,r,flag*2+1);
    a[flag]=a[flag*2]+a[flag*2+1];
}

int query(int x,int y,int l,int r,int flag) {
    if(x<=l&&r<=y)
        return a[flag];
    int m=(l+r)/2;
    int ans=0;
    if(x<=m)
        ans+=query(x,y,l,m,flag*2);
    if(y>m)
        ans+=query(x,y,m+1,r,flag*2+1);
    return ans;
}

int main()
{
    int t,n,x,y,k=1;
    scanf("%d",&t);
    while(t--) {
        scanf("%d",&n);
        build(1,n,1);
        printf("Case %d:\n",k++);
        while(scanf("%s",str)&&str[0]!='E') {
            scanf("%d %d",&x,&y);
            if(str[0]=='Q')
                printf("%d\n",query(x,y,1,n,1));
            else if(str[0]=='A')
                update(x,y,1,n,1);
            else if(str[0]=='S')
                update(x,-y,1,n,1);
        }
    }
    return 0;
}
