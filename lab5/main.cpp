#include "./employee.h"

#define NUMBER_OF_EMPLOYEE 3

int main()
{
    employee *emp_array[NUMBER_OF_EMPLOYEE];

    // Shine ajilchingiin haygiig emp_index-d hadgalj baina
    emp_array[0] = new employee("Sam", "CEO", 10.0);
    emp_array[1] = new employee("Dan", "EMP", 21.0);
    emp_array[2] = new employee("Anna", "EMP", 11.0);

    emp_array[0]->sort_employee_by_salary(emp_array, NUMBER_OF_EMPLOYEE);

    for (int emp_index = 0; emp_index < NUMBER_OF_EMPLOYEE; emp_index++)
    {
        emp_array[emp_index]->print();
        delete emp_array[emp_index];
    }
    return 0;
}