#include <iostream>
using namespace std;

class employee {
    public:
        int id;
        char name[20];
        char position[20];
        float worked_hour;    

    public:
        // Гишүүн ажилчинд анхны утга оноож үүсгэнэ.
        void init();
        // Гишүүн ажилчингийн мэдээлэл дэлгэцэнд хэвлэх
        void print();
        // Гишүүн ажилчингийн мэдээлэл
        void read();
        // Гишүүн ажилчингийн цалинг ажилласан цагаар бодож буцаана.
        float calculate_salary();
        // Захирлын цалин бодох
        float calculate_salary_ceo();
        // Гишүүн ажилчингийн ажилласан цагийн 
        bool add_worked_hour(float hour);

    // Do g++ -c *.cpp -o employee.o g++ main.cpp employee.o ./main.exe };
};
