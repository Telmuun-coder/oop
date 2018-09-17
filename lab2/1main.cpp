#include <iostream>
using namespace std;

int main()
{

	// Бүхэл тоон заагч
	int *a;

	// Бодит тоон заагч
	float *b;

	// Тэмдэгт төрлийн заагч
	char *c;

	cout << "Бүхэл тоон хэмжээ- " << sizeof(int) << endl;
	cout << "Бүхэл тоон төрлийн заагчийн хэмжээ- " << sizeof(a) << endl
		 << endl;

	cout << "Бодит тоон хэмжээ- " << sizeof(double) << endl;
	cout << "Бодит тоон төрлийн заагчийн хэмжээ- " << sizeof(b) << endl
		 << endl;

	cout << "Тэмдэгтийн хэмжээ- " << sizeof(char) << endl;
	cout << "Тэмдэгт төрлийн заагчийн хэмжээ- " << sizeof(c) << endl
		 << endl;
}