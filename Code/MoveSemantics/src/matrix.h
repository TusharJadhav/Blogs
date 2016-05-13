#ifndef _MATRIX_H_
#define _MATRIX_H_

class Matrix
{
	private:
		int *data_;
		int dim_a_;
		int dim_b_;

	public:
		Matrix(int dim_a, int dim_b);
		Matrix(const Matrix &other);
		~Matrix();
};

#endif //_MATRIX_H_
