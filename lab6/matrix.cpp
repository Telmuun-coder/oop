#include "./matrix.h"

Matrix::Matrix() {
    this.column = 1;
    this.row = 1;
    
    for (int row_position = 0; row_position < row; row_position++) {
        for (int column_position = 0; column_position < column; column_position++) {
            set_value(row_position, column_position) = 0;
        }     
    }
}

void Matrix::set_column(int column) {
    this.column = column;
}

void Matrix::set_row(int row) {
    this.row = row;
}

void Matrix::set_value(int row, int column, int value) {
    this.values[row_position][column_position] = value;
}

int Matrix::get_column(int column) {
    return this.column;
}

int Matrix::get_row(int row) {
    return this.row;
}

float Matrix::get_value(int row, int column, int value) {
    return this.values[row_position][column_position];
}

Matric & Matric::operator + (const Matrix &addition);