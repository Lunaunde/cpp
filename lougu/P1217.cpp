#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int a, b, q, flag_1, flag_2, length, j, back_1, back_2;
    cin >> a >> b;
    for (int num = a; num <= b; num++)
    {
        flag_1 = 1;
        flag_2 = 1;
        if (num % 2 != 0 && num % 3 != 0 && num % 5 != 0 && num % 7 != 0 && num != 1)
        {

            for (int i = 1; i <= 9; i++)
            {
                if (num / (pow(10, i)) >= 1)
                    length = i;
            }
            if (length % 2 == 0 || length < 2)
            {
                for (int i = 0; i <= length / 2; i++)
                {
                    j = length - i;
                    back_1 = (num / pow(10, i));
                    back_1 %= 10;
                    back_2 = (num / pow(10, j));
                    back_2 %= 10;
                    if (back_1 != back_2)
                    {
                        flag_1 = 0;
                        break;
                    }
                }
                if (flag_1)
                {
                    for (int p = 2; p <= sqrt(num); p++)
                    {
                        q = num / p;
                        if (p * q == num)
                            flag_2 = 0;
                    }
                    if (flag_2)
                    {
                        printf("%d\n", num);
                    }
                }
            }
        }
        else if (num < 10 && num != 1)
        {
            for (int p = 2; p <= sqrt(num); p++)
            {
                q = num / p;
                if (p * q == num)
                    flag_2 = 0;
            }
            if (flag_2)
            {
                printf("%d\n", num);
            }
        }
    }
    return 0;
}