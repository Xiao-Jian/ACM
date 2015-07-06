#include <stdio.h>

int main()
{
    double c=0,mon[12];
    for(int i=0;i<12;i++) {
        scanf("%lf",&mon[i]);
        c+=mon[i];
    }
    printf("$%.2lf\n",c/12);
    return 0;
}
