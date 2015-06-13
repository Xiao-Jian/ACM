/*
OJ: TOJ
ID: 3013216109
TASK: 4130.HDFS Simple Version
LANG: C++
NOTE:
*/
#include <cstdio>
#include <cstring>

const int MAX=5000004/4;

struct node {
    unsigned char bit_0 : 2;
    unsigned char bit_1 : 2;
    unsigned char bit_2 : 2;
    unsigned char bit_3 : 2;
}num[MAX];

int main()
{
    int t,n,x,k,l;
    scanf("%d",&t);
    while(t--) {
        memset(num,0,sizeof(num));
        scanf("%d",&n);
        for(int i=0;i<2*(n-1);i++) {
            scanf("%d",&x);
            k=x/4; l=x%4;
            switch(l) {
                case 0:num[k].bit_0++;break;
                case 1:num[k].bit_1++;break;
                case 2:num[k].bit_2++;break;
                case 3:num[k].bit_3++;break;
            }
        }
        k=0; l=0;
        int cnt=0;
        for(int i=1;i<=n;i++) {
            k=i/4; l=i%4;
            int bit;
            switch(l) {
                case 0:bit=num[k].bit_0;break;
                case 1:bit=num[k].bit_1;break;
                case 2:bit=num[k].bit_2;break;
                case 3:bit=num[k].bit_3;break;
            }
            if(bit==0) {
                printf("%d %d\n",i,i);
                break;
            }
            else if(bit==1) {
                cnt++;
                if(cnt==1)
                    printf("%d ",i);
                else if(cnt==2) {
                    printf("%d\n",i);
                    break;
                }
            }
        }
    }
    return 0;
}
