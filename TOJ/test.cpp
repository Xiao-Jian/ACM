#include <stdio.h>
#include <cmath>

int main(){
    int p;
    int n,i;
    int t;
    while(scanf("%d",&n) && n){
        if(n>0){
            for(i=31;i>=1;i--){
                t=(int)(pow(1.0*n,1.0/i)+0.1);
                p=(int)(pow(1.0*t,1.0*i)+0.1);
                if(n==p){
                    printf("%d\n",i);
                    break;
                }
            }
        }
        else{
            n=-n;
            for(i=31;i>=1;i-=2){
                t=(int)(pow(1.0*n,1.0/i)+0.1);
                p=(int)(pow(1.0*t,1.0*i)+0.1);
                if(n==p){
                    printf("%d\n",i);
                    break;
                }
            }
        }
    }
    return 0;
}
