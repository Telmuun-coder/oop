#include <iostream>
using namespace std;
class employee
{
  private:
	// Гишүүн ажилчны дугаар
	int id;
	// Гишүүн ажилчны нэр
	char *name;
	// Гишүүн ажилчны албан тушаал
	char position[20];
	// Гишүүн ажилчны ажилсан цаг
	float worked_hour;

  public:
    employee();
    employee(int e_id, char e_name[], char e_position[]);

	// Гишүүн ажилчинд анхны утга оноож үүсгэнэ.
	void init();
	// Гишүүн ажилчны мэдээлэл дэлгэцэнд хэвлэх
	void print();
	// Гишүүн ажилчны мэдээлэл
	void read();
	// Гишүүн ажилчны цалинг ажилласан цагаар нь бодож буцаана.
	float calculate_salary();
	// Гишүүн ажилчны ажилласан цагийг нэмнэ
	bool add_worked_hour(float hour);

  private:
	// Захирлын цалинг бодох
	float calculate_salary_ceo();
};
