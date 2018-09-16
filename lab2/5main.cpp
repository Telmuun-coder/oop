#include <iostream>;
using namespace std;

/*
	Өгөгдсөн 2 тооны утгуудыг солино

	Params:
	int a - утгыг нь солих тоо
	int b - утгыг нь солих тоо

	Return:
	void
*/
void swap_nums(int *a, int *b)
{
	// temp-т а-н утгыг хадгална
	int temp = *a;
	// а-т b-н утгыг оноож өгнө
	*a = *b;
	// b-m хадгалж авсан а-н утгыг оноож өгнө
	*b = temp;
}

int main()
{
	//  утгыг нь солих 2 бүхэл тоо зарлах
	int a = 10;
	int b = 96;

	// функцээ дуудан ажиллуулах
	swap_nums(&a, &b);

	// хоёр тоогоо хэвлэнэ
	cout << "a: " << a << endl;
	cout << "b: " << b << endl;
}