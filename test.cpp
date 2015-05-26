#include <cstdio>
#include <cstring>

int t,l,n,m,i,j,k;
char str[1005];
char tmp[7]={'g','o','d','m','r','n','i'};

int main()
{
    scanf("%d",&t);
    getchar();
    n=1;
    while(t--) {
        int num[7]={0};
        gets(str);
        //puts(str);
        l=strlen(str);
        for(i=0;i<l;i++) {
            for(j=0;j<7;j++) {
                if(str[i]==tmp[j])
                    num[j]++;
            }
        }
        num[0]=num[0]-1;
        num[1]=num[1]/3;
        num[5]=num[5]/2;
        m=10000;
        for(i=0;i<7;i++)
            if(m>num[i])
                m=num[i];
            //printf("%d\n",num[i]);
        printf("Case #%d: %d\n",n++,m);
    }
}
