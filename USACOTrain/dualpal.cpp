/*
ID: xiaojia5
LANG: C++
TASK: dualpal
*/
#include <cstdio>
#include <cstring>

char* func(int n,int base) {
    char tmp[1000];
    int i=0;
    while(n) {
        tmp[i]=(char)(n%base+48);
        n/=base;
        i++;
    }
    tmp[i]='\0';
    return tmp;
}

bool Reverse(char *s) {
    for(int i=0;i<strlen(s)/2;i++)
        if(s[i]!=s[strlen(s)-1-i])
            return false;
    return true;
}

int main()
{
    freopen("dualpal.in","r",stdin);
    freopen("dualpal.out","w",stdout);
	int n,s;
    scanf("%d %d",&n,&s);
    for(int j=s+1,x=0;x<n;j++) {
        for(int k=2,flag=0;k<=10;k++) {
            if(Reverse(func(j,k)))
                flag++;
            if(flag>1) {
                printf("%d\n",j);
                x++;
                break;
            }
        }
    }
    return 0;
}
