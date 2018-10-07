#include <iostream>
using namespace std;
class employee
{
  public:
	// Гишүүн ажилчны дугаар
	int id;
	// Гишүүн ажилчны нэр
	char *name;
	// Гишүүн ажилчны албан тушаал
	char *position;
	// Гишүүн ажилчны ажилсан цаг
	float worked_hour;

  public:
	/*

	*/
	employee();

	/*

	*/
	employee::employee(int e_id, char e_name[], char e_position[]);

	/*

	*/
	~employee();

	/*
	*/
	int get_id();

	/*
	*/
	char *get_name();

	/*
	*/
	char *get_postion();

	/*
	*/
	float get_worked_wour();

	/*
	*/
	void set_id(int e_id);

	/*
	*/
	void set_name(char e_name[]);

	/*
	*/
	void set_position(char e_position[]);

	/*
	*/
	void set_worked_wour(float e_worked_hour);

	/*
		Гишүүн ажилчинд анхны утга оноож өгнө

		Params:
		void

		Return:
		void
	*/
	void init();

	/*
		Гишүүн ажилчны мэдээлэлийг дэлгэцэнд хэвлэнэ

		Params:
		void

		Return:
		void
	*/
	void print();

	/*
		Гишүүн ажилчны мэдээлэл

		Params:
		void

		Return:
		void
	*/
	void read();

	/*
		Гишүүн ажилчны цалинг ажилласан цагаар нь бодож буцаана.

		Params:
		void

		Return:
		void
	*/
	float calculate_salary();

	/*
		Гишүүн ажилчны ажилласан цагийг нэмнэ

		Params:
		float hour - Ажилчингын ажилсн цаг

		Return:
		bool - Зөв утга уруулсан үед 1 бусад үед 0
	*/
	bool add_worked_hour(float hour);

  private:
	/*
		Захирлын цалинг бодох

		Params:
		void

		Return:
		void
	*/
	float calculate_salary_ceo();
};
