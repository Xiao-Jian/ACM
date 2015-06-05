#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
#include <iostream>
#include <queue>
using namespace std;

const int MAX=10005;
queue<int> a;
set<int> s1;
set<int> s2;
char tmp[3][10]={"in","query","out"};

int main()
{
    int n,x,i,j,k,cnt=1;
    while(scanf("%d",&n)!=EOF) {
        int m=0;
        printf("Case #%d:\n",cnt++);
        while(n--) {
            char str[10];
            scanf("%s",str);
            for(i=0;i<3;i++) {
                if(!strcmp(str,tmp[i]))
                    break;
            }
            if(i==0) {
                scanf("%d",&x);
                a.push(x);
                if(s1.size()==s2.size())
                    s1.insert(x);
                else {
                    set<int>::iterator it;
                    it=s1.end();
                    it--;
                    if(x>*it)
                        s2.insert(x);
                    else {
                        s2.insert(*it);
                        s1.erase(*it);
                        s1.insert(x);
                    }
                }
            }
            else if(i==1) {
                if(s1.size()!=s2.size()) {
                    set<int>::iterator it;
                    it=s1.end();
                    it--;
                    printf("%d\n",*it);
                }
                else {
                    set<int>::iterator it;
                    it=s2.begin();
                    printf("%d\n",*it);
                }
            }
            else {
                set<int>::iterator it;
                if(s1.size()==s2.size()) {
                    it=s1.end();
                    it--;
                    if(a.front()<*it) {
                        s1.erase(a.front());
                        it=s2.begin();
                        s1.insert(*it);
                        s2.erase(*it);
                    }
                    else
                        s2.erase(a.front());
                }
                else {
                    it=s1.end();
                    it--;
                    if(a.front()>*it) {
                        s2.erase(a.front());
                        if(s1.size()>s2.size()+1) {
                            s2.insert(*it);
                            s1.erase(*it);
                        }
                    }
                    else {
                        s1.erase(a.front());
                        if(s1.size()<s2.size()) {
                            s1.insert(*s2.begin());
                            s2.erase(*s2.begin());
                        }
                    }
                }
                a.pop();
            }
        }
    }
    return 0;
}
