#include <iostream>
using namespace std;
int main()
{
    int n, a[10000], b;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if (a[i] <= a[j])
            {
                b = a[i];
                for (int k = i; k > j; k--)
                {
                    a[k] = a[k - 1];
                }
                a[j] = b;
                break;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}