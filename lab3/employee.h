#include <iostream>
using namespace std;

class employee {
    public:
        // Гишүүн ажилчны дугаар
        int id;
        // Гишүүн ажилчны нэр
        char name[20];
        // Гишүүн ажилчны албан тушаал
        char position[20];
        // Гишүүн ажилчны ажилсан цаг
        float worked_hour;    

    public:
        // Гишүүн ажилчинд анхны утга оноож үүсгэнэ.
        void init();
        // Гишүүн ажилчны мэдээлэл дэлгэцэнд хэвлэх
        void print();
        // Гишүүн ажилчны мэдээлэл
        void read();
        // Гишүүн ажилчны цалинг ажилласан цагаар нь бодож буцаана.
        float calculate_salary();
        // Захирлын цалинг бодох
        float calculate_salary_ceo();
        // Гишүүн ажилчны ажилласан цагийг нэмнэ
        bool add_worked_hour(float hour);

    // Do g++ -c *.cpp -o employee.o g++ main.cpp employee.o ./main.exe };
};
