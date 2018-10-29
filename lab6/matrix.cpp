#include "./matrix.h"

#include <iostream>

void Matrix::constructor(void) {
    // Матрицид мөр баганы хэмжээгээр санах ой нөөцөлж байна
    this->values = new float *[this->row];
    for (int row_position = 0; row_position < this->row; row_position++)
        values[row_position] = new float[this->column];

    // Матрицид утга оноож байна
    for (int row_position = 0; row_position < this->row; row_position++) {
        for (int column_position = 0; column_position < this->column; column_position++) {
            this->set_value(row_position, column_position, 0);
        }
    }
}
Matrix::Matrix() {
    // Мөр баганад анхны утга 1-г өгч байна
    this->set_column(1);
    this->set_row(1);
    // Матрицийн санах ой нөөцөлж, 0 ээр дүүргнэ
    this->constructor();
}

Matrix::Matrix(int column, int row) {
    // Мөр баганад анхны утга өгч байна
    this->set_column(column);
    this->set_row(row);
    // Матрицийн санах ой нөөцөлж, 0 ээр дүүргнэ
    this->constructor();
}

Matrix::Matrix(int row, int column, float **values, int values_row_size, int values_col_size) {
    // Мөр баганад анхны утга 1-г оөгч байна
    this->set_column(column);
    this->set_row(row);
    // Матрицийн санах ой нөөцөлж, 0 ээр дүүргнэ
    this->constructor();
    // Хэрэв оруулах мөр баганы тоо матрицийн мөр баганы тоотой зороотэй үед дуусгна
    if (this->row != values_row_size || this->column != values_col_size) {
        return;
    }
    // Орж ирсэн 2 хэмжээс хүснэгтийн утгыг авч марицид хийнэ
    for (int row_position = 0; row_position < this->row; row_position++) {
        for (int column_position = 0; column_position < this->column; column_position++) {
            this->set_value(row_position, column_position, values[row_position][column_position]);
        }
    }
}

Matrix::~Matrix() {
    // Багананыг устагж байна
    for (int row_position = 0; row_position < this->row; row_position++) {
        for (int column_position = 0; column_position < this->column; column_position++) {
            std::cout << values[row_position][column_position] << " ";
        }
        std::cout << std::endl;
        delete[] values[row_position];
    }
    // Мөрийг устагж байна
    delete[] values;
}

void Matrix::set_column(int column) {
    // Багана 0-с бага байж болохгүй учир 1 болгно
    if (column < 0)
        column = 1;
    this->column = column;
}

void Matrix::set_row(int row) {
    // Мөр 0-с бага байж болохгүй учир 1 болгно
    if (row < 0)
        row = 1;
    this->row = row;
}

void Matrix::set_value(int row, int column, int value) {
    this->values[row][column] = value;
}

int Matrix::get_column(void) const {
    return this->column;
}

int Matrix::get_row(void) const {
    return this->row;
}

float Matrix::get_value(int row, int column) const {
    return this->values[row][column];
}

bool Matrix::check_for_add_and_sub(int row_1, int col_1, int row_2, int col_2) {
    if (row_1 == row_2 && col_1 == col_2)
        return false;
    return true;
}

bool Matrix::check_for_mul(int col_1, int row_2) {
    if (col_1 == row_2)
        return false;
    return true;
}

Matrix Matrix::operator+(const Matrix &addition) {
    // Буцаах матирицийг үүсгэж байна
    Matrix new_matrix(this->row, this->column);

    // Мөр багны тоо өөр үед үйлдэл хийхгүй
    if (check_for_add_and_sub(this->row, this->column, addition.row, addition.column)) {
        return new_matrix;
    }

    for (int row_position = 0; row_position < this->row; row_position++) {
        for (int column_position = 0; column_position < this->column; column_position++) {
            float new_value = this->values[row_position][column_position] + addition.values[row_position][column_position];
            new_matrix.set_value(row_position, column_position, new_value);
        }
    }
    return new_matrix;
}

Matrix Matrix::operator-(const Matrix &subtraction) {
    // Буцаах матирицийг үүсгэж байна
    Matrix new_matrix(this->row, this->column);

    if (check_for_add_and_sub(this->row, this->column, subtraction.row, subtraction.column)) {
        Matrix none;
        return new_matrix;
    }

    for (int row_position = 0; row_position < this->row; row_position++) {
        for (int column_position = 0; column_position < this->column; column_position++) {
            float new_value = this->values[row_position][column_position] - subtraction.values[row_position][column_position];
            new_matrix.set_value(row_position, column_position, new_value);
        }
    }
    return new_matrix;
}

Matrix Matrix::operator*(const Matrix &multiplication) {
    // Буцаах матирицийг үүсгэж байна
    Matrix new_matrix(this->row, multiplication.column);
    // m x n * a x b ( n == a ) болож шинэ үүсэх матриц нь m * b байна
    // Мөр багны тоо өөр үед үйлдэл хийхгүй
    if (check_for_mul(this->column, multiplication.row)) {
        return new_matrix;
    }

    for (int i = 0; i < this->row; i++) {
        for (int j = 0; j < multiplication.column; j++) {
            for (int k = 0; k < this->column; k++) {
                new_matrix.set_value(i, j, new_matrix[i][j] + this->values[i][k] * multiplication[k][j]);
            }
        }
    }
    return new_matrix;
}

// [][] operator definition
float *Matrix::operator[](int row) const {
    return this->values[row];
}

// Refrence operators

Matrix &Matrix::operator=(const Matrix &assign) {
    // Мөр багны тоо өөр үед үйлдэл хийхгүй
    if (check_for_add_and_sub(this->row, this->column, assign.row, assign.column)) {
        return *this;
    }

    for (int i = 0; i < this->row; i++) {
        for (int j = 0; j < this->column; j++) {
            this->set_value(i, j, assign[i][j]);
        }
    }
    return *this;
}

Matrix &Matrix::operator++(int) {
    for (int i = 0; i < this->row; i++) {
        for (int j = 0; j < this->column; j++) {
            this->set_value(i, j, this->values[i][j] + 1);
        }
    }
    return *this;
}

Matrix &Matrix::operator--(int) {
    for (int i = 0; i < this->row; i++) {
        for (int j = 0; j < this->column; j++) {
            this->set_value(i, j, this->values[i][j] - 1);
        }
    }
    return *this;
}
Matrix &Matrix::operator+=(const Matrix &addition) {
	*this = *this + addition;
    return *this;
}
Matrix &Matrix::operator-=(const Matrix &subtraction) {
	*this = *this - subtraction;
    return *this;
}
Matrix &Matrix::operator*=(const Matrix &multiplication) {
	*this = *this * multiplication;
    return *this;
}