/*
ID: xiaojia5
LANG: C++
TASK: milk2
*/
#include <fstream>
#include <cmath>
#include <algorithm>
using namespace std;

ifstream fin("milk2.in");
ofstream fout("milk2.out");

typedef struct {
    int s,f;
}Node,Time[5005];

bool cmp(Node t1,Node t2) {
	return t1.s<t2.s;
}

int main()
{
    int n,i,j,k,l,m,tmps,tmpf;
    Time t;
    fin >> n;
    for(i=0;i<n;i++)
    	fin >> t[i].s >> t[i].f;
    sort(t,t+n,cmp);
    tmps=t[0].s; tmpf=t[0].f;
    l=tmpf-tmps; m=0;
    for(i=1;i<n;i++) {
    	if(t[i].s<=tmpf)
    		tmpf=max(tmpf,t[i].f);
    	else {
    		l=max(tmpf-tmps,l);
    		m=max(t[i].s-tmpf,m);
    		tmpf=t[i].f;
    		tmps=t[i].s;
    	}
    }
    fout << l <<" "<< m << endl;
    return 0;
}
