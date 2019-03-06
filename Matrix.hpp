#include <fstream>
#include <numeric>
#include <vector>

class Matrix{
public:
	int rows;
	int columns;
	std::vector <float> data;

public:
	Matrix operator +(const Matrix &b){
		Matrix result=(*this);

		for(int i=0; i<this->rows*this->columns; ++i){
			result.data[i] += b.data[i];
		}

		return result;
	}

};

Matrix operator +(const Matrix &a, const Matrix &b){
	Matrix result = a;

	for(int i=0; i<a.rows*a.columns; ++i){
		result.data[i] = a.data[i] + b.data[i];
	}

	return result;
}

std::ostream &operator <<(std::ostream &output,const Matrix &matrix){
	for(int i=0; i<matrix.rows*matrix.columns; ++i){
		output << matrix.data[i] << " ";
	}
	return output;
}

std::istream &operator >>(std::istream &input, Matrix &matrix){
	float buff;
	input >> matrix.rows;
	input >> matrix.columns;

	for(int i=0; i<matrix.rows*matrix.columns; ++i){
		input >> buff;
		matrix.data.push_back(buff);
		buff=0;
	}
	return input;
}

class SumInput{
public:
	Matrix a;
	Matrix b;
};

std::ostream &operator <<(std::ostream &output,const SumInput &matrix){
	output << matrix.a << std::endl;
	output << matrix.b << std::endl;
	return output;
}

std::istream &operator >>(std::istream &input, SumInput &matrix){
	float buff;
	int rows, columns;
	input >> rows;
	input >> columns;
	
	matrix.a.rows=rows;
	matrix.a.columns=columns;
	
	matrix.b.rows=rows;
	matrix.b.columns=columns;

	for(int i=0; i<matrix.a.rows*matrix.a.columns; ++i){
		input >> buff;
		matrix.a.data.push_back(buff);
		buff=0;
	}

	for(int i=0; i<matrix.b.rows*matrix.b.columns; ++i){
		input >> buff;
		matrix.b.data.push_back(buff);
		buff=0;
	}
	return input;
}



























