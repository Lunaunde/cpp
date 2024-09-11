#include <iostream>
using namespace std;
int main()
{
	int a,b;
	cin>>a>>b;
	a=a+b;
	b=a-2*b;//b=a+b-2b=a-b
	a=(a-b)/2;//a=b
	b=a+b;
	cout<<a<<" "<<b;
	return 0;
} 