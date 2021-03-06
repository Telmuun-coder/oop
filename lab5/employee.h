#ifndef EMPPLOYEE_H
#define EMPPLOYEE_H

#include <iostream>

using namespace std;
class employee
{
  public:
    // Ажилчны нийт тоо
    static int id_number;

  private:
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
		Анхдагч байгуулагч функц
		name-т Default
		position-т Employee
		worked_hour-т 0.0
		зэрэг утгуудыг оноож, санах ой нөөцлөнө

		Params:
		void
	*/
	employee();

    /*
        Хуудагч байгуулагч нэг ажилчингий мэдээлэлийг нөгөө ажилчинд өгнө

        Param:
        employee &emp - Хуулах ажилчингийн хаяг
    */
    employee(const employee &emp);

	/*
		Параметртэй байгуулагч функц. Параметрийн дагуу объектд анхны утгууд оноож, санах ой нөөцлөнө

		Params:
		int e_id - шинээр үүсгэж буй ажилчингийн дугаар
		char e_name[] - шинээр үүсгэж буй ажилчингийн нэр
		char e_position[] - шинээр үүсгэж буй ажилчингийн албан тушаал
	*/
	employee(const char e_name[], const char e_position[], float e_worked_hour = 0.0);
	

	/*
		Устгагч функц

		ажилчингийн new гээр нөөцөлсөн name, position-г delete оператор ашиглан чөлөөлнө.
	*/
	~employee();

    /*
        Ажилчдын тоог буцааж өгнө

		Params:
		void

		Return:
		void
    */
    static int get_id_number();
	/*
		Гишүүн ажилчингийн дугаарыг буцааж өгнө

		Params:
		void

		Return:
		int - Гишүүн ажилчингийн дугаар
	*/
	int get_id();

	/*
		Гишүүн ажилчингийн нэрийг буцааж өгнө

		Params:
		void

		Return:
		char* - Гишүүн ажилчингийн нэр
	*/
	char *get_name();

	/*
		Гишүүн ажилчингийн албан тушаалыг буцааж өгнө

		Params:
		void

		Return:
		char* - Гишүүн ажилчингийн албан тушаал
	*/
	char *get_position();

	/*
		Гишүүн ажилчингийн ажилласан цагийг буцааж өгнө

		Params:
		void

		Return:
		float - Гишүүн ажилчингийн ажилласан цаг
	*/
	float get_worked_hour();

	/*
		Гишүүн ажилчингийн нэрийг өөрчилнө

		Params:
		int e_id - шинээр өөрчлөх гишүүн ажилчингийн нэр

		Return:
		void
	*/
	void set_name(const char e_name[]);

	/*
		Гишүүн ажилчингийн албан тушаалыг өөрчилнө

		Params:
		int e_id - шинээр өөрчлөх гишүүн ажилчингийн албан тушаал

		Return:
		void
	*/
	void set_position(const char e_position[]);

	/*
		Гишүүн ажилчингийн ажилласан цагийг өөрчилнө

		Params:
		int e_id - шинээр өөрчлөх гишүүн ажилчингийн ажилласан цаг

		Return:
		void
	*/
	void set_worked_hour(float e_worked_hour);

	/*
		Гишүүн ажилчны мэдээлэлийг дэлгэцэнд хэвлэнэ

		Params:
		void

		Return:
		void
	*/
	void print();

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

	/*
		Ажилчин хүснэгтийг цалингаар нь багаас ихруу эрэмблэх

		Params:
		employee employee_array[] - Эрэмблэх ажилчин хүснэгт
        int emp_array_length - эрэмблэх ажилчин хүснэгтийн урт

		Return:	
        void
	*/
	void sort_employee_by_salary(employee *emp_array[], int emp_array_lenght);

    /*
		Ажилчин хүснэгтийг нэрээр нь эрэмблэх

		Params:
		employee employee_array[] - Эрэмблэх ажилчин хүснэгт
        int emp_array_length - эрэмблэх ажилчин хүснэгтийн урт

		Return:	
        void
    */
    void sort_employee_by_name(employee **emp_array, int emp_array_length);

  private:
	/*
		Захирлын цалинг бодох

		Params:
		void

		Return:
		void
	*/
	float calculate_salary_ceo();

    /*
 		Ажилчидын тоог нэгээр ихэсгэх

		Params:
		void

		Return:
		void
    */
    static void inc_id_number();

	/*
		Гишүүн ажилчны дугаарыг өөрчилнө

		Params:
		int e_id - шинээр өөрчлөх гишүүн ажилчингийн дугаар

		Return:
		void
	*/
	void set_id(int e_id);
};

#endif