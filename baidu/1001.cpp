#include <cstdio>
#include <algorithm>

int main()
{
    int t,n,i,j,cnt=1;
    long long m,k,dist;
    long long a[10005];
    scanf("%d",&t);
    while(t--) {
        scanf("%d %I64d %I64d",&n,&m,&k);
        for(i=0;i<n;i++)
            scanf("%I64d",&a[i]);
        std::sort(a,a+n);
        for(i=0;i<n;i++)
            if(m<a[i]) break;
        bool flag=true;
        if(i>0)
            m=a[i-1];
        if(i==0)
            flag=false;
        else {
            while(i<n) {
                dist=a[i]-m;
                if(dist>k) {
                    flag=false;
                    break;
                }
                m += dist;
                i++;
                if(k>0)
                    k--;
            }
        }
        printf("Case #%d:\n",cnt++);
        if(flag) printf("why am I so diao?\n");
        else printf("madan!\n");
    }
}
