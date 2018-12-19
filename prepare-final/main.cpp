#include <iostream>
#include <string.h>
using namespace std;

int get_max(int a, int b) {
    return a > b ? a : b;
}

double get_max(double a, double b) {
    return a > b ? a : b;
}

template <class T, class U, class X>
T getMax(T a, U b) {
    return a > b ? a : b;
}

template <class T>
class pair1 {
    public:
    T a;
};

pair1<int> aa;
pair1<double> bb;

int main() {
    getMax<int, double, char>(12, 24);

    get_max(4, 10);
    // 2
    int a = 8;
    // p_a gsm haygn huvsagch uuseg
    int *p_a = &a;

    // p_a ashiglan a iin utgiig hvel
    cout << *p_a << endl;

    // z_a a iin zaaltan huvsagch uuseg
    int &z_a = a;

    // new ashiglan b m double turuliin sanah oi nuutsul

    double *b = new double;
    *b = 10; 
    delete b;

    char *c = new char[3];
    delete[] c;

    // class
    class employee {
        public:
        int age;
        char name[10];
        employee()
        {
             age = 20;
            strcpy(name, "Default");
        };

        employee(int e_age, char *e_name)
        {
            age = e_age;
            strcpy(name, e_name);
        };

        employee(employee &e)
        {
            age = e.age;
            strcpy(name, e.name);
        };


        ~employee()
        {
            cout << "BYEBYE " << name;
        };
        
        public:
        void print() {
            cout << age << endl;
            cout << name << endl;
        }
    };

    // base
    class aClass {
        public:
        virtual void print() = 0;
    };

    class bClass : public aClass {
        public:
        virtual void show() = 0;
    };

    class base : public aClass {
        public:
        int a;
        virtual void print() {
            cout << "hurdal!" << endl;
        }
    };

    class derived : public base{
        public:
        int b;
        void print () {
            cout << "Hooe!" << endl;
        }
    };
    // derived

    base b1, *pptr;
    pptr = &b1;
    derived d1;
    
    pptr->print();

    pptr = &d1;
    pptr->print();


    employee d;
    employee sar(1, "Sarre");
    employee e(sar);
    d.print();
    sar.print();
    e.print();

    // o gsn emp iin haygan huvsagch uusgeed new eer sanah oi nuutslnu
    employee *o = new employee(5, "SRl");
    (*o).print(); 
    o->print();

    employee *oo = new employee(*o);
    oo->print();

    delete o;
    delete oo;
    
    // e gsn haygan object 

    return 0;
}