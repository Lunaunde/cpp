#include <iostream>
using namespace std;
int a[100000];
void half_find(int start,int end, int i)
{
    int b,hplace=(start + end)/2;
    if (hplace == 0 && a[hplace] > a[i])
    {
        b = a[i];
        for (int k = i; k > 0; k--)
        {
            a[k] = a[k - 1];
        }
        a[0] = b;
    }
    else
    {
        if (a[hplace] <= a[i] && a[hplace + 1] > a[i])
        {
            b = a[i];
            for (int k = i; k > hplace + 1; k--)
            {
                a[k] = a[k - 1];
            }
            a[hplace + 1] = b;
        }
        else
        {
            if (a[hplace] <= a[i])
                half_find(hplace+1,end,i);
            if (a[hplace + 1] >= a[i])
                half_find(start,hplace,i);
        }
    }
}
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i < n; i++)
    {
        half_find(0,i-1, i);
    }
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}