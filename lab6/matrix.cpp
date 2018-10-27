#include "./matrix.h"

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
    // Мөр баганад анхны утга 1-г оөгч байна
    this->set_column(1);
    this->set_row(1);
    // Матрицийн санах ой нөөцөлж, 0 ээр дүүргнэ
    this->constructor();
}

Matrix::Matrix(int column, int row) {
    // Мөр баганад анхны утга 1-г оөгч байна
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
    if (row != values_row_size || column != values_col_size) {
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

int Matrix::get_column(void) {
    return this->column;
}

int Matrix::get_row(void) {
    return this->row;
}

float Matrix::get_value(int row, int column) {
    return this->values[row][column];
}