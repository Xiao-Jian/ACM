#include <cstdio>
#include <iostream>
#include <map>
#include <cstring>
#include <vector>
using namespace std;

int n1,n2,n3,n4,i,j,k,m,sum;
map<string,int> equ;
string str;
struct node {
    int mon,num;
    vector<int> a;
}equip[105];

int cal(int x) {
    if(equip[x].num>0) {
        equip[x].num--;
        return 0;
    }
    else if(equip[x].a.empty()&&equip[x].mon<9999999)
        return equip[x].mon;
    int sum,i;
    for(sum=i=0;i<equip[x].a.size();i++)
        sum+=cal(equip[x].a[i]);
    return sum;
}

int main()
{
    while(scanf("%d",&n1)!=EOF) {
        sum=0;k=0;
        for(i=0;i<n1;i++) {
            //scanf("%s %d",str,&m);
            cin>>str>>m;
            equ[str]=i;
            equip[i].mon=m;
            equip[i].num=0;
            k=i;
        }
        scanf("%d",&n2);
        for(i=0;i<n2;i++) {
            cin>>str>>m;
            if(!equ.count(str)) {
                equ[str]=++k;
                equip[equ[str]].mon=9999999;
            }
            equip[equ[str]].num=m;
        }
        scanf("%d",&n3);
        for(i=0;i<n3;i++) {
            j=0;
            int coun[105];
            while(cin>>str) {
                if(str[0]=='+')
                    continue;
                if(str[0]=='=') {
                    cin>>str;
                    if(!equ.count(str)) {
                        equ[str]=++k;
                        equip[equ[str]].mon=9999999;
                        equip[equ[str]].num=0;
                    }
                    break;
                }
                coun[j++]=equ[str];
                //printf("%d\n",coun[j-1]);
            }
            for(int l=0;l<j;l++)
                equip[equ[str]].a.push_back(coun[l]);
        }
        scanf("%d",&n4);
        for(i=0;i<n4;i++) {
            cin>>str>>m;
            for(j=0;j<m;j++)
                sum+=cal(equ[str]);
        }
        printf("%d\n",sum);
        memset(equip,0,sizeof(equip));
        equ.clear();
    }
}
