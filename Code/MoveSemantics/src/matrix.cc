#include <iostream>
#include <time.h>
#include <chrono>
#include "matrix.h"

Matrix::Matrix(int dim_x_axis, int dim_y_axis) :
	dim_a_(dim_x_axis),
	dim_b_(dim_y_axis),
	data_(new int[dim_x_axis * dim_y_axis])
{
	std::cout << "Inside Matrix constructor" << std::endl;
	int n_index;

	for (int row = 0; row < dim_x_axis; ++row)
	{
		for (int col = 0; col < dim_y_axis; ++col)
		{
			n_index = (row + (col * dim_x_axis));
		}
	}
}

Matrix::Matrix(const Matrix &other) :
	dim_a_(other.dim_a_),
	dim_b_(other.dim_b_),
	data_(new int[other.dim_a_ * other.dim_b_])
{
	std::cout << "Inside Matrix Copy constructor" << std::endl;
	int range = other.dim_a_ * other.dim_b_;
	for (int index = 0; index < range; ++index)
		data_[index] = other.data_[index];
}

Matrix::~Matrix()
{
	std::cout << "Inside Destructor" << std::endl;
	if(data_)
		delete []data_;
}

Matrix MatrixFactory(int a, int b)
{
	return (*new Matrix(a, b));
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

