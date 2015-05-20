/*
ID: xiaojia5
TASK: palsquare
LANG: C++
*/
#include <cstdio>

int a[20],b[20],base,m,n,i,j,k;
char c[20]={'0','1','2','3','4','5','6','7','8','9',
            'A','B','C','D','E','F','G','H','I','J'};

void tran(int l) {
    int tmp=l;
    m=0;n=0;
    while(tmp) {
        a[m]=tmp%base;
        tmp/=base;
        m++;
    }
    tmp=l*l;
    while(tmp) {
        b[n]=tmp%base;
        tmp/=base;
        n++;
    }
}

bool isReverse() {
    for(i=0;i<n/2;i++) {
        if(b[i]!=b[n-1-i])
            return false;
    }
    return true;
}

int main()
{
    freopen("palsquare.in","r",stdin);
	freopen("palsquare.out","w",stdout);
    scanf("%d",&base);
    for(k=1;k<=300;k++) {
        tran(k);
        if(isReverse()) {
            for(i=0;i<m;i++)
                printf("%c",c[a[m-i-1]]);
            printf(" ");
            for(j=0;j<n;j++)
                printf("%c",c[b[j]]);
            printf("\n");
        }
    }

}
