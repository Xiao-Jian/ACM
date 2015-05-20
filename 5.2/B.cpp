#include <cstdio>
#include <cstring>
#include <map>
#include <vector>
using namespace std;

map<char*,int> equ1,equ2;   //¹ØÁªº¯Êý
int n1,n2,n3,n4,i,j,k,m,sum;
char str[105];
vector<char*>equ3[105];
vector<char*>ch;

int find(char* str,vector<char*> ch) {
    for(int i=0;i<ch.size();i++)
        if(!strcmp(str,ch[i]))
            return i;
    return -1;
}

int cal(char *str) {
    if(!equ2.count(str)) {
        equ2[str]--;
        return 0;
    }
    else if(find(str,ch)==-1)
        return equ1[str];
    for(sum=i=0;i<equ3[find(str,ch)].size();i++)
        sum+=cal(equ3[find(str,ch)][i]);
    return sum;
}

int main()
{
    while(scanf("%d",&n1)!=EOF) {
        sum=0;
        for(i=0;i<n1;i++) {
            scanf("%s %d",str,&m);
            equ1[str]=m;
        }
        scanf("%d",&n2);
        for(i=0;i<n2;i++) {
            scanf("%s %d",str,&m);
            equ2[str]=m;
        }
        scanf("%d",&n3);
        for(i=0;i<n3;i++) {
            while(scanf("%s",str)) {
                if(!strcmp(str,"+")) continue;
                if(!strcmp(str,"=")) {
                    scanf("%s",str);
                    ch.push_back(str);
                    break;
                }
                equ3[i].push_back(str);
            }
        }
        scanf("%d",&n4);
        for(i=0;i<n4;i++) {
            scanf("%s %d",str,&m);
            for(j=0;j<m;j++)
                sum+=cal(str);
        }
        printf("%d\n",sum);
        ch.clear();
    }
    return 0;
}
