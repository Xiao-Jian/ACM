#include <stdio.h>

int main()
{
    double c,sum[300];
    sum[1]=0;
    for(int i=2;i<300;i++)
        sum[i]=sum[i-1]+1.0/i;

    while(scanf("%lf",&c),c) {
        for(int i=2;i<300;i++)
            if(sum[i]>=c) {
                printf("%d card(s)\n",i-1);
                break;
            }
    }
    return 0;
}
