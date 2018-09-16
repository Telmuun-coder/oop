#include <iostream>
using namespace std;

/*
    А хүснэгтийн тэгш тоонуудыг тоолно
    
    Params
    int a[] - А хүснэгт, 
    int n - а хүснэгтийн хэмжээ
    
    Return
    int - тэгш тоонууды тоо
*/
int count_even(int a[], int n)
{
	// тэгш тооны тоолуурыг зарлна
	int j = 0;

	// i дахь элемент тэгш үед тоолуурыг 1-ээр нэмнэ
	for (int i = 0; i < n; i++)
	{
		if (a[i] % 2 == 0)
		{
			j++;
		}
	}

	return j;
}

int main()
{
	int n;
	// хүснэгтийн хэмжээг оруулсан
	cin >> n;

	int a[n];
	// n элементтэй хүснэгт үүсгэж утгыг нь оруулсан
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	// тэгш тоо тоолох функцийг дуудаж утгыг хэвлэнэ
	cout << count_even(a, n) << endl;

	return 0;
}