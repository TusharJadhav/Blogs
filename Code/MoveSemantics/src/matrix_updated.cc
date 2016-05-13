#include <iostream>
#include <time.h>
#include <chrono>
#include "matrix_updated.h"

Matrix::Matrix(int dimA, int dimB) :
	dim_a_(dimA),
	dim_b_(dimB),
	data_(new int[dimA * dimB])
{
	std::cout << "Inside Matrix constructor" << std::endl;
	int index;

	for(int i = 0 ; i < dimA ; ++i)
	{
		for(int j = 0 ; j < dimB ; ++j)
		{
			index = (i + ( j * dimA ));
		}
	}
}

Matrix::Matrix(const Matrix &other) :
	dim_a_(other.dim_a_),
	dim_b_(other.dim_b_),
	data_(new int[other.dim_a_ * other.dim_b_])
{
	std::cout << "Inside Matrix Copy constructor" << std::endl;

	int nRange = other.dim_a_ * other.dim_b_;
	for(int i = 0 ; i < nRange ; ++i)
		data_[i] = other.data_[i];
}

Matrix::Matrix(Matrix &&other)
{
	std::cout << "Inside Matrix Move constructor" << std::endl;

	dim_a_ = other.dim_a_;
	dim_b_ = other.dim_b_;
	data_ = other.data_;
	other.data_ = nullptr;
}

Matrix MatrixFactory(int a, int b)
{
	return std::move(*new Matrix(a, b));
}

Matrix::~Matrix()
{
	std::cout << "Inside Matrix Destructor" << std::endl;
	if (data_)
		delete[]data_;
}

int main()
{
	std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();
	
	Matrix large = MatrixFactory(1000, 1000);

	std::chrono::high_resolution_clock::time_point stop = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();

	std::cout << "Time taken to complete: " << duration << std::endl;
	return 0;
}
