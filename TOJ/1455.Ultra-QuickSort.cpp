/*
OJ: TOJ
ID: 3013216109
TASK: 1455.Ultra-QuickSort
LANG: C++
NOTE:
*/
#include <cstdio>

int main()
{
    int n,i,j,k;
    while(scanf("%d", &n),n) {
        const int N = n;
        int a[N],sum=0;
        for(i=0;i<n;i++) {
            scanf("%d",&a[i]);
            for(j=i-1;j>=0;j--)
                if(a[i]>=a[j]) break;
            int tmp=a[i];
            for(k=i;k>j+1;k--)
                a[k]=a[k-1];
            a[j+1]=tmp;
            sum+=(i-j-1);
        }
        printf("%d\n",sum);
    }
}
