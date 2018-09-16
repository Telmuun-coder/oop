#include <iostream>;
using namespace std;

int main()
{
	// Тэмдэгт тоон заагч зарласан
	char *p1;

	// Бүхэл тоон заагч зарласан
	int *p2;

	// давхаp нарийвчлалтай бодит тоон заагч зарласан
	double *p3;

	// p1, p2, p3 - ийн хэмжээг хэвлэж байна.
	cout << sizeof(p1) << " " << sizeof(p2) << " " << sizeof(p3);

	// OS-ийн 32bit / 64 bit ээс хамааран 4 / 8 байна.36+
}