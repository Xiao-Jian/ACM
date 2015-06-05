/*
OJ: TOJ
ID: 3013216109
TASK: 1438.Perfect Pth Powers
LANG: C++
NOTE: ´ò±í
*/
#include <cstdio>

int a[65537][33];

int main()
{
    int x,b,i,j,k;
    for(i=1;i<65537;i++) {
        b=1;
        for(j=1;j<33;j++) {
            b=b*i;
            a[i][j]=b;
        }
    }
    while(scanf("%d",&x),x) {
        bool flag=true;
        if(x<0) {
            x=-x;
            for(i=1;i<65536;i++) {
                for(j=33;j>0;j--) {
                    if(a[i][j]==x) {
                        if(j%2==1) {
                            printf("%d\n",j);
                            flag=false;
                            break;
                        }
                    }
                }
                if(!flag) break;
            }
            if(flag) printf("1\n");
        }
        else {
            for(i=1;i<65536;i++) {
                for(j=33;j>0;j--) {
                    if(a[i][j]==x) {
                        printf("%d\n",j);
                        flag=false;
                        break;
                    }
                }
                if(!flag) break;
            }
            if(flag) printf("1\n");
        }
    }
    return 0;
}
