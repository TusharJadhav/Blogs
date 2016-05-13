#ifndef _MATRIX_UPDATED_H_
#define _MATRIX_UPDATED_H_

class Matrix
{
	private:
		int* data_;
		int dim_a_;
		int dim_b_;

	public:
		Matrix(int dimA, int dimB);
		Matrix(const Matrix &other);
		Matrix(Matrix &&other);
		~Matrix();
};

#endif //_MATRIX_UPDATED_H_