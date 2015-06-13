#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

const int N=4000005;
int n,cnt;
ll ans,t;

struct Trie {
	int a[2];
	ll num;
}f[N];

void insert(ll x,int u,int num) {
	bool k;
	for(int i=num;i>=0;i--) {
		k=(1<<i)&x;
		if(f[u].a[k]==-1)
			f[u].a[k]=++cnt;
		u=f[u].a[k];
	}
	f[u].num=x;
}

void query(ll x, int u, int num) {
	bool k;
	for(int i=num;i>=0;i--) {
		k=(1<<i)&x;
		if(f[u].a[!k]!=-1)
			u=f[u].a[!k];
		else
			u=f[u].a[k];
	}
	ans=max(ans,f[u].num^x);
}

int main()
{
	scanf("%d",&n);
    memset(f,-1,sizeof(f));
    cnt=0;
    scanf("%lld",&t);
    ans=t;
    printf("%lld\n",ans);
    n--;
    while(n--) {
        scanf("%d",&t);
        if(ans<t)
            ans=t;
        insert(t,0,63);
        query(t,0,63);
        printf("%lld\n",ans);
    }
	return 0;
}
