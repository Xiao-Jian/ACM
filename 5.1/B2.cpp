#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
using namespace std;

const int INF = 99999999;
const int N = 32768;
int a[N];
int n, l, u;
int head, tail;

struct Node
{
    int l, s;
} q[N];

int solve()
{
    int ans = INF;
    head = tail = 0;
    for ( int i = l; i <= n; i++ )
    {
        while ( head < tail && a[i - l] > q[tail - 1].s )
        {
            tail--;
        }
        q[tail].l = i - l, q[tail].s = a[i - l];
        tail++;
        while ( q[head].l + u < i ) head++;
        int tmp = a[i] - q[head].s;
        if ( tmp < ans ) ans = tmp;
    }
    return ans;
}

int main()
{
    while ( scanf("%d", &n), n )
    {
        scanf("%d%d", &l, &u);
        a[0] = 0;
        for ( int i = 1; i <= n; i++ )
        {
            scanf("%d", a + i);
            a[i] += a[i - 1];
        }
        printf("%d\n", solve());
    }
    return 0;
}
