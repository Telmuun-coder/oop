#ifndef MATRIX_H
#define MATRIX_H

class Matrix {
    private:
        int column;
        int row;
        float values[][];
    
    public:
        Matrix();
        Matrix(int column = 1, int row = 1);
        
        // Set
        void set_column(int column);
        void set_row(int row);
        void set_value(int row, int column, int value);
        
        // Get
        int get_column();
        int get_row();
        float get_value(int row, int column);
        
        // Operator
        Matric & operator + (const Matrix &addition);
        Matric & operator - (const Matrix &subtraction);
        Matric & operator * (const Matrix &multiplication);
        Matric & operator = (const Matrix &assign);
        void & operator ++ (const Matrix &increment);
        void & operator -- (const Matrix &decrement);
        void & operator += (const Matrix &addition);
        void & operator -= (const Matrix &subtraction);
        void & operator *= (const Matrix &multiplication);
        float & operator [][] (int row, int column);
};

#endif MATRIX_H