#include <iostream>
using namespace std;

/*
	Өгөгдсөн гурван тооны хамгийн ихийг нь олно

	Params:
	int a - тоо
	int b - тоо
	int c - тоо

	Return:
	Гурван тооны хамгийн их утга
*/
int findMax(int a, int b, int c)
{
	// а тоо хамгийн их
	if (a >= b && a >= c)
		return a;
	// b тоо хамгийн их
	else if (b >= a && b >= c)
		return b;
	// c тоо хамгийн их
	else
		return c;
}

int main()
{
	int a, b, c;
	// Гурван тоог гараас оруулна
	cin >> a >> b >> c;

	// Олсон тоогоо хэвлэнэ
	cout << findMax(a, b, c) << endl;

	return 0;
}
