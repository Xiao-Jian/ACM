#include <cstdio>

int main()
{
    int t,a[4],b[4],k=1;
    double tmp[4]={1000,1500,2000,2500};
    scanf("%d",&t);
    while(t--) {
        for(int i=0;i<4;i++)
            scanf("%d %d",&a[i],&b[i]);
        double sum=0;
        for(int i=0;i<4;i++) {
            double ans=tmp[i];
            ans=((250.0-a[i])/250.0)*ans-50.0*b[i];
            if(ans<0.4*tmp[i])
                ans=0.4*tmp[i];
            sum+=ans;
        }
        printf("Case #%d: %.0lf\n",k++,sum);
    }
}
