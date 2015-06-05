 /*
OJ: POJ
ID: 3013216109
TASK: 1256.Anagram
LANG: C++
NOTE: DFS
*/
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

int n;
char str[13],ans[13];
int visited[13];

bool cmp(char a,char b) {
    if(tolower(a)==tolower(b))
        return a<b;
    else
        return tolower(a)<tolower(b);
}

void dfs(int t) {
    if(t==strlen(str)) {
        for(int i=0;i<t;i++)
            printf("%c",ans[i]);
        printf("\n");
        return;
    }
    for(int i=0;i<strlen(str);i++) {
        if(!visited[i]) {
            ans[t]=str[i];
            visited[i]=1;
            dfs(t+1);
            visited[i]=0;
            while(i+1<strlen(str)&&str[i]==str[i+1]) i++;
        }
    }
}

int main()
{
    scanf("%d",&n);
    getchar();
    while(n--) {
        memset(visited,0,sizeof(visited));
        gets(str);
        sort(str,str+strlen(str),cmp);
        dfs(0);
    }
    return 0;
}
