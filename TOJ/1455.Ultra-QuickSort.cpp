/*
OJ: TOJ
ID: 3013216109
TASK: 1455.Ultra-QuickSort
LANG: C++
NOTE: MergeSort
*/
#include <cstdio>

long long sum;

void Merge(int src[],int tmp[],int start,int mid,int end) {
    int i=start,j=mid+1,k=start;
    while(i!=mid+1&&j!=end+1) {
        if(src[i]<=src[j])
            tmp[k++]=src[i++];
        else {
            tmp[k++]=src[j++];
            sum+=(mid-i+1);
        }
    }
    while(i!=mid+1)
        tmp[k++]=src[i++];
    while(j!=end+1)
        tmp[k++]=src[j++];
    for(i=start;i<=end;i++)
        src[i]=tmp[i];
}

void MergeSort(int src[],int tmp[],int start,int end) {
    int mid;
    if(start<end) {
        mid=(end+start)/2;
        MergeSort(src,tmp,start,mid);
        MergeSort(src,tmp,mid+1,end);
        Merge(src,tmp,start,mid,end);
    }
}

int main()
{
    int n;
    while(scanf("%d", &n),n) {
        const int N = n;
        int a[N],tmp[N];
        sum=0;
        for(int l=0;l<n;l++)
            scanf("%d",&a[l]);
        MergeSort(a,tmp,0,n-1);
        printf("%lld\n",sum);
    }
}
