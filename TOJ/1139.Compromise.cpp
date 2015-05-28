/*
OJ: TOJ
ID: 3013216109
TASK: 1139.Compromise
LANG: C++
NOTE: LCS(DP)
*/
#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	char x[105][31],y[105][31],ans[105][31];
	int c[105][105],b[105][105];
	int i,j,k,m,n;
	while(cin >> x[1]) {
		for(i=2;;i++) {
			cin >> x[i];
			if(x[i][0]=='#')break;
		}
		for(j=1;;j++) {
			cin >> y[j];
			if(y[j][0]=='#')break;
		}
		m=i-1; n=j-1;
        for(i=0;i<=m;i++)
            c[i][0]=0;
        for(i=1;i<=n;i++)
            c[0][i]=0;
        for(i=1;i<=m;i++) {
            for(j=1;j<=n;j++) {
                if(!strcmp(x[i],y[j])) {
                    c[i][j]=c[i-1][j-1]+1;
                    b[i][j]=1;
                }
                else if(c[i-1][j]>=c[i][j-1]) {
                    c[i][j]=c[i-1][j];
                    b[i][j]=2;
                }
                else {
                    c[i][j]=c[i][j-1];
                    b[i][j]=3;
                }
            }
        }
        i=m;j=n;
        k=c[m][n]-1;
        while(i>0&&j>0&&k>=0) {
            if(b[i][j]==1) {
                strcpy(ans[k],x[i]);
                i--;j--;k--;
            }
            else if(b[i][j]==2) i--;
            else if(b[i][j]==3) j--;
            else break;
        }
        for(i=0;i<c[m][n]-1;i++)
            cout << ans[i] <<" ";
        cout <<ans[c[m][n]-1]<<endl;
	}
	return 0;
}
