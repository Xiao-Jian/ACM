/*
ID: xiaojia5
LANG: C++
TASK: namenum
*/
#include <cstdio>
#include <cstring>

char alpha[26]={'2','2','2','3','3','3','4','4','4','5','5','5','6','6','6','7','0','7','7','8','8','8','9','9','9','0'};
char a[13],b[13],c[13];
int i,j,k;

int main()
{
	freopen("namenum.in", "r", stdin);
	freopen("namenum.out", "w", stdout);
	freopen("dict.txt", "r", stderr);
	bool flag=false;
	gets(a);
	while(fscanf(stderr,"%s",b)!=EOF) {
		for(i=0;b[i];i++)
			c[i]=alpha[b[i]-'A'];
		c[i]='\0';
		if(!strcmp(a,c)) {
			flag=true;
			puts(b);
		}
	}
	if(!flag) puts("NONE");
}