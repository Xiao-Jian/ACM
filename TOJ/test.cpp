#include<iostream>
#include<cstring>
#include<cmath>
#include<cstdio>
#include<algorithm>

using namespace std;

struct node
{
    int p,l,r;
}data[100100];
int p;
int value[100100];
int counts[100100];
int dp[100050][60];
int n,m;

void init()
{
	for(int i=1;i<=p;i++)
        dp[i][0]=counts[i];
	int k=floor(log((double)(n+1))/log(2.0));
	int m;
	for(int j=1;j<=k;j++)
		for(int i=1;i+(1<<j)-1<=p;i++)
		{
			m=i+(1<<(j-1));
			dp[i][j]=max(dp[i][j-1],dp[m][j-1]);
		}
}

int rmq(int i,int j)
{
	int m=floor((log((double)(j-i+1))/log(2.0)));
	int x=max(dp[i][m],dp[j-(1<<m)+1][m]);
	return x;
}

int main()
{
    while(~scanf("%d",&n)&&n)
    {
        scanf("%d",&m);
        int l=0,r=0,v=0,tmp;
        p=1;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&tmp);
            if(tmp!=v && l!=0)
            {
                counts[p]=r-l+1;
                value[p]=v;
                for(int j=l;j<=r;j++)
                    data[j].l=l,data[j].r=r,data[j].p=p;
                p++;
                r++;
                l=r;
                v=tmp;
            }
            else
                r++;
            if(l==0)
            {
                l=1;
                v=tmp;
            }
        }
        counts[p]=r-l+1;
        value[p]=v;
        for(int j=l;j<=r;j++)
            data[j].l=l,data[j].r=r,data[j].p=p;
        init();
        for(int i=1;i<=m;i++)
        {
            scanf("%d%d",&l,&r);
            int L,R;
            if(data[l].p==data[r].p)
                printf("%d\n",r-l+1);
            else
            {
                L=data[l].p+1;
                R=data[r].p-1;
                int ans=data[l].r-l+1;
                ans=max(ans,r-data[r].l+1);
                if(L<=R)ans=max(ans,rmq(L,R));
                printf("%d\n",ans);
            }
        }
    }
	return 0;
}
