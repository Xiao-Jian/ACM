/*
OJ: TOJ
ID: 3013216109
TASK: 3515.Middle number
LANG: C++
NOTE: sort�Ͳ������򣬿ɻ��öѼ�Сʱ�临�Ӷ�
*/
#include <stdio.h>
#include <algorithm>

int a[1000000];

int main()
{
    int t,n,m,i,j,k;
    char str[4];
    scanf("%d",&t);
    while(t--) {
        scanf("%d",&n);
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);
        std::sort(a,a+n);

        scanf("%d",&m);
        while(m--) {
            scanf("%s",str);
            if(str[0]=='a') {
                int x;
                scanf("%d",&x);
                n++;
                for(i=0;i<n;i++) {
                    if(a[i]>x) {
                        for(j=n;j>i;j--)
                            a[j]=a[j-1];
                        a[i]=x;
                        break;
                    }
                }
            }
            else
                printf("%d\n",a[(n-1)/2]);
        }
    }
}
