#include<iostream>
#include<cmath>
using namespace std;
int max_size, squer[11][2049][2049];
void write(int x_add, int y_add,int size)
{
    for (int y =1; y <= pow(2,size); y++)
    {
		for (int x = 1; x <= pow(2,size); x++)
		{
		    squer[size][x+x_add][y+y_add]=squer[size-1][x][y];
		}
    }
}
int main()
{
	squer[0][1][1] = 1;
	cin >> max_size;
    for(int size=1; size <= max_size; size++)
    {
        write(pow(2,size-1),0,size);
        write(0,pow(2,size-1),size);
        write(pow(2,size-1),pow(2,size-1),size);
    }
	for (int y =1; y <= pow(2,max_size); y++)
	{
		for (int x = 1; x <= pow(2,max_size); x++)
		{
			cout << squer[max_size][x][y]<<" ";
		}
		cout << endl;
	}
	return 0;
}