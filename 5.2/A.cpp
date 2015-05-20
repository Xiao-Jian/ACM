#include <cstdio>

double cal(double x) {
    return 8*x*x*x*x+7*x*x*x+2*x*x+3*x+6;
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--) {
        double y;
        scanf("%lf",&y);
        if(cal(0)>y+1e-10||cal(100)<y+1e-10) {
            printf("No solution!\n");
            continue;
        }

        double head=0,tail=100,mid;
        while(head+1e-10<=tail) {
            mid=(head+tail)/2;
            if(cal(mid)<y)
                head=mid+1e-10;
            else
                tail=mid-1e-10;
        }
        printf("%.4lf\n",head);
    }
}
