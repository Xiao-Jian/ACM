/*
OJ: POJ
ID: 3013216109
TASK: 3368.Frequent values
LANG: C++
NOTE: Ïß¶ÎÊ÷
*/
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

const int MAX=100005;
int a[MAX],dp[MAX][18];
int cnt[MAX],tree[MAX*4],f;

struct trip {
    int s,e;
    int num;
}wap[MAX];

void build(int l,int r,int flag) {
    if(l==r) {
        tree[flag]=cnt[f++];
        return;
    }
    int m=(l+r)/2;
    build(l,m,flag*2);
    build(m+1,r,flag*2+1);
    tree[flag]=max(tree[flag<<1],tree[flag<<1|1]);
}

int query(int x,int y,int l,int r,int flag) {
    if(x<=l&&r<=y)
        return tree[flag];
    int m=(l+r)/2;
    int ans=0;
    if(x<=m)
        ans=max(ans,query(x,y,l,m,flag<<1));
    if(y>m)
        ans=max(ans,query(x,y,m+1,r,flag<<1|1));
    return ans;
}

int main()
{
    int n,q,x,y,i,j;
    while(scanf("%d",&n),n) {
        scanf("%d",&q);
        memset(wap,0,sizeof(wap));
        memset(cnt,0,sizeof(cnt));
        int k=1;
        scanf("%d",&a[1]);
        wap[k].s=1;
        for(i=2;i<=n;i++) {
            scanf("%d",&a[i]);
            if(a[i]==a[i-1]) {
                cnt[k]++;
                wap[i].s=wap[i-1].s;
            }
            else {
                cnt[k]++;
                wap[i].e=i-1;
                k++;
                wap[i].s=i;
            }
        }
        wap[n+1].e=n;
        cnt[k]++;
        for(i=1,j=1;i<=n;) {
            for(int f=i;f<i+cnt[j];f++)
                wap[f].num=j;
            for(int f=i+1;f<i+cnt[j];f++)
                wap[f].s=wap[f-1].s;
            for(int f=i+cnt[j]-1;f>=i;f--)
                wap[f].e=wap[f+1].e;
            i+=cnt[j];j++;
        }
        f=1;
        build(1,k,1);
        while(q--) {
            scanf("%d %d",&x,&y);
            int i,st,rt,ans;
            st=wap[x].num;
            rt=wap[y].num;
            if((rt-st)==0)
                ans=y-x+1;
            else if((rt-st)==1)
                ans=max(wap[x].e-x+1,y-wap[y].s+1);
            else {
                ans=query(st+1,rt-1,1,k,1);
                ans=max(wap[x].e-x+1,ans);
                ans=max(ans,y-wap[y].s+1);
            }
            printf("%d\n",ans);
        }
    }
    return 0;
}
