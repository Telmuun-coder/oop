#ifndef MATRIX_H
#define MATRIX_H

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
    int get_column(void);
    int get_row(void);
    float get_value(int row, int column);

    // Operator
    Matrix operator+(const Matrix &addition);
    Matrix operator-(const Matrix &subtraction);
    Matrix operator*(const Matrix &multiplication);
    Matrix &operator=(const Matrix &assign);
    void operator++(void);
    void operator--(void);
    Matrix &operator+=(const Matrix &addition);
    Matrix &operator-=(const Matrix &subtraction);
    Matrix &operator*=(const Matrix &multiplication);
    float *operator[](int row);
};

#endif