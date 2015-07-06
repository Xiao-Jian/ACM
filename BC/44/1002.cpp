#include <cstdio>
#include <cstring>

const int MAX_N=10001*5;
int a[MAX_N],b[MAX_N];

int lowbit(int x) {
    if(x==0) return 0;
    bool k;
    for(int i=0;i<=32;i++) {
		k=(1<<i)&x;
		if(k==1)
            return (1<<i);
	}
}

int main()
{
    int t,n,k=1;
    scanf("%d",&t);
    while(t--) {
        scanf("%d",&n);
        memset(b,0,sizeof(b));
        for(int i=0;i<n;i++)
            scanf("%d",&a[i]);
        int m=0,sum=0;
        for(int i=0;i<n;i++)
            for(int j=i+1;j<n;j++) {
                int ans=a[i]^a[j];
                sum+=lowbit(ans);
                if(sum>=998244353)
                    sum%=998244353;
            }
        printf("Case #%d: %d\n",k++,(sum*2)%998244353);
    }
}
