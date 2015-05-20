#include <stdio.h>
#include <cstring>

int main()
{
    int i,j,k;
    int a[7]={4};
    char str[100],ans;
    while(scanf("%s",str)!=EOF) {
        int n=strlen(str),sum=0;
        for(i=0;i<n;i++) {
            sum+=(str[i]-'0');
            a[str[i]-'0']--;
        }
        if(sum==31)
            ans=(n%2)?'A':'B';

        sum=31-sum;


        printf("%s %c\n",str,ans);
    }
}
