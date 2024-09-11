#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int T, n[10000], m[10000], k[10000], S_flag = 0, left;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        cin >> n[i] >> m[i] >> k[i];
    }
    for (int i = 0; i < T; i++)
    {
        S_flag = 0;
        if (n[i] > m[i])
        {
            for (int j = 0; j < n[i]; j++)
            {
                S_flag++;
                if (j == k[i] - 1)
                    break;
            }
        }
        else
        {
            for (int j = 0; j < m[i]; j++)
            {
                S_flag++;
                if (j == k[i] - 1)
                    break;
            }
        }
        left = k[i] - S_flag;
        for (int j = 0; j < n[i]; j++)
        {
            for (int l = 0; l < m[i]; l++)
            {
                if (j == l && j + 1 <= S_flag)
                    cout << 'S';
                else if (left >= 0)
                {
                    left--;
                    cout << 'S';
                }
                else
                    cout << '.';
            }
            cout << endl;
        }
    }
    return 0;
}