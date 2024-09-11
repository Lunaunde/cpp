#include<bits/stdc++.h>
using namespace std;
int a[5000000];
int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++)
    {
        scanf("%d%d",&a[i]);
    }
    sort(a,a+n-1);
    cout<<a[k];
    return 0;
}