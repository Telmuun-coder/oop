#ifndef EMPPLOYEE_H
#define EMPPLOYEE_H

#include "./employee.h"

#define NUMBER_OF_EMPLOYEE 3

int main()
{
    employee *emp_array[NUMBER_OF_EMPLOYEE];

    // Shine ajilchingiin haygiig emp_index-d hadgalj baina
    employee *new_emp_0 = new employee(1, "Sam", "CEO", 10.0);
    employee *new_emp_1 = new employee(2, "Dan", "EMP", 21.0);
    employee *new_emp_2 = new employee(3, "Anna", "EMP", 11.0);

    emp_array[0] = new_emp_0;
    emp_array[1] = new_emp_1;
    emp_array[2] = new_emp_2;

    emp_array[0]->sort_employee_by_salary(emp_array, NUMBER_OF_EMPLOYEE);

    for (int emp_index = 0; emp_index < NUMBER_OF_EMPLOYEE; emp_index++)
    {
        emp_array[emp_index]->print();
    }
    return 0;
}

#endif
