 /*
OJ: POJ
ID: 3013216109
TASK: 1256.Anagram
LANG: C++
NOTE: NEXT_PERMUTATION
*/
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

int n;
char str[13];

bool cmp(char a,char b) {
    if(tolower(a)==tolower(b))
        return a<b;
    else
        return tolower(a)<tolower(b);
}


int main()
{
    scanf("%d",&n);
    getchar();
    while(n--) {
        gets(str);
        sort(str,str+strlen(str),cmp);
        do {
            puts(str);
        } while(next_permutation(str,str+strlen(str),cmp));
    }
    return 0;
}
