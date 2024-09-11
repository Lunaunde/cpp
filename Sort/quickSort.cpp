#include <iostream>
using namespace std;
int n, a[10000];
void quickSort(int start, int end)
{
    int counter=0,b;
    for(int i=start+1;i<=end;i++)
    {
        if(a[start+counter]>a[i])
        {
            b=a[i];
            for(int j=i;j>start+counter;j--)
            {
                a[j]=a[j-1];   
            }
            a[start+counter]=b;
            counter++;
        }
    }
    if(start+counter<end-1)
        quickSort(start+counter+1,end);
    if(start+counter>start+1)
        quickSort(start,start+counter-1);
}
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    quickSort(0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}