#include "./employee.h"

int main()
{
    employee lkhamaa;
    
    lkhamaa.init();
    lkhamaa.read();
    float hour;
    cin >> hour;
    lkhamaa.add_worked_hour(hour);
    cout << "Tsalin chine: " << lkhamaa.calculate_salary() << "k$" << endl;

    lkhamaa.print();
}
