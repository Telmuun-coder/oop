#include "./employee.h"

int main()
{
	const int array_size = 3;
	// 3 ажилчинтай ажилчин хүснэгт үүсэгсэн
	employee emp_array[array_size];

	// emp_array-д for давтал ашигал read болон add_worked_hour функцийг дуудан
	// утга гараас оноож байна
	for (int emp_index = 0; emp_index < array_size; emp_index++)
	{
		// Ажилсан цагийг хадаглах бодит тоон хувьсагч
		float hours;

		cout << emp_index + 1 << " => " << endl;
		emp_array[emp_index].read();
		// Гараас утга авч hours-т оноож байна
		cout << "Ajilsan tsagiig oruul: ";
		cin >> hours;
		cout << endl;
		emp_array[emp_index].add_worked_hour(hours);
	}

	emp_array[0].sort_employee_by_salary(emp_array, array_size);

	// emp_array for давтал ашиглан print функцийш дуудан мэдээлэлийг дэлгэцнд хэлэж байна.
	for (int emp_index = 0; emp_index < array_size; emp_index++)
	{
		emp_array[emp_index].print();
	}
}
