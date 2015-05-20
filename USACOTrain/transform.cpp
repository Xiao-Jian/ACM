/*
ID: xiaojia5
LANG: C++
TASK: transform
*/
#include <cstdio>
#include <cstring>
using namespace std;

int n,i,j,k;
char before[11][11],after[11][11],tmp[11][11];
bool flag=false;

bool cmp(char a[][11],char b[][11],int m) {
    for(i=0;i<m;i++)
		if(memcmp(a[i],b[i],m)) return false;
	return true;
}

void tran(char a[][11],char b[][11],int n,int k) {
    for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			switch (k) {
			case 1: b[i][j]=a[n-j-1][i]; break;
			case 2: b[i][j]=a[n-i-1][n-j-1]; break;
			case 3: b[i][j]=a[j][n-i-1]; break;
			case 4: b[i][j]=a[i][n-j-1];
			}
}

int solve() {
    for(k=1;k<=4;k++) {
        tran(before,tmp,n,k);
        if(cmp(tmp,after,n))
            return k;
    }
    for(k=1;k<=3;k++) {
        tran(tmp,before,n,k);
        if(cmp(before,after,n))
            return 5;
    }
    if(flag) return 7;
    else return 6;
}

int main()
{
    freopen("transform.in","r",stdin);
	freopen("transform.out","w",stdout);
    scanf("%d%*c",&n);
    for(i=0;i<n;i++)
        gets(before[i]);
    for(i=0;i<n;i++) {
        gets(after[i]);
        if(memcmp(before[i],after[i],n))
            flag=true;
    }
    printf("%d\n",solve());
    return 0;
}
