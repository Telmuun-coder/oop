#include "./employee.h"
#include <string.h>

void employee::init()
{
    id = 0;
    strcpy(name, "");
    strcpy(position, "employee");
    worked_hour = 0.0;
}

void employee::print()
{
    cout << "Id: " << id << endl;
    cout << "Name: " << name << endl;
    cout << "Position: " << position << endl;
    cout << "Wordked hours: " << worked_hour << endl;
}

void employee::read()
{

    cout << "Ajilchingiin Idiig oruul: " << endl;
    cin >> id;
    cout << "Ajilchingiin Neriig oruul: " << endl;
    cin >> name;
    cout << "Ajilchingiin Alban tushaaliig oruul: " << endl;
    cin >> position;
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
