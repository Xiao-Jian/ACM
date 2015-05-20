#include <cstdio>
#include <cstring>

char str[105],a[105];
int n,q,i,j,k,cp=0,dp=1,tail,l,r;
int num[10];

int main()
{
    scanf("%d %d",&n,&q);
    scanf("%s",str);
    while(q--) {
        dp=1;
        scanf("%d %d",&l,&r);
        for(i=l-1,j=0;i<r;i++,j++)
            a[j]=str[i];
        tail=j;
        for(i=0;i<10;i++)
            num[i]=0;

        for(i=0;i<tail&&i>-1;) {
            if(a[i]=='<') {
                if(i>0&&(a[i-1]=='>'||a[i-1]=='<')) {
                    for(j=i;j<tail-1;j++)
                        a[j]=a[j+1];
                    tail=tail-1;
                }
                dp=0;i--;continue;
            }
            if(a[i]=='>'){
                if(i<tail-1&&(a[i+1]=='<'||a[i+1]=='>')) {
                    for(j=i;j<tail-1;j++)
                        a[j]=a[j+1];
                    tail=tail-1;
                    i--;
                }
                dp=1;i++;continue;
            }

            if(int(a[i])==48) {
                num[int(a[i])-48]++;
                for(j=i;j<tail-1;j++)
                    a[j]=a[j+1];
                tail=tail-1;
                if(!dp) i--;
                continue;
            }
            if(dp) {
                num[int(a[i])-48]++;
                a[i]=char(a[i]-1);
                i++;
            }
            else if(!dp) {
                num[int(a[i])-48]++;
                a[i]=char(a[i]-1);
                i--;
            }
        }
        for(i=0;i<9;i++)
            printf("%d ",num[i]);
        printf("%d\n",num[9]);
    }
    return 0;
}
