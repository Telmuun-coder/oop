#include "./employee.h"
#include <string.h>

// Static ажилчингийн тоонд анхны утга оноож байна
int employee::number_of_employee = 0;

employee::employee()
{
    employee::inc_number_of_employee();
    this->set_id(number_of_employee);
    this->set_name("Default");
	this->set_position("Employee");
    this->set_worked_hour(0.0);
}

employee::employee(const employee &emp)
{
    this->set_id(emp.id);
    this->set_name(emp.name);
    this->set_position(emp.position);
    this->set_worked_hour(emp.worked_hour);
}

employee::employee(const char e_name[], const char e_position[], float e_worked_hour)
{
    employee::inc_number_of_employee();
    this->set_id(number_of_employee);
    this->set_name(e_name);
    this->set_position(e_position);
    this->set_worked_hour(e_worked_hour);
}

employee::~employee()
{
	delete[] name;
	delete[] position;
}

void employee::inc_number_of_employee()
{
    number_of_employee++;
}

int employee::get_id()
{
	return id;
}

char *employee::get_name()
{
	return name;
}

char *employee::get_position()
{
	return position;
}

float employee::get_worked_hour()
{
	return worked_hour;
}

void employee::set_id(int e_id)
{
	id = e_id;
}

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

void employee::set_worked_hour(float e_worked_hour)
{
	worked_hour = e_worked_hour;
}

void employee::print()
{
	cout << "Id: " << id << endl;
	cout << "Name: " << name << endl;
	cout << "Position: " << position << endl;
	cout << "Wordked hours: " << worked_hour << endl;
	cout << endl;
}

float employee::calculate_salary()
{
	float salary = worked_hour * 100;

	if (strcmp(position, "CEO") == 0)
		return salary + calculate_salary_ceo();

	return salary;
}

float employee::calculate_salary_ceo()
{
	return worked_hour * 50;
}

bool employee::add_worked_hour(float hour)
{
	if (hour > 0 && hour < 24)
	{
		worked_hour += hour;
		return true;
	}

	return false;
}

void employee::sort_employee_by_salary(employee *emp_array[], int emp_array_lenght)
{
    for (int emp_index = 0; emp_index < emp_array_lenght - 1; emp_index++)
    {
        // Хамгийн бага цалинтай ажилчингийн индекс, цалингийн хэмжээг хадгалах хувьсагч зарласан
        float min_salary = (emp_array[emp_index])->calculate_salary();
        int min_index = emp_index;
        
        // Ажилчин хүснэгтээс хамгийн бага цалитай ажилчинг олож индекс болон цалингийн хэмжээг хадаглана
        for(int emp_cmp_index = emp_index + 1; emp_cmp_index < emp_array_lenght; emp_cmp_index++)
        {
            if (min_salary > emp_array[emp_cmp_index]->calculate_salary() )
            {
                min_salary = emp_array[emp_cmp_index]->calculate_salary();
                min_index = emp_cmp_index;
            }
        }

        // Хамгийн бага цалинтай ажилчиг эхнээс нь байрандан оруулна
        // Хамгийн бага цалинтай ажилчин болон байранд оруулах индекс адилхаг үед сольхгүй
        if (min_index != emp_index)
        {
            employee *temp = emp_array[min_index];

            emp_array[min_index] = emp_array[emp_index];
            emp_array[emp_index] = temp;
        }
    }
}

void employee::sort_employee_by_name(employee *emp_array[], int emp_array_lenght)
{
    for (int emp_index = 0; emp_index < emp_array_lenght - 1; emp_index++)
    {
        // Өмнө нь байх нэрий, индексийг хадаглах хувьсагч зарласан
        char *min_name = emp_array[emp_index]->get_name();
        int min_index = emp_index;
        
        // Өмнө нь байх нэрийг олож дээрэх хувьсагчид хадгална
        for(int emp_cmp_index = emp_index + 1; emp_cmp_index < emp_array_lenght; emp_cmp_index++)
        {
            if ( strcmp(min_name, emp_array[emp_cmp_index]->get_name()) > 0 )
            {
                min_name = emp_array[emp_cmp_index]->get_name();
                min_index = emp_cmp_index;
            }
        }
        
        // Өмнө нь орох нэртэй ажилчинг байранд нь оруулж, солигдож буй ажилчид өөрийн утгаа өгнө
        if (min_index != emp_index)
        {
            employee *temp = emp_array[min_index];

            emp_array[min_index] = emp_array[emp_index];
            emp_array[emp_index] = temp;
        }
    }
}
