/*
ID: xiaojia5
LANG: C++
TASK: gift1
*/
#include <fstream>
#include <string>
#include <cstring>
using namespace std;
 
ifstream fin("gift1.in");
ofstream fout("gift1.out");
 
int main()
{
	static int ans[10];
	int np,i,j,p,mon,ng;
	string a[10],give,rec;
	fin>>np;
	for (i=0;i<np;i++)
		fin>>a[i];
	for (i=0;i<np;i++) {
		fin >> give >> mon >> ng;
		for (p=0;give!=a[p];p++);
			ans[p]-=ng==0?0:mon-mon%ng;
		for (j=0;j<ng;j++) {
			fin >> rec;
			for (p=0;rec!=a[p];p++);
			ans[p]+=mon/ng;
		}
	}
	for (i=0;i<np;i++)
		fout<<a[i]<<' '<<ans[i]<<endl;
	return 0;
}