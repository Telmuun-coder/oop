#ifndef EMPPLOYEE_H
#define EMPPLOYEE_H

#include "./employee.h"
#include <string.h>

/*

*/
employee::employee()
{
    this->set_id(0);
    this->set_name("Default");
	this->set_position("Employee");
    this->set_worked_hour(0.0);
}

/*  Copy constructor
 *  
 */
employee::employee(const employee &emp)
{
    this->set_id(emp.id);
    this->set_name(emp.name);
    this->set_position(emp.position);
    this->set_worked_hour(emp.worked_hour);
}

/*

*/
employee::employee(int e_id, const char e_name[], const char e_position[])
{
    this->set_id(e_id);
    this->set_name(e_name);
    this->set_position(e_position);
    this->set_worked_hour(0.0);
}

/*

*/
employee::~employee()
{
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
char *employee::get_position()
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
void employee::set_name(const char e_name[])
{
    if (name != nullptr)
    {
        delete[] name;
    }

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
void employee::set_position(const char e_position[])
{
    if (position != nullptr)
    {
        delete[] position;
    }

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
}

#endif
