#include<iostream>
#include<conio.h>
#include"Tvector.h"
using namespace std;
int main(void)
{
	TVector<int> a(3);
	TVector<int> b(4);
	cout << a[4] << endl;
	cout << b << endl;
	cin >> a;
	cin >> b;
	cout << (a + b) << endl;
	_getch();
}