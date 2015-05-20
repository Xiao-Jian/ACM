/*
ID: xiaojia5
LANG: C++
TASK: friday
*/
#include <fstream>
using namespace std;

ifstream fin("friday.in");
ofstream fout("friday.out");

int isLeap(int year) {
    return ((year % 4 == 0 && year % 100 != 0) ||year%400==0);
}

int main()
{
    int n,i,j,x=3;
    fin >> n;
    int a[7]={0},days[12]={31,31,28,31,30,31,30,31,31,30,31,30};
    for(i=1900;i<1900+n;++i){
		if(isLeap(i)) days[2]=29;
		for(j=0;j<12;++j){
			x=(x+days[j])%7;
			a[x]++;
		}
		days[2]=28;
	}

	for(i=0;i<6;++i)
        fout << a[(i+6)%7] <<' ';
	fout << a[5] << endl;
    return 0;
}
