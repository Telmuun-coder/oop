#include <iostream>;
using namespace std;

/*
	Өгөгдсөн 2 тооны утгуудыг солино

	Params:
	int a - утга солих тоо
	int b - утга солих тоо

	Return:
	void
*/
void swap_nums(int *a, int *b)
{
	// temp-т а-н утгыг хадгална
	int temp = *a;
	// а-н утгыг b-н утгаар оноож өгнө
	*a = *b;
	// b-m хадгалж авсан а-н утгыг b-д оноож өгнө
	*b = temp;
}

int main()
{
	//  Бүхэл 2 тоо зарлах
	int a = 10;
	int b = 96;

	// функцээ ажиллуулах
	swap_nums(&a, &b);

	// хоёр тоогоо хэвлэнэ
	cout << "a: " << a << endl;
	cout << "b: " << b << endl;
}