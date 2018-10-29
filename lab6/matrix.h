#ifndef MATRIX_H
#define MATRIX_H
// const https://stackoverflow.com/questions/28987916/cannot-call-a-method-of-const-reference-parameter-in-c
// function return as refrence https://www.programiz.com/cpp-programming/return-reference
// Operator overload https://en.cppreference.com/w/cpp/language/operators
// Matrix https://www.mathwarehouse.com/algebra/matrix/multiply-matrix.php
// Post vs pre fix https://stackoverflow.com/questions/8006264/post-increment-in-operator-overloading-in-c
class Matrix {
private:
	// Баганы хэмжээ
	int column;
	// Мөрний хэмжээ
	int row;
	// Матрицын утгууд
	float **values;
	/*
		Марицид мөр баганы хэмжээгээр санах ой new ашиглан нөөцлөөд 0 ээр дүүргнэ

		Params:
		void

		Return:
		void
	*/
	void constructor(void);

public:
	// Мөр, баганыг 1 ээр аваад constructor() функц дуудаж 0-р дүүргнэ
	Matrix();
	// Мөр, баганы утгыг гараас аван constructor() функц дуудаж 0-р дүүргнэ
	Matrix(int column, int row);
	/*
		Мөр, баганы утгыг гараас аван гараас орж ирсэн 2 хэмжээст хүснэгтийн утгаар дүүргэнэ

		Params:
		int row				- Шинээр үүсэх матрицны мөрний хэмжээ
		int column			- Шинээр үүсэх матрицны баганы хэмжээ
		flaot **values		- Хуулах 2 хэмжээст хүснэгтийн хаяг
		int values_row_size	- Хуулах 2 хэмжээст хүснэгтийн мөрний хэмжээ
		int values_col_size	- Хуулах 2 хэмжээст хүснэгтийн баганы хэмжээ

		Return:
		NONE
	*/
	Matrix(int row, int column,float **values, int values_row_size, int values_col_size);

	/*
		Матрицын утгыг delete оператор ашиглан чөлөөлнө

		Params:
		NONE

		Return:
		NONE
	*/
	~Matrix();

	// Set
	/*
		Матрицын мөрийг өөрчилнө

		Params:
		int row - Шинэ матрицийн мөрийн хэмжээ

		Return:
		NONE
	*/
	void set_row(int row);
	/*
		Матрицын баганыг өөрчилнө

		Params:
		int column - Шинэ матрицийн баганы хэмжээ

		Return:
		NONE
	*/
	void set_column(int column);
	/*
		Матрицын тухай мөр, баганад байгаа утгыг өөрчилнө

		Params:
		int row		- Матрицын мөр
		int column	- Матрицын багана
		float value	- Матрицы тухай мөр, багана дээр байгаа утгыг өөрчилө

		Return:
		NONE
	*/
	void set_value(int row, int column, float value);

	// Get
	/*
		Матрицын баганы хэмжээг буцаана

		Params:
		NONE

		Return:
		int - Матрицын баганы хэмжээ
	*/
	int get_column(void) const;
	/*
		Матрицын мөрийн хэмжээг буцаана

		Params:
		NONE

		Return:
		int - Матрицын мөрний хэмжээ
	*/
	int get_row(void) const;
	/*
		Матрицын тухай мөр, баганад байгаа утгыг буцаана

		Params:
		int row		- Матрицын мөр
		int column	- Матрицын багана

		Return:
		float - Тухай мөр баганд буй утгыг буцаана
	*/
	float get_value(int row, int column) const;

	// Operator
	/*
		Өгөгдсөн хоёр матрицын мөр болон багана тэнцүү байхыг шалгна

		Params:
		int row_1		- Нэгдэх матрицын мөр
		int col_1		- Нэгдэх матрицын багана
		int row_2		- Хоёрдох матрицын мөр
		int col_2		- Хоёрдох матрицын багана

		Return:
		float - Мөрүүд, баганууд тэнцүү үед 1 үгүй үед 0
	*/
	bool check_for_add_and_sub(int row_1, int col_1, int row_2, int col_2);
	/*
		Өгөгдсөн хоёр матрицын багана мөр тэнцүү хэсэгийг шалгана

		Params:
		int col_1		- Нэгдэх матрицын багана
		int row_2		- Хоёрдох матрицын мөр

		Return:
		float - Мөр, багана тэнцүү үед 1 үгүй үед 0
	*/
	bool check_for_mul(int col_1, int row_2);
	/*
		Хоёр матрицыг нэмнэ

		Params:
		Matrix const &addition	- Нэмж буй матриц

		Return:
		Matrix - Хоёр матрицын нийлбэр
	*/
	Matrix operator+(Matrix const &addition);
	/*
		Хоёр матрицыг хасна

		Params:
		Matrix const &subtraction	- Хасаж буй матриц

		Return:
		Matrix - Хоёр матрицын ялгвар
	*/
	Matrix operator-(const Matrix &subtraction);
	/*
		Хоёр матрицыг үржүүлнэ

		Params:
		Matrix const &multiplication	- Үржүүлэж буй матриц

		Return:
		Matrix - Хоёр матрицын үржвэр
	*/
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
	/*
		Дуудсан матриц дээр операндын хойно байгаа матрицын утгыг хуулна

		Params:
		Matrix const &assign	- Утгыг нь авх матриц

		Return:
		Matrix& - Дуудсан матрицын заалтыг буцаана
	*/
	Matrix &operator=(const Matrix &assign);
	/*
		Матрицын утгуудад 1-г нэмнэ

		Params:
		int - Postfixе-г заана

		Return:
		Matrix& - Дуудсан матрицын заалтыг буцаана
	*/
	Matrix &operator++(int);
	/*
		Матрицын утгуудаас 1-г хасна

		Params:
		int - Postfixе-г заана

		Return:
		Matrix& - Дуудсан матрицын заалтыг буцаана
	*/
	Matrix &operator--(int);
	/*
		Дуудсан матриц дээр операндын хойно байгаа матриц нэмнэ

		Params:
		Matrix const &addition	- Нэмнэх матриц

		Return:
		Matrix& - Дуудсан матрицын заалтыг буцаана
	*/
	Matrix &operator+=(const Matrix &addition);
	/*
		Дуудсан матрицаас операндын хойно байгаа матрицыг хасна

		Params:
		Matrix const &subtraction	- Хасах матриц

		Return:
		Matrix& - Дуудсан матрицын заалтыг буцаана
	*/
	Matrix &operator-=(const Matrix &subtraction);
	/*
		Дуудсан матрицаас операндын хойно байгаа матрицаар үржүүлнэ

		Params:
		Matrix const &multiplication	- Үржүүлэх матриц

		Return:
		Matrix& - Дуудсан матрицын заалтыг буцаана
	*/
	Matrix &operator*=(const Matrix &multiplication);
	/*
		Матрицын мөрийг авч түүнд байгаа 1 хэмжээс хүснэгт буцаана

		Params:
		int row - Матрицын мөр

		Return:
		float * - Мөрний эхлэл хаяг
	*/
	float *operator[](int row) const;
};

#endif