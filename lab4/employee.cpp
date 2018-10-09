#include "./employee.h"
#include <string.h>

/*

*/
employee::employee()
{
	id = 0;

	name = new char[strlen("Default") + 1];
	strcpy(name, "Default");

	position = new char[strlen("Employee") + 1];
	strcpy(position, "Employee");

	worked_hour = 0.0;
}

/*

*/
employee::employee(int e_id, char e_name[], char e_position[])
{
	id = e_id;

	name = new char[strlen(e_name) + 1];
	strcpy(name, e_name);

	position = new char[strlen(e_position) + 1];
	strcpy(position, e_position);

	worked_hour = 0.0;
}

/*

*/
employee::~employee()
{
	cout << "Goodbye " << name << "!" << endl;

	delete[] name;
	delete[] position;
}

/*
*/
int employee::get_id()
{
	return id;
}

/*
*/
char *employee::get_name()
{
	return name;
}

/*
*/
char *employee::get_postion()
{
	return position;
}

/*
*/
float employee::get_worked_hour()
{
	return worked_hour;
}

/*
*/
void employee::set_id(int e_id)
{
	id = e_id;
}

/*
*/
void employee::set_name(char e_name[])
{
	if (e_name[strlen(e_name) != '\0'])
	{
		name = new char[strlen(e_name) + 1];
	}
	else
	{
		name = new char[strlen(e_name)];
	}
	strcpy(name, e_name);
}

/*
*/
void employee::set_position(char e_position[])
{
	if (e_position[strlen(e_position) != '\0'])
	{
		position = new char[strlen(e_position) + 1];
	}
	else
	{
		position = new char[strlen(e_position)];
	}
	strcpy(position, e_position);
}

/*
*/
void employee::set_worked_hour(float e_worked_hour)
{
	worked_hour = e_worked_hour;
}

/*
    Гишүүн ажилчинд анхны утга оноож өгнө

    Params:
    void

    Return:
    void
*/
void employee::init()
{
	id = 0;
	strcpy(name, "");
	strcpy(position, "employee");
	worked_hour = 0.0;
}

/*
    Гишүүн ажилчны мэдээлэлийг дэлгэцэнд хэвлэнэ

    Params:
    void

    Return:
    void
*/
void employee::print()
{
	cout << "Id: " << id << endl;
	cout << "Name: " << name << endl;
	cout << "Position: " << position << endl;
	cout << "Wordked hours: " << worked_hour << endl;
	cout << endl;
}

/*
    Гишүүн ажилчны мэдээлэл

    Params:
    void

    Return:
    void
*/
void employee::read()
{
	cout << "Ajilchingiin Idiig oruul: " << endl;
	cin >> id;
	cout << "Ajilchingiin Neriig oruul: " << endl;
	cin >> name;
	cout << "Ajilchingiin Alban tushaaliig oruul: " << endl;
	cin >> position;
}

/*
    Гишүүн ажилчны цалинг ажилласан цагаар нь бодож буцаана.

    Params:
    void

    Return:
    void
*/
float employee::calculate_salary()
{
	float salary = worked_hour * 100;

	if (strcmp(position, "CEO") == 0)
		return salary + calculate_salary_ceo();

	return salary;
}

/*
    Захирлын цалинг бодох

    Params:
    void

    Return:
    void
*/
float employee::calculate_salary_ceo()
{
	return worked_hour * 50;
}

/*
    Гишүүн ажилчны ажилласан цагийг нэмнэ

    Params:
    float hour - Ажилчингын ажилсн цаг

    Return:
    bool - Зөв утга уруулсан үед 1 бусад үед 0
*/
bool employee::add_worked_hour(float hour)
{
	if (hour > 0 && hour < 24)
	{
		worked_hour += hour;
		return true;
	}

	return false;
}

/*
	Ажилчин хүснэгтийг цалингаар нь багаас ихруу эрэмблэх

	Params:
	employee employee_array[] - Эрэмблэх ажилчин хүснэгт

	Return:	
	employee *array - Эрэмблэгдсэн хүснэгтийн эхний элементийн хаяг
*/
void employee::sort_employee_by_salary(employee *emp_array, int emp_array_lenght)
{
	// Ажилчдийн цалинг хадаглах хүснэгт
	float emp_salary_array[emp_array_lenght];

	// Ажилчдийн цалинг calculate_salary функц дуудан олож хүснэгтэд хадаглна
	for (int emp_index = 0; emp_index < emp_array_lenght; emp_index++)
	{
		emp_salary_array[emp_index] = emp_array[emp_index].calculate_salary();
	}

	// selection sort ашиглан цалингийн хүснэгтээ эрэмбэх мөн харгалзах ажилчидыг байрын солино.
	for (int emp_index = 0; emp_index < emp_array_lenght - 1; emp_index++)
	{
		int min_salary = emp_salary_array[emp_index];
		int min_index = emp_index;

		for (int emp_cpm_index = emp_index; emp_cpm_index < emp_array_lenght; emp_cpm_index++)
		{
			if (min_salary > emp_salary_array[emp_cpm_index])
			{
				min_salary = emp_salary_array[emp_cpm_index];
				min_index = emp_cpm_index;
			}
		}

		int min_id = emp_array[min_index].id;
		char min_name[strlen(emp_array[min_index].name)];
		strcpy(min_name, emp_array[min_index].get_name());
		char min_position[strlen(emp_array[min_index].position)];
		strcpy(min_position, emp_array[min_index].get_postion());
		int min_worked_hour = emp_array[min_index].worked_hour;

		swap(emp_salary_array[min_index], emp_salary_array[emp_index]);
		if (min_index != emp_index)
		{
			emp_array[min_index].set_id(emp_array[emp_index].id);
			emp_array[min_index].set_name(emp_array[emp_index].name);
			emp_array[min_index].set_position(emp_array[emp_index].position);
			emp_array[min_index].set_worked_wour(emp_array[emp_index].worked_hour);

			emp_array[emp_index].set_id(min_id);
			emp_array[emp_index].set_name(min_name);
			emp_array[emp_index].set_position(min_position);
			emp_array[emp_index].set_worked_wour(min_worked_hour);
		}
	}
}
