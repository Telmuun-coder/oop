#ifndef MATRIX_H
#define MATRIX_H
// const https://stackoverflow.com/questions/28987916/cannot-call-a-method-of-const-reference-parameter-in-c
// function return as refrence https://www.programiz.com/cpp-programming/return-reference
// Operator overload https://en.cppreference.com/w/cpp/language/operators
// Matrix https://www.mathwarehouse.com/algebra/matrix/multiply-matrix.php
// Post vs pre fix https://stackoverflow.com/questions/8006264/post-increment-in-operator-overloading-in-c
class Matrix {
   private:
    int column;
    int row;
    float **values;
    void constructor(void);

   public:
    Matrix();
    Matrix(int column, int row);
    Matrix(int column, int row, float **values, int values_row_size, int values_col_size);
    ~Matrix();

    // Set
    void set_column(int column);
    void set_row(int row);
    void set_value(int row, int column, int value);

    // Get
    int get_column(void) const;
    int get_row(void) const;
    float get_value(int row, int column) const;

    // Operator
    bool check_for_add_and_sub(int row_1, int col_1, int row_2, int col_2);
    bool check_for_mul(int col_1, int row_2);
    Matrix operator+(Matrix const &addition);
    Matrix operator-(const Matrix &subtraction);
    Matrix operator*(const Matrix &multiplication);
    // Байгаа зүйл дээр өөрчилөлт явгзаж байгаа тул refrence буцаана
    // 1. Илүү хурдан болно
    // Шинээр local хувьсагч үүсгэхгүй дуудагдсан матриц дээр үйлдэл хийгээд түүнийгээ буцаана
    // return *this; буцах утга нь & учир өөрчилөгдсөн марицийн хаягийш буцаана
    /*
    Matrix a;
    b = a++;
    // Хэрэв шинээр үүсгээд түүнийхээ утгыг буцаах үед
    local учир функц дуусахад устаад ctor return хийх үед ажилна
    */
    Matrix &operator=(const Matrix &assign);
    Matrix &operator++(int);
    Matrix &operator--(int);
    Matrix &operator+=(const Matrix &addition);
    Matrix &operator-=(const Matrix &subtraction);
    Matrix &operator*=(const Matrix &multiplication);
    float *operator[](int row) const;
};

#endif