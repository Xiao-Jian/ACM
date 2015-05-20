/*
ID: xiaojia5
LANG: C++
TASK: beads
*/
#include <fstream>
using namespace std;

ifstream fin("beads.in");
ofstream fout("beads.out");

int main()
{
    int n,i,j,k,m=0,a=0,b=0,w=0;
    fin >> n;
    char str[705],c=0;
    fin >> str;
    for(i=0;i<n;i++)
        str[i+n]=str[i];
    for (i=0;i<n<<1;i++)
		if (str[i]=='w') b++,w++;
		else if (str[i]==c) b++,w=0;
		else
		{
			if (a+b>m) m=a+b;
			a=b-w;b=w+1;w=0;c=str[i];
		}
	if (a+b>m) m=a+b;
	fout << (m>n?n:m) << endl;
    return 0;
}
