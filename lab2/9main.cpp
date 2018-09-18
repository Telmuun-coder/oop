#include <iostream>
using namespace std;

int main()
{
	for (int i = 0; i < 2; i++)
	{
		// а гэсэн бүхэл тоон хаяган хувьсагч зарлаж түүнд new int-с нөөцөлсөн хаягийг оноож өгнө
		int *a = new int;

		// p_a-т а-н хаягийг өгнө
		p_a = a;

		// а-н хаяган дээр байгаа утгыг i болгоно
		*a = i;

		// а-н хаяган дээр байгаа утгыг хэвлэнэ
		cout << "*a = " << *a << endl;
	}
	return 0;
}